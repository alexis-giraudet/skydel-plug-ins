#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsTrajectorySmoothingEnabled.
///
/// Name    Type Description
/// ------- ---- ------------------------------------------------------
/// Enabled bool If true, trajectory will be smoothed during simulation
///

class IsTrajectorySmoothingEnabledResult;
typedef std::shared_ptr<IsTrajectorySmoothingEnabledResult> IsTrajectorySmoothingEnabledResultPtr;

class IsTrajectorySmoothingEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsTrajectorySmoothingEnabledResult";
  inline static const char* const Documentation =
    "Result of IsTrajectorySmoothingEnabled.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ------------------------------------------------------\n"
    "Enabled bool If true, trajectory will be smoothed during simulation";
  inline static const char* const TargetId = "";

  IsTrajectorySmoothingEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsTrajectorySmoothingEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsTrajectorySmoothingEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsTrajectorySmoothingEnabledResult>(enabled);
  }

  static IsTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsTrajectorySmoothingEnabledResult>(relatedCommand, enabled);
  }

  static IsTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsTrajectorySmoothingEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsTrajectorySmoothingEnabledResult);
} // namespace Cmd
} // namespace Sdx
