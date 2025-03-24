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
/// Wait until simulator has reached the specified substate unless simulator goes to error state or specified failure
/// substate. Will return a SimulatorStateResult. Possible substates are : -None -Incomplete -Ready -Initializing -Armed
/// -Streaming RF
/// -Sync Worker Instance
/// -WF Init (Worker)
/// -WF Init (Main)
/// -HIL Sync
/// -Sync Init
/// -Sync PPS Reset
/// -Sync Start Time
/// -Sync Start
/// -Error
///
/// Name         Type   Description
/// ------------ ------ ----------------------------------------------------------
/// State        string Simulator sub state string.
/// FailureState string Abort waiting if simulator goes to this sub state instead.
///

class WaitSimulatorState;
typedef std::shared_ptr<WaitSimulatorState> WaitSimulatorStatePtr;

class WaitSimulatorState : public CommandBase
{
public:
  inline static const char* const CmdName = "WaitSimulatorState";
  inline static const char* const Documentation =
    "Wait until simulator has reached the specified substate unless simulator goes to error state or specified failure substate. Will return a SimulatorStateResult.\n"
    "Possible substates are :\n"
    "-None\n"
    "-Incomplete\n"
    "-Ready\n"
    "-Initializing\n"
    "-Armed\n"
    "-Streaming RF\n"
    "-Sync Worker Instance\n"
    "-WF Init (Worker)\n"
    "-WF Init (Main)\n"
    "-HIL Sync\n"
    "-Sync Init\n"
    "-Sync PPS Reset\n"
    "-Sync Start Time\n"
    "-Sync Start\n"
    "-Error\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ ----------------------------------------------------------\n"
    "State        string Simulator sub state string.\n"
    "FailureState string Abort waiting if simulator goes to this sub state instead.";
  inline static const char* const TargetId = "";

  WaitSimulatorState() : CommandBase(CmdName, TargetId) {}

  WaitSimulatorState(const std::string& state, const std::string& failureState) : CommandBase(CmdName, TargetId)
  {

    setState(state);
    setFailureState(failureState);
  }

  static WaitSimulatorStatePtr create(const std::string& state, const std::string& failureState)
  {
    return std::make_shared<WaitSimulatorState>(state, failureState);
  }

  static WaitSimulatorStatePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<WaitSimulatorState>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["State"]) &&
           parse_json<std::string>::is_valid(m_values["FailureState"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"State", "FailureState"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::string state() const { return parse_json<std::string>::parse(m_values["State"]); }

  void setState(const std::string& state)
  {
    m_values.AddMember("State",
                       parse_json<std::string>::format(state, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string failureState() const { return parse_json<std::string>::parse(m_values["FailureState"]); }

  void setFailureState(const std::string& failureState)
  {
    m_values.AddMember("FailureState",
                       parse_json<std::string>::format(failureState, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(WaitSimulatorState);
} // namespace Cmd
} // namespace Sdx
