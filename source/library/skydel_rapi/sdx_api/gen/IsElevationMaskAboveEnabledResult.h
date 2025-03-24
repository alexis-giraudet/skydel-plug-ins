#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsElevationMaskAboveEnabled.
///
/// Name    Type Description
/// ------- ---- ------------------------------------------------------------------
/// Enabled bool If true, mask satellites with elevation angle above masking angle.
///

class IsElevationMaskAboveEnabledResult;
typedef std::shared_ptr<IsElevationMaskAboveEnabledResult> IsElevationMaskAboveEnabledResultPtr;

class IsElevationMaskAboveEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsElevationMaskAboveEnabledResult";
  inline static const char* const Documentation =
    "Result of IsElevationMaskAboveEnabled.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ------------------------------------------------------------------\n"
    "Enabled bool If true, mask satellites with elevation angle above masking angle.";
  inline static const char* const TargetId = "";

  IsElevationMaskAboveEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsElevationMaskAboveEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsElevationMaskAboveEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsElevationMaskAboveEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsElevationMaskAboveEnabledResult>(enabled);
  }

  static IsElevationMaskAboveEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsElevationMaskAboveEnabledResult>(relatedCommand, enabled);
  }

  static IsElevationMaskAboveEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsElevationMaskAboveEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsElevationMaskAboveEnabledResult);
} // namespace Cmd
} // namespace Sdx
