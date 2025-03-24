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
/// Get SBAS delta UDREI outside all the defined regions for this service provider.
///
/// Name            Type   Description
/// --------------- ------ -----------------------------------------------------------------------
/// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
///

class GetSbasDeltaUdreiOutsideOfRegions;
typedef std::shared_ptr<GetSbasDeltaUdreiOutsideOfRegions> GetSbasDeltaUdreiOutsideOfRegionsPtr;

class GetSbasDeltaUdreiOutsideOfRegions : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSbasDeltaUdreiOutsideOfRegions";
  inline static const char* const Documentation =
    "Get SBAS delta UDREI outside all the defined regions for this service provider.\n"
    "\n"
    "Name            Type   Description\n"
    "--------------- ------ -----------------------------------------------------------------------\n"
    "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".";
  inline static const char* const TargetId = "";

  GetSbasDeltaUdreiOutsideOfRegions() : CommandBase(CmdName, TargetId) {}

  GetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider) : CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
  }

  static GetSbasDeltaUdreiOutsideOfRegionsPtr create(const std::string& serviceProvider)
  {
    return std::make_shared<GetSbasDeltaUdreiOutsideOfRegions>(serviceProvider);
  }

  static GetSbasDeltaUdreiOutsideOfRegionsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasDeltaUdreiOutsideOfRegions>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSbasDeltaUdreiOutsideOfRegions);
} // namespace Cmd
} // namespace Sdx
