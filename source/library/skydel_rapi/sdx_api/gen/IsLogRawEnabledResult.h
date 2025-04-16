#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsLogRawEnabled.
///
/// Name    Type Description
/// ------- ---- -----------------------------------------------
/// Enabled bool If true, file will be created during simulation
///

class IsLogRawEnabledResult;
typedef std::shared_ptr<IsLogRawEnabledResult> IsLogRawEnabledResultPtr;

class IsLogRawEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsLogRawEnabledResult";
  inline static const char* const Documentation = "Result of IsLogRawEnabled.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- -----------------------------------------------\n"
                                                  "Enabled bool If true, file will be created during simulation";
  inline static const char* const TargetId = "";

  IsLogRawEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsLogRawEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsLogRawEnabledResult(CommandBasePtr relatedCommand, bool enabled) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsLogRawEnabledResultPtr create(bool enabled) { return std::make_shared<IsLogRawEnabledResult>(enabled); }

  static IsLogRawEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsLogRawEnabledResult>(relatedCommand, enabled);
  }

  static IsLogRawEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLogRawEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsLogRawEnabledResult);
} // namespace Cmd
} // namespace Sdx
