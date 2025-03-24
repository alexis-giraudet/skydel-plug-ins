#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with
/// Tracks and Routes
///
/// Name    Type Description
/// ------- ---- ------------------------------------------------------------------------
/// Enabled bool If true, simulation will stop when the vehicle will reach trajectory end
///

class EnableSimulationStopAtTrajectoryEnd;
typedef std::shared_ptr<EnableSimulationStopAtTrajectoryEnd> EnableSimulationStopAtTrajectoryEndPtr;

class EnableSimulationStopAtTrajectoryEnd : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableSimulationStopAtTrajectoryEnd";
  inline static const char* const Documentation =
    "Set simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ------------------------------------------------------------------------\n"
    "Enabled bool If true, simulation will stop when the vehicle will reach trajectory end";
  inline static const char* const TargetId = "";

  EnableSimulationStopAtTrajectoryEnd() : CommandBase(CmdName, TargetId) {}

  EnableSimulationStopAtTrajectoryEnd(bool enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static EnableSimulationStopAtTrajectoryEndPtr create(bool enabled)
  {
    return std::make_shared<EnableSimulationStopAtTrajectoryEnd>(enabled);
  }

  static EnableSimulationStopAtTrajectoryEndPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableSimulationStopAtTrajectoryEnd>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableSimulationStopAtTrajectoryEnd);
} // namespace Cmd
} // namespace Sdx
