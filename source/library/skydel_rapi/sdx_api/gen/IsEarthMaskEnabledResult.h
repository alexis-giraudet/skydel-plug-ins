#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsEarthMaskEnabled.
///
/// Name    Type Description
/// ------- ---- ----------------------------------------------------------------------------------------------
/// Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.
///

class IsEarthMaskEnabledResult;
typedef std::shared_ptr<IsEarthMaskEnabledResult> IsEarthMaskEnabledResultPtr;

class IsEarthMaskEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsEarthMaskEnabledResult";
  inline static const char* const Documentation =
    "Result of IsEarthMaskEnabled.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ----------------------------------------------------------------------------------------------\n"
    "Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.";
  inline static const char* const TargetId = "";

  IsEarthMaskEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsEarthMaskEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsEarthMaskEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsEarthMaskEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsEarthMaskEnabledResult>(enabled);
  }

  static IsEarthMaskEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsEarthMaskEnabledResult>(relatedCommand, enabled);
  }

  static IsEarthMaskEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsEarthMaskEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsEarthMaskEnabledResult);
} // namespace Cmd
} // namespace Sdx
