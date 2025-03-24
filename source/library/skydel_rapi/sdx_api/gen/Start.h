#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Start the simulation. Simulation may or may not start depending on the current state of the simulator.
///
///
///

class Start;
typedef std::shared_ptr<Start> StartPtr;

class Start : public CommandBase
{
public:
  inline static const char* const CmdName = "Start";
  inline static const char* const Documentation =
    "Start the simulation. Simulation may or may not start depending on the current state of the simulator.";
  inline static const char* const TargetId = "";

  Start() : CommandBase(CmdName, TargetId) {}

  static StartPtr create() { return std::make_shared<Start>(); }

  static StartPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<Start>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(Start);
} // namespace Cmd
} // namespace Sdx
