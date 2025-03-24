#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Stop the simulation.
///
///
///

class Stop;
typedef std::shared_ptr<Stop> StopPtr;

class Stop : public CommandBase
{
public:
  inline static const char* const CmdName = "Stop";
  inline static const char* const Documentation = "Stop the simulation.";
  inline static const char* const TargetId = "";

  Stop() : CommandBase(CmdName, TargetId) {}

  static StopPtr create() { return std::make_shared<Stop>(); }

  static StopPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<Stop>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(Stop);
} // namespace Cmd
} // namespace Sdx
