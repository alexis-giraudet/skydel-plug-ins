#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Enable/Disable Time Synchronization on main instance.
/// The main instance will control other Skydel simulators with main instance PPS Enabled.
///
/// Name    Type Description
/// ------- ---- ----------------------------------------------------------------------------
/// Enabled bool If true, this simulator will be the main instance to synchronize simulators.
///

class EnableMainInstanceSync;
typedef std::shared_ptr<EnableMainInstanceSync> EnableMainInstanceSyncPtr;

class EnableMainInstanceSync : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableMainInstanceSync";
  inline static const char* const Documentation =
    "Enable/Disable Time Synchronization on main instance.\n"
    "The main instance will control other Skydel simulators with main instance PPS Enabled.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ----------------------------------------------------------------------------\n"
    "Enabled bool If true, this simulator will be the main instance to synchronize simulators.";
  inline static const char* const TargetId = "";

  EnableMainInstanceSync() : CommandBase(CmdName, TargetId) {}

  EnableMainInstanceSync(bool enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static EnableMainInstanceSyncPtr create(bool enabled) { return std::make_shared<EnableMainInstanceSync>(enabled); }

  static EnableMainInstanceSyncPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableMainInstanceSync>(ptr);
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

  int executePermission() const { return EXECUTE_IF_IDLE; }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableMainInstanceSync);
} // namespace Cmd
} // namespace Sdx
