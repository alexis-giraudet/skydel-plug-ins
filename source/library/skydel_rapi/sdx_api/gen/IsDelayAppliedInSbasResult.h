#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsDelayAppliedInSbas.
///
/// Name      Type Description
/// --------- ---- --------------------------------------------
/// IsEnabled bool True if offsets are applied in Sbas messages
///

class IsDelayAppliedInSbasResult;
typedef std::shared_ptr<IsDelayAppliedInSbasResult> IsDelayAppliedInSbasResultPtr;

class IsDelayAppliedInSbasResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsDelayAppliedInSbasResult";
  inline static const char* const Documentation = "Result of IsDelayAppliedInSbas.\n"
                                                  "\n"
                                                  "Name      Type Description\n"
                                                  "--------- ---- --------------------------------------------\n"
                                                  "IsEnabled bool True if offsets are applied in Sbas messages";
  inline static const char* const TargetId = "";

  IsDelayAppliedInSbasResult() : CommandResult(CmdName, TargetId) {}

  IsDelayAppliedInSbasResult(bool isEnabled) : CommandResult(CmdName, TargetId) { setIsEnabled(isEnabled); }

  IsDelayAppliedInSbasResult(CommandBasePtr relatedCommand, bool isEnabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIsEnabled(isEnabled);
  }

  static IsDelayAppliedInSbasResultPtr create(bool isEnabled)
  {
    return std::make_shared<IsDelayAppliedInSbasResult>(isEnabled);
  }

  static IsDelayAppliedInSbasResultPtr create(CommandBasePtr relatedCommand, bool isEnabled)
  {
    return std::make_shared<IsDelayAppliedInSbasResult>(relatedCommand, isEnabled);
  }

  static IsDelayAppliedInSbasResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsDelayAppliedInSbasResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["IsEnabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IsEnabled"};
    return names;
  }

  bool isEnabled() const { return parse_json<bool>::parse(m_values["IsEnabled"]); }

  void setIsEnabled(bool isEnabled)
  {
    m_values.AddMember("IsEnabled",
                       parse_json<bool>::format(isEnabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsDelayAppliedInSbasResult);
} // namespace Cmd
} // namespace Sdx
