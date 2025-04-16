#pragma once

#include <memory>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsOsnmaEnabledForEachSV.
///
/// Name    Type       Description
/// ------- ----------
/// -------------------------------------------------------------------------------------------------------------
/// Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second
/// SV ID, etc).
///

class IsOsnmaEnabledForEachSVResult;
typedef std::shared_ptr<IsOsnmaEnabledForEachSVResult> IsOsnmaEnabledForEachSVResultPtr;

class IsOsnmaEnabledForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsOsnmaEnabledForEachSVResult";
  inline static const char* const Documentation =
    "Result of IsOsnmaEnabledForEachSV.\n"
    "\n"
    "Name    Type       Description\n"
    "------- ---------- -------------------------------------------------------------------------------------------------------------\n"
    "Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
  inline static const char* const TargetId = "";

  IsOsnmaEnabledForEachSVResult() : CommandResult(CmdName, TargetId) {}

  IsOsnmaEnabledForEachSVResult(const std::vector<bool>& enabled) : CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
  }

  IsOsnmaEnabledForEachSVResult(CommandBasePtr relatedCommand, const std::vector<bool>& enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsOsnmaEnabledForEachSVResultPtr create(const std::vector<bool>& enabled)
  {
    return std::make_shared<IsOsnmaEnabledForEachSVResult>(enabled);
  }

  static IsOsnmaEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<bool>& enabled)
  {
    return std::make_shared<IsOsnmaEnabledForEachSVResult>(relatedCommand, enabled);
  }

  static IsOsnmaEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsOsnmaEnabledForEachSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled"};
    return names;
  }

  std::vector<bool> enabled() const { return parse_json<std::vector<bool>>::parse(m_values["Enabled"]); }

  void setEnabled(const std::vector<bool>& enabled)
  {
    m_values.AddMember("Enabled",
                       parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsOsnmaEnabledForEachSVResult);
} // namespace Cmd
} // namespace Sdx
