#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Resume GUI updates and force one update immediately.
///
///
///

class UnlockGUI;
typedef std::shared_ptr<UnlockGUI> UnlockGUIPtr;

class UnlockGUI : public CommandBase
{
public:
  inline static const char* const CmdName = "UnlockGUI";
  inline static const char* const Documentation = "Resume GUI updates and force one update immediately.";
  inline static const char* const TargetId = "";

  UnlockGUI() : CommandBase(CmdName, TargetId) {}

  static UnlockGUIPtr create() { return std::make_shared<UnlockGUI>(); }

  static UnlockGUIPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<UnlockGUI>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(UnlockGUI);
} // namespace Cmd
} // namespace Sdx
