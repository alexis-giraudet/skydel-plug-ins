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
///
///

class IsStopMainInstanceWhenWorkerInstanceStop;
typedef std::shared_ptr<IsStopMainInstanceWhenWorkerInstanceStop> IsStopMainInstanceWhenWorkerInstanceStopPtr;

class IsStopMainInstanceWhenWorkerInstanceStop : public CommandBase
{
public:
  inline static const char* const CmdName = "IsStopMainInstanceWhenWorkerInstanceStop";
  inline static const char* const Documentation =
    "If enabled, main instance and all the worker instances will stop if a worker instance stops.";
  inline static const char* const TargetId = "";

  IsStopMainInstanceWhenWorkerInstanceStop() : CommandBase(CmdName, TargetId) {}

  static IsStopMainInstanceWhenWorkerInstanceStopPtr create()
  {
    return std::make_shared<IsStopMainInstanceWhenWorkerInstanceStop>();
  }

  static IsStopMainInstanceWhenWorkerInstanceStopPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsStopMainInstanceWhenWorkerInstanceStop>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(IsStopMainInstanceWhenWorkerInstanceStop);
} // namespace Cmd
} // namespace Sdx
