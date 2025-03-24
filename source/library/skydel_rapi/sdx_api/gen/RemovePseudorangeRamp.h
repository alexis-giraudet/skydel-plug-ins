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
/// Removes a PSR ramp events. When adding an event, the simulator
/// sets the Id parameter. Use that Id here to remove the associated ramp.
///
/// Name   Type   Description
/// ------ ------ --------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Id     string Unique identifier of the PSR ramp to remove.
///

class RemovePseudorangeRamp;
typedef std::shared_ptr<RemovePseudorangeRamp> RemovePseudorangeRampPtr;

class RemovePseudorangeRamp : public CommandBase
{
public:
  inline static const char* const CmdName = "RemovePseudorangeRamp";
  inline static const char* const Documentation =
    "Removes a PSR ramp events. When adding an event, the simulator\n"
    "sets the Id parameter. Use that Id here to remove the associated ramp.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ --------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Id     string Unique identifier of the PSR ramp to remove.";
  inline static const char* const TargetId = "";

  RemovePseudorangeRamp() : CommandBase(CmdName, TargetId) {}

  RemovePseudorangeRamp(const std::string& system, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setId(id);
  }

  static RemovePseudorangeRampPtr create(const std::string& system, const std::string& id)
  {
    return std::make_shared<RemovePseudorangeRamp>(system, id);
  }

  static RemovePseudorangeRampPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemovePseudorangeRamp>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RemovePseudorangeRamp);
} // namespace Cmd
} // namespace Sdx
