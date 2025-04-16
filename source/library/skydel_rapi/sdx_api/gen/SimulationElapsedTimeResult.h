#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSimulationElapsedTime.
///
/// Name         Type Description
/// ------------ ---- -----------------------------------------------------------------------------
/// Milliseconds int  Simulation elapsed time in milliseconds. Note: Resolution is limited to 10Hz.
///

class SimulationElapsedTimeResult;
typedef std::shared_ptr<SimulationElapsedTimeResult> SimulationElapsedTimeResultPtr;

class SimulationElapsedTimeResult : public CommandResult
{
public:
  inline static const char* const CmdName = "SimulationElapsedTimeResult";
  inline static const char* const Documentation =
    "Result of GetSimulationElapsedTime.\n"
    "\n"
    "Name         Type Description\n"
    "------------ ---- -----------------------------------------------------------------------------\n"
    "Milliseconds int  Simulation elapsed time in milliseconds. Note: Resolution is limited to 10Hz.";
  inline static const char* const TargetId = "";

  SimulationElapsedTimeResult() : CommandResult(CmdName, TargetId) {}

  SimulationElapsedTimeResult(int milliseconds) : CommandResult(CmdName, TargetId) { setMilliseconds(milliseconds); }

  SimulationElapsedTimeResult(CommandBasePtr relatedCommand, int milliseconds) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setMilliseconds(milliseconds);
  }

  static SimulationElapsedTimeResultPtr create(int milliseconds)
  {
    return std::make_shared<SimulationElapsedTimeResult>(milliseconds);
  }

  static SimulationElapsedTimeResultPtr create(CommandBasePtr relatedCommand, int milliseconds)
  {
    return std::make_shared<SimulationElapsedTimeResult>(relatedCommand, milliseconds);
  }

  static SimulationElapsedTimeResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SimulationElapsedTimeResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Milliseconds"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Milliseconds"};
    return names;
  }

  int milliseconds() const { return parse_json<int>::parse(m_values["Milliseconds"]); }

  void setMilliseconds(int milliseconds)
  {
    m_values.AddMember("Milliseconds",
                       parse_json<int>::format(milliseconds, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SimulationElapsedTimeResult);
} // namespace Cmd
} // namespace Sdx
