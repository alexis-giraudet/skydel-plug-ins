#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/SimulatorState.h"
#include "gen/SimulatorSubState.h"

namespace Sdx
{
namespace Cmd
{
///
/// Simulator State Result.
/// Possible substates are :
/// -None
/// -Incomplete
/// -Ready
/// -Initializing
/// -Armed
/// -Streaming RF
/// -Sync Worker
/// -WF Init (Worker)
/// -WF Init (Main)
/// -HIL Sync
/// -Sync Init
/// -Sync PPS Reset
/// -Sync Start Time
/// -Sync Start
/// -Error
///
/// Name       Type              Description
/// ---------- ----------------- ------------------------------------
/// State      string            Simulator substate.
/// Error      string            Error Message if state is Error.
/// StateId    SimulatorState    Simulator State value as an enum.
/// SubStateId SimulatorSubState Simulator SubState value as an enum.
///

class SimulatorStateResult;
typedef std::shared_ptr<SimulatorStateResult> SimulatorStateResultPtr;

class SimulatorStateResult : public CommandResult
{
public:
  inline static const char* const CmdName = "SimulatorStateResult";
  inline static const char* const Documentation = "Simulator State Result.\n"
                                                  "Possible substates are :\n"
                                                  "-None\n"
                                                  "-Incomplete\n"
                                                  "-Ready\n"
                                                  "-Initializing\n"
                                                  "-Armed\n"
                                                  "-Streaming RF\n"
                                                  "-Sync Worker\n"
                                                  "-WF Init (Worker)\n"
                                                  "-WF Init (Main)\n"
                                                  "-HIL Sync\n"
                                                  "-Sync Init\n"
                                                  "-Sync PPS Reset\n"
                                                  "-Sync Start Time\n"
                                                  "-Sync Start\n"
                                                  "-Error\n"
                                                  "\n"
                                                  "Name       Type              Description\n"
                                                  "---------- ----------------- ------------------------------------\n"
                                                  "State      string            Simulator substate.\n"
                                                  "Error      string            Error Message if state is Error.\n"
                                                  "StateId    SimulatorState    Simulator State value as an enum.\n"
                                                  "SubStateId SimulatorSubState Simulator SubState value as an enum.";
  inline static const char* const TargetId = "";

  SimulatorStateResult() : CommandResult(CmdName, TargetId) {}

  SimulatorStateResult(const std::string& state,
                       const std::string& error,
                       const Sdx::SimulatorState& stateId,
                       const Sdx::SimulatorSubState& subStateId) :
    CommandResult(CmdName, TargetId)
  {

    setState(state);
    setError(error);
    setStateId(stateId);
    setSubStateId(subStateId);
  }

  SimulatorStateResult(CommandBasePtr relatedCommand,
                       const std::string& state,
                       const std::string& error,
                       const Sdx::SimulatorState& stateId,
                       const Sdx::SimulatorSubState& subStateId) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setState(state);
    setError(error);
    setStateId(stateId);
    setSubStateId(subStateId);
  }

  static SimulatorStateResultPtr create(const std::string& state,
                                        const std::string& error,
                                        const Sdx::SimulatorState& stateId,
                                        const Sdx::SimulatorSubState& subStateId)
  {
    return std::make_shared<SimulatorStateResult>(state, error, stateId, subStateId);
  }

  static SimulatorStateResultPtr create(CommandBasePtr relatedCommand,
                                        const std::string& state,
                                        const std::string& error,
                                        const Sdx::SimulatorState& stateId,
                                        const Sdx::SimulatorSubState& subStateId)
  {
    return std::make_shared<SimulatorStateResult>(relatedCommand, state, error, stateId, subStateId);
  }

  static SimulatorStateResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SimulatorStateResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["State"]) &&
           parse_json<std::string>::is_valid(m_values["Error"]) &&
           parse_json<Sdx::SimulatorState>::is_valid(m_values["StateId"]) &&
           parse_json<Sdx::SimulatorSubState>::is_valid(m_values["SubStateId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"State", "Error", "StateId", "SubStateId"};
    return names;
  }

  std::string state() const { return parse_json<std::string>::parse(m_values["State"]); }

  void setState(const std::string& state)
  {
    m_values.AddMember("State",
                       parse_json<std::string>::format(state, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string error() const { return parse_json<std::string>::parse(m_values["Error"]); }

  void setError(const std::string& error)
  {
    m_values.AddMember("Error",
                       parse_json<std::string>::format(error, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::SimulatorState stateId() const { return parse_json<Sdx::SimulatorState>::parse(m_values["StateId"]); }

  void setStateId(const Sdx::SimulatorState& stateId)
  {
    m_values.AddMember("StateId",
                       parse_json<Sdx::SimulatorState>::format(stateId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::SimulatorSubState subStateId() const
  {
    return parse_json<Sdx::SimulatorSubState>::parse(m_values["SubStateId"]);
  }

  void setSubStateId(const Sdx::SimulatorSubState& subStateId)
  {
    m_values.AddMember("SubStateId",
                       parse_json<Sdx::SimulatorSubState>::format(subStateId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SimulatorStateResult);
} // namespace Cmd
} // namespace Sdx
