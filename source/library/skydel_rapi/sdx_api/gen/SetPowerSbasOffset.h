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
/// Set power offset default value for the SBAS Service Provider given in argument
///
/// Name            Type   Description
/// --------------- ------ ------------------------------------------------------------------------------
/// ServiceProvider string Service Provider key, allowed values: "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM"
/// Offset          double Offset in dB (negative value will attenuate signal)
///

class SetPowerSbasOffset;
typedef std::shared_ptr<SetPowerSbasOffset> SetPowerSbasOffsetPtr;

class SetPowerSbasOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPowerSbasOffset";
  inline static const char* const Documentation =
    "Set power offset default value for the SBAS Service Provider given in argument\n"
    "\n"
    "Name            Type   Description\n"
    "--------------- ------ ------------------------------------------------------------------------------\n"
    "ServiceProvider string Service Provider key, allowed values: \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\"\n"
    "Offset          double Offset in dB (negative value will attenuate signal)";
  inline static const char* const TargetId = "";

  SetPowerSbasOffset() : CommandBase(CmdName, TargetId) {}

  SetPowerSbasOffset(const std::string& serviceProvider, double offset) : CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
    setOffset(offset);
  }

  static SetPowerSbasOffsetPtr create(const std::string& serviceProvider, double offset)
  {
    return std::make_shared<SetPowerSbasOffset>(serviceProvider, offset);
  }

  static SetPowerSbasOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetPowerSbasOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ServiceProvider"]) &&
           parse_json<double>::is_valid(m_values["Offset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ServiceProvider", "Offset"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::string serviceProvider() const { return parse_json<std::string>::parse(m_values["ServiceProvider"]); }

  void setServiceProvider(const std::string& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double offset() const { return parse_json<double>::parse(m_values["Offset"]); }

  void setOffset(double offset)
  {
    m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPowerSbasOffset);
} // namespace Cmd
} // namespace Sdx
