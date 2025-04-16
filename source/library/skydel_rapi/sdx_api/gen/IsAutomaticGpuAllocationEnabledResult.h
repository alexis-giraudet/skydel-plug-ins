#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsAutomaticGpuAllocationEnabled.
///
/// Name    Type Description
/// ------- ----
/// --------------------------------------------------------------------------------------------------------- Enabled
/// bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.
///

class IsAutomaticGpuAllocationEnabledResult;
typedef std::shared_ptr<IsAutomaticGpuAllocationEnabledResult> IsAutomaticGpuAllocationEnabledResultPtr;

class IsAutomaticGpuAllocationEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsAutomaticGpuAllocationEnabledResult";
  inline static const char* const Documentation =
    "Result of IsAutomaticGpuAllocationEnabled.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ---------------------------------------------------------------------------------------------------------\n"
    "Enabled bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.";
  inline static const char* const TargetId = "";

  IsAutomaticGpuAllocationEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsAutomaticGpuAllocationEnabledResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsAutomaticGpuAllocationEnabledResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsAutomaticGpuAllocationEnabledResultPtr create(bool enabled)
  {
    return std::make_shared<IsAutomaticGpuAllocationEnabledResult>(enabled);
  }

  static IsAutomaticGpuAllocationEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsAutomaticGpuAllocationEnabledResult>(relatedCommand, enabled);
  }

  static IsAutomaticGpuAllocationEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsAutomaticGpuAllocationEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsAutomaticGpuAllocationEnabledResult);
} // namespace Cmd
} // namespace Sdx
