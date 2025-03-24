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
/// Set the enabled SBAS messages. Message 63 is always enabled
///
/// Name     Type      Description
/// -------- --------- --------------------
/// Messages array int The enabled messages
///

class EnableSbasMessages;
typedef std::shared_ptr<EnableSbasMessages> EnableSbasMessagesPtr;

class EnableSbasMessages : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableSbasMessages";
  inline static const char* const Documentation = "Set the enabled SBAS messages. Message 63 is always enabled\n"
                                                  "\n"
                                                  "Name     Type      Description\n"
                                                  "-------- --------- --------------------\n"
                                                  "Messages array int The enabled messages";
  inline static const char* const TargetId = "";

  EnableSbasMessages() : CommandBase(CmdName, TargetId) {}

  EnableSbasMessages(const std::vector<int>& messages) : CommandBase(CmdName, TargetId) { setMessages(messages); }

  static EnableSbasMessagesPtr create(const std::vector<int>& messages)
  {
    return std::make_shared<EnableSbasMessages>(messages);
  }

  static EnableSbasMessagesPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableSbasMessages>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<int>>::is_valid(m_values["Messages"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Messages"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::vector<int> messages() const { return parse_json<std::vector<int>>::parse(m_values["Messages"]); }

  void setMessages(const std::vector<int>& messages)
  {
    m_values.AddMember("Messages",
                       parse_json<std::vector<int>>::format(messages, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableSbasMessages);
} // namespace Cmd
} // namespace Sdx
