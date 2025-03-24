#pragma once

#include <memory>
#include <optional>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsLogDownlinkEnabled.
///
/// Name           Type          Description
/// -------------- -------------
/// ----------------------------------------------------------------------------------------------------------------------
/// Enabled        bool          If true, files will be created during simulation. By default, the downlink files will
/// be created after signal encoding BeforeEncoding optional bool (Optional) If true, files will be created before
/// signal encoding. Can be used with AfterEncoding AfterEncoding  optional bool (Optional) If true, files will be
/// created after signal encoding. Can be used with BeforeEncoding
///

class IsLogDownlinkEnabledResult;
typedef std::shared_ptr<IsLogDownlinkEnabledResult> IsLogDownlinkEnabledResultPtr;

class IsLogDownlinkEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsLogDownlinkEnabledResult";
  inline static const char* const Documentation =
    "Result of IsLogDownlinkEnabled.\n"
    "\n"
    "Name           Type          Description\n"
    "-------------- ------------- ----------------------------------------------------------------------------------------------------------------------\n"
    "Enabled        bool          If true, files will be created during simulation. By default, the downlink files will be created after signal encoding\n"
    "BeforeEncoding optional bool (Optional) If true, files will be created before signal encoding. Can be used with AfterEncoding\n"
    "AfterEncoding  optional bool (Optional) If true, files will be created after signal encoding. Can be used with BeforeEncoding";
  inline static const char* const TargetId = "";

  IsLogDownlinkEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsLogDownlinkEnabledResult(bool enabled,
                             const std::optional<bool>& beforeEncoding = {},
                             const std::optional<bool>& afterEncoding = {}) :
    CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
    setBeforeEncoding(beforeEncoding);
    setAfterEncoding(afterEncoding);
  }

  IsLogDownlinkEnabledResult(CommandBasePtr relatedCommand,
                             bool enabled,
                             const std::optional<bool>& beforeEncoding = {},
                             const std::optional<bool>& afterEncoding = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
    setBeforeEncoding(beforeEncoding);
    setAfterEncoding(afterEncoding);
  }

  static IsLogDownlinkEnabledResultPtr create(bool enabled,
                                              const std::optional<bool>& beforeEncoding = {},
                                              const std::optional<bool>& afterEncoding = {})
  {
    return std::make_shared<IsLogDownlinkEnabledResult>(enabled, beforeEncoding, afterEncoding);
  }

  static IsLogDownlinkEnabledResultPtr create(CommandBasePtr relatedCommand,
                                              bool enabled,
                                              const std::optional<bool>& beforeEncoding = {},
                                              const std::optional<bool>& afterEncoding = {})
  {
    return std::make_shared<IsLogDownlinkEnabledResult>(relatedCommand, enabled, beforeEncoding, afterEncoding);
  }

  static IsLogDownlinkEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLogDownlinkEnabledResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<std::optional<bool>>::is_valid(m_values["BeforeEncoding"]) &&
           parse_json<std::optional<bool>>::is_valid(m_values["AfterEncoding"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled", "BeforeEncoding", "AfterEncoding"};
    return names;
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<bool> beforeEncoding() const
  {
    return parse_json<std::optional<bool>>::parse(m_values["BeforeEncoding"]);
  }

  void setBeforeEncoding(const std::optional<bool>& beforeEncoding)
  {
    m_values.AddMember("BeforeEncoding",
                       parse_json<std::optional<bool>>::format(beforeEncoding, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<bool> afterEncoding() const
  {
    return parse_json<std::optional<bool>>::parse(m_values["AfterEncoding"]);
  }

  void setAfterEncoding(const std::optional<bool>& afterEncoding)
  {
    m_values.AddMember("AfterEncoding",
                       parse_json<std::optional<bool>>::format(afterEncoding, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsLogDownlinkEnabledResult);
} // namespace Cmd
} // namespace Sdx
