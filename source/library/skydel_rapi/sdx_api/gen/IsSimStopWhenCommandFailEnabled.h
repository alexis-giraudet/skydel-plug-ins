#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// If enabled, simulation stops when a command result fail.
///
///
///

class IsSimStopWhenCommandFailEnabled;
typedef std::shared_ptr<IsSimStopWhenCommandFailEnabled> IsSimStopWhenCommandFailEnabledPtr;

class IsSimStopWhenCommandFailEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsSimStopWhenCommandFailEnabled";
  inline static const char* const Documentation = "If enabled, simulation stops when a command result fail.";
  inline static const char* const TargetId = "";

  IsSimStopWhenCommandFailEnabled() : CommandBase(CmdName, TargetId) {}

  static IsSimStopWhenCommandFailEnabledPtr create() { return std::make_shared<IsSimStopWhenCommandFailEnabled>(); }

  static IsSimStopWhenCommandFailEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSimStopWhenCommandFailEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsSimStopWhenCommandFailEnabled);
} // namespace Cmd
} // namespace Sdx
