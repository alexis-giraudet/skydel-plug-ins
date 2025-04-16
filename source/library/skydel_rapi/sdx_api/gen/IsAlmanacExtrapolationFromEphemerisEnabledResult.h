#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsAlmanacExtrapolationFromEphemerisEnabled.
///
/// Name    Type Description
/// ------- ---- -------------------------------
/// Enabled bool State of almanac extrapolation.
///

class IsAlmanacExtrapolationFromEphemerisEnabledResult;
typedef std::shared_ptr<IsAlmanacExtrapolationFromEphemerisEnabledResult>
  IsAlmanacExtrapolationFromEphemerisEnabledResultPtr;

class IsAlmanacExtrapolationFromEphemerisEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsAlmanacExtrapolationFromEphemerisEnabledResult";
  inline static const char* const Documentation = "Result of IsAlmanacExtrapolationFromEphemerisEnabled.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- -------------------------------\n"
                                                  "Enabled bool State of almanac extrapolation.";
  inline static const char* const TargetId = "";

  IsAlmanacExtrapolationFromEphemerisEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsAlmanacExtrapolationFromEphemerisEnabledResult(bool enabled) : CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
  }

  IsAlmanacExtrapolationFromEphemerisEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsAlmanacExtrapolationFromEphemerisEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsAlmanacExtrapolationFromEphemerisEnabledResult>(enabled);
  }

  static IsAlmanacExtrapolationFromEphemerisEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsAlmanacExtrapolationFromEphemerisEnabledResult>(relatedCommand, enabled);
  }

  static IsAlmanacExtrapolationFromEphemerisEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsAlmanacExtrapolationFromEphemerisEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsAlmanacExtrapolationFromEphemerisEnabledResult);
} // namespace Cmd
} // namespace Sdx
