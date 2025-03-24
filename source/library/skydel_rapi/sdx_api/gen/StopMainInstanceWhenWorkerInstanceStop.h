#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// If enabled, main instance and all the worker instances will stop if a worker instance stops.
///
/// Name    Type Description
/// ------- ---- ---------------------------------------------------------
/// Enabled bool Enable main instance stop when worker instance stops flag
///

class StopMainInstanceWhenWorkerInstanceStop;
typedef std::shared_ptr<StopMainInstanceWhenWorkerInstanceStop> StopMainInstanceWhenWorkerInstanceStopPtr;

class StopMainInstanceWhenWorkerInstanceStop : public CommandBase
{
public:
  inline static const char* const CmdName = "StopMainInstanceWhenWorkerInstanceStop";
  inline static const char* const Documentation =
    "If enabled, main instance and all the worker instances will stop if a worker instance stops.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ---------------------------------------------------------\n"
    "Enabled bool Enable main instance stop when worker instance stops flag";
  inline static const char* const TargetId = "";

  StopMainInstanceWhenWorkerInstanceStop() : CommandBase(CmdName, TargetId) {}

  StopMainInstanceWhenWorkerInstanceStop(bool enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static StopMainInstanceWhenWorkerInstanceStopPtr create(bool enabled)
  {
    return std::make_shared<StopMainInstanceWhenWorkerInstanceStop>(enabled);
  }

  static StopMainInstanceWhenWorkerInstanceStopPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<StopMainInstanceWhenWorkerInstanceStop>(ptr);
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

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(StopMainInstanceWhenWorkerInstanceStop);
} // namespace Cmd
} // namespace Sdx
