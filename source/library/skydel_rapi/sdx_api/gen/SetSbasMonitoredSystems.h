#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the systems monitored by SBAS.
///
/// Name    Type         Description
/// ------- ------------ ------------------------------------------------------------------------------------
/// Systems array string A list containing the name of monitored systems, only "GPS" and "SBAS" are supported
///

class SetSbasMonitoredSystems;
typedef std::shared_ptr<SetSbasMonitoredSystems> SetSbasMonitoredSystemsPtr;

class SetSbasMonitoredSystems : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSbasMonitoredSystems";
  inline static const char* const Documentation =
    "Set the systems monitored by SBAS.\n"
    "\n"
    "Name    Type         Description\n"
    "------- ------------ ------------------------------------------------------------------------------------\n"
    "Systems array string A list containing the name of monitored systems, only \"GPS\" and \"SBAS\" are supported";
  inline static const char* const TargetId = "";

  SetSbasMonitoredSystems() : CommandBase(CmdName, TargetId) {}

  SetSbasMonitoredSystems(const std::vector<std::string>& systems) : CommandBase(CmdName, TargetId)
  {

    setSystems(systems);
  }

  static SetSbasMonitoredSystemsPtr create(const std::vector<std::string>& systems)
  {
    return std::make_shared<SetSbasMonitoredSystems>(systems);
  }

  static SetSbasMonitoredSystemsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSbasMonitoredSystems>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::string>>::is_valid(m_values["Systems"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Systems"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::vector<std::string> systems() const { return parse_json<std::vector<std::string>>::parse(m_values["Systems"]); }

  void setSystems(const std::vector<std::string>& systems)
  {
    m_values.AddMember("Systems",
                       parse_json<std::vector<std::string>>::format(systems, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSbasMonitoredSystems);
} // namespace Cmd
} // namespace Sdx
