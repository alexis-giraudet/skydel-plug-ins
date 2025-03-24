#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Quit/Exit Skydel. Simulation must be stopped to be able to quit Skydel
///
/// Name      Type Description
/// --------- ---- --------------------------------------------------------
/// ForceQuit bool Force to quit Skydel even if current config is not saved
///

class Quit;
typedef std::shared_ptr<Quit> QuitPtr;

class Quit : public CommandBase
{
public:
  inline static const char* const CmdName = "Quit";
  inline static const char* const Documentation =
    "Quit/Exit Skydel. Simulation must be stopped to be able to quit Skydel\n"
    "\n"
    "Name      Type Description\n"
    "--------- ---- --------------------------------------------------------\n"
    "ForceQuit bool Force to quit Skydel even if current config is not saved";
  inline static const char* const TargetId = "";

  Quit() : CommandBase(CmdName, TargetId) {}

  Quit(bool forceQuit) : CommandBase(CmdName, TargetId) { setForceQuit(forceQuit); }

  static QuitPtr create(bool forceQuit) { return std::make_shared<Quit>(forceQuit); }

  static QuitPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<Quit>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["ForceQuit"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ForceQuit"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  bool forceQuit() const { return parse_json<bool>::parse(m_values["ForceQuit"]); }

  void setForceQuit(bool forceQuit)
  {
    m_values.AddMember("ForceQuit",
                       parse_json<bool>::format(forceQuit, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(Quit);
} // namespace Cmd
} // namespace Sdx
