#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsLogHILInputEnabled.
///
/// Name    Type Description
/// ------- ---- ------------------------------------------------
/// Enabled bool If true, files will be created during simulation
///

class IsLogHILInputEnabledResult;
typedef std::shared_ptr<IsLogHILInputEnabledResult> IsLogHILInputEnabledResultPtr;

class IsLogHILInputEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsLogHILInputEnabledResult";
  inline static const char* const Documentation = "Result of IsLogHILInputEnabled.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- ------------------------------------------------\n"
                                                  "Enabled bool If true, files will be created during simulation";
  inline static const char* const TargetId = "";

  IsLogHILInputEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsLogHILInputEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsLogHILInputEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsLogHILInputEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsLogHILInputEnabledResult>(enabled);
  }

  static IsLogHILInputEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsLogHILInputEnabledResult>(relatedCommand, enabled);
  }

  static IsLogHILInputEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLogHILInputEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsLogHILInputEnabledResult);
} // namespace Cmd
} // namespace Sdx
