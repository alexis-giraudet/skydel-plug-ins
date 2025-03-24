#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command GetMasterStatus is deprecated since 23.11. You may use GetMainInstanceStatus.
///
/// Request for the master status, returns a GetMasterStatusResult
///
///
///

class GetMasterStatus;
typedef std::shared_ptr<GetMasterStatus> GetMasterStatusPtr;

class GetMasterStatus : public CommandBase
{
public:
  inline static const char* const CmdName = "GetMasterStatus";
  inline static const char* const Documentation =
    "Please note the command GetMasterStatus is deprecated since 23.11. You may use GetMainInstanceStatus.\n"
    "\n"
    "Request for the master status, returns a GetMasterStatusResult";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command GetMasterStatus is deprecated since 23.11. You may use GetMainInstanceStatus.";

  GetMasterStatus() : CommandBase(CmdName, TargetId) {}

  static GetMasterStatusPtr create() { return std::make_shared<GetMasterStatus>(); }

  static GetMasterStatusPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetMasterStatus>(ptr); }

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
REGISTER_COMMAND_TO_FACTORY(GetMasterStatus);
} // namespace Cmd
} // namespace Sdx
