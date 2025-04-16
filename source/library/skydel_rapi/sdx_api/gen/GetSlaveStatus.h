#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command GetSlaveStatus is deprecated since 23.11. You may use GetWorkerInstanceStatus.
///
/// Request for the slave status, returns a GetSlaveStatusResult
///
///
///

class GetSlaveStatus;
typedef std::shared_ptr<GetSlaveStatus> GetSlaveStatusPtr;

class GetSlaveStatus : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSlaveStatus";
  inline static const char* const Documentation =
    "Please note the command GetSlaveStatus is deprecated since 23.11. You may use GetWorkerInstanceStatus.\n"
    "\n"
    "Request for the slave status, returns a GetSlaveStatusResult";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command GetSlaveStatus is deprecated since 23.11. You may use GetWorkerInstanceStatus.";

  GetSlaveStatus() : CommandBase(CmdName, TargetId) {}

  static GetSlaveStatusPtr create() { return std::make_shared<GetSlaveStatus>(); }

  static GetSlaveStatusPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetSlaveStatus>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  std::optional<std::string> deprecated() const { return std::optional<std::string> {Deprecated}; }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetSlaveStatus);
} // namespace Cmd
} // namespace Sdx
