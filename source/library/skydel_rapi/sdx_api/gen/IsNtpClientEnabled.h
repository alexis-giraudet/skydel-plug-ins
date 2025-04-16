#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Indicates if the NTP client is enabled.
///
///
///

class IsNtpClientEnabled;
typedef std::shared_ptr<IsNtpClientEnabled> IsNtpClientEnabledPtr;

class IsNtpClientEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsNtpClientEnabled";
  inline static const char* const Documentation = "Indicates if the NTP client is enabled.";
  inline static const char* const TargetId = "";

  IsNtpClientEnabled() : CommandBase(CmdName, TargetId) {}

  static IsNtpClientEnabledPtr create() { return std::make_shared<IsNtpClientEnabled>(); }

  static IsNtpClientEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsNtpClientEnabled>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(IsNtpClientEnabled);
} // namespace Cmd
} // namespace Sdx
