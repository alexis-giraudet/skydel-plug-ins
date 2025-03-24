#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Ask current simulator state. Will return a SimulatorStateResult.
///
///
///

class GetSimulatorState;
typedef std::shared_ptr<GetSimulatorState> GetSimulatorStatePtr;

class GetSimulatorState : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSimulatorState";
  inline static const char* const Documentation = "Ask current simulator state. Will return a SimulatorStateResult.";
  inline static const char* const TargetId = "";

  GetSimulatorState() : CommandBase(CmdName, TargetId) {}

  static GetSimulatorStatePtr create() { return std::make_shared<GetSimulatorState>(); }

  static GetSimulatorStatePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSimulatorState>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetSimulatorState);
} // namespace Cmd
} // namespace Sdx
