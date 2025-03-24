#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get power offset default value for the SBAS Service Provider given in argument
///
/// Name            Type   Description
/// --------------- ------ ------------------------------------------------------------------------------
/// ServiceProvider string Service Provider key, allowed values: "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM"
///

class GetPowerSbasOffset;
typedef std::shared_ptr<GetPowerSbasOffset> GetPowerSbasOffsetPtr;

class GetPowerSbasOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPowerSbasOffset";
  inline static const char* const Documentation =
    "Get power offset default value for the SBAS Service Provider given in argument\n"
    "\n"
    "Name            Type   Description\n"
    "--------------- ------ ------------------------------------------------------------------------------\n"
    "ServiceProvider string Service Provider key, allowed values: \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\"";
  inline static const char* const TargetId = "";

  GetPowerSbasOffset() : CommandBase(CmdName, TargetId) {}

  GetPowerSbasOffset(const std::string& serviceProvider) : CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
  }

  static GetPowerSbasOffsetPtr create(const std::string& serviceProvider)
  {
    return std::make_shared<GetPowerSbasOffset>(serviceProvider);
  }

  static GetPowerSbasOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPowerSbasOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ServiceProvider"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ServiceProvider"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string serviceProvider() const { return parse_json<std::string>::parse(m_values["ServiceProvider"]); }

  void setServiceProvider(const std::string& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetPowerSbasOffset);
} // namespace Cmd
} // namespace Sdx
