#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Enable (or disable) automatic GPU allocation to outputs.
///
/// Name    Type Description
/// ------- ----
/// --------------------------------------------------------------------------------------------------------- Enabled
/// bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.
///

class EnableAutomaticGpuAllocation;
typedef std::shared_ptr<EnableAutomaticGpuAllocation> EnableAutomaticGpuAllocationPtr;

class EnableAutomaticGpuAllocation : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableAutomaticGpuAllocation";
  inline static const char* const Documentation =
    "Enable (or disable) automatic GPU allocation to outputs.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ---------------------------------------------------------------------------------------------------------\n"
    "Enabled bool If enabled, Skydel will automatically assign available GPUs to each added output to optimize performance.";
  inline static const char* const TargetId = "";

  EnableAutomaticGpuAllocation() : CommandBase(CmdName, TargetId) {}

  EnableAutomaticGpuAllocation(bool enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static EnableAutomaticGpuAllocationPtr create(bool enabled)
  {
    return std::make_shared<EnableAutomaticGpuAllocation>(enabled);
  }

  static EnableAutomaticGpuAllocationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableAutomaticGpuAllocation>(ptr);
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

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableAutomaticGpuAllocation);
} // namespace Cmd
} // namespace Sdx
