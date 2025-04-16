#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsSimStopWhenCommandFailEnabled.
///
/// Name    Type Description
/// ------- ---- ----------------------------------
/// Enabled bool Enable stop when command fail flag
///

class IsSimStopWhenCommandFailEnabledResult;
typedef std::shared_ptr<IsSimStopWhenCommandFailEnabledResult> IsSimStopWhenCommandFailEnabledResultPtr;

class IsSimStopWhenCommandFailEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsSimStopWhenCommandFailEnabledResult";
  inline static const char* const Documentation = "Result of IsSimStopWhenCommandFailEnabled.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- ----------------------------------\n"
                                                  "Enabled bool Enable stop when command fail flag";
  inline static const char* const TargetId = "";

  IsSimStopWhenCommandFailEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsSimStopWhenCommandFailEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsSimStopWhenCommandFailEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsSimStopWhenCommandFailEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsSimStopWhenCommandFailEnabledResult>(enabled);
  }

  static IsSimStopWhenCommandFailEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsSimStopWhenCommandFailEnabledResult>(relatedCommand, enabled);
  }

  static IsSimStopWhenCommandFailEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSimStopWhenCommandFailEnabledResult>(ptr);
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

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsSimStopWhenCommandFailEnabledResult);
} // namespace Cmd
} // namespace Sdx
