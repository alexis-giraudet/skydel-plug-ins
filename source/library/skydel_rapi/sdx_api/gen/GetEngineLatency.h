#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get engine latency.
///
///
///

class GetEngineLatency;
typedef std::shared_ptr<GetEngineLatency> GetEngineLatencyPtr;

class GetEngineLatency : public CommandBase
{
public:
  inline static const char* const CmdName = "GetEngineLatency";
  inline static const char* const Documentation = "Get engine latency.";
  inline static const char* const TargetId = "";

  GetEngineLatency() : CommandBase(CmdName, TargetId) {}

  static GetEngineLatencyPtr create() { return std::make_shared<GetEngineLatency>(); }

  static GetEngineLatencyPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEngineLatency>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetEngineLatency);
} // namespace Cmd
} // namespace Sdx
