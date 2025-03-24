#pragma once

#include <memory>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Group multiple commands as one
///
/// Name     Type               Description
/// -------- ------------------ -----------------------
/// Commands array command_base The commands to execute
///

class CommandGroup;
typedef std::shared_ptr<CommandGroup> CommandGroupPtr;

class CommandGroup : public CommandBase
{
public:
  inline static const char* const CmdName = "CommandGroup";
  inline static const char* const Documentation = "Group multiple commands as one\n"
                                                  "\n"
                                                  "Name     Type               Description\n"
                                                  "-------- ------------------ -----------------------\n"
                                                  "Commands array command_base The commands to execute";
  inline static const char* const TargetId = "";

  CommandGroup() : CommandBase(CmdName, TargetId) {}

  CommandGroup(const std::vector<Sdx::CommandBasePtr>& commands) : CommandBase(CmdName, TargetId)
  {

    setCommands(commands);
  }

  static CommandGroupPtr create(const std::vector<Sdx::CommandBasePtr>& commands)
  {
    return std::make_shared<CommandGroup>(commands);
  }

  static CommandGroupPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<CommandGroup>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<Sdx::CommandBasePtr>>::is_valid(m_values["Commands"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Commands"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::vector<Sdx::CommandBasePtr> commands() const
  {
    return parse_json<std::vector<Sdx::CommandBasePtr>>::parse(m_values["Commands"]);
  }

  void setCommands(const std::vector<Sdx::CommandBasePtr>& commands)
  {
    m_values.AddMember("Commands",
                       parse_json<std::vector<Sdx::CommandBasePtr>>::format(commands, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(CommandGroup);
} // namespace Cmd
} // namespace Sdx
