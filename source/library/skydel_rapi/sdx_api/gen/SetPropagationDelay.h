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
/// Enable (or disable) the satellite signal propagation delay. If disabled, the signal is immediately received
/// by the receiver. The delay should always be enabled, unless your are doing a PPS calibration for the simulator.
///
/// Name    Type   Description
/// ------- ------ -------------------------------------------------------------------------------------------------
/// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.
///

class SetPropagationDelay;
typedef std::shared_ptr<SetPropagationDelay> SetPropagationDelayPtr;

class SetPropagationDelay : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPropagationDelay";
  inline static const char* const Documentation =
    "Enable (or disable) the satellite signal propagation delay. If disabled, the signal is immediately received\n"
    "by the receiver. The delay should always be enabled, unless your are doing a PPS calibration for the simulator.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ -------------------------------------------------------------------------------------------------\n"
    "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.";
  inline static const char* const TargetId = "";

  SetPropagationDelay() : CommandBase(CmdName, TargetId) {}

  SetPropagationDelay(const std::string& system, bool enabled) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setEnabled(enabled);
  }

  static SetPropagationDelayPtr create(const std::string& system, bool enabled)
  {
    return std::make_shared<SetPropagationDelay>(system, enabled);
  }

  static SetPropagationDelayPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetPropagationDelay>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Enabled"};
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

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPropagationDelay);
} // namespace Cmd
} // namespace Sdx
