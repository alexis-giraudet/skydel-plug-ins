#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Prevent GUI updates while modify the configuration. Use UnlockGUI when done with
/// configuration modifications.
///
///
///

class LockGUI;
typedef std::shared_ptr<LockGUI> LockGUIPtr;

class LockGUI : public CommandBase
{
public:
  inline static const char* const CmdName = "LockGUI";
  inline static const char* const Documentation =
    "Prevent GUI updates while modify the configuration. Use UnlockGUI when done with\n"
    "configuration modifications.";
  inline static const char* const TargetId = "";

  LockGUI() : CommandBase(CmdName, TargetId) {}

  static LockGUIPtr create() { return std::make_shared<LockGUI>(); }

  static LockGUIPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<LockGUI>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(LockGUI);
} // namespace Cmd
} // namespace Sdx
