#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Remove message from sequence.
///
/// Name   Type   Description
/// ------ ------ ----------------------------------------------------------------------------------------
/// Signal string Signal Name ("L2C" for example)
/// Index  int    Message index in sequence where to remove. Set to -1 to remove last message in sequence.
///

class MessageSequenceRemove;
typedef std::shared_ptr<MessageSequenceRemove> MessageSequenceRemovePtr;

class MessageSequenceRemove : public CommandBase
{
public:
  inline static const char* const CmdName = "MessageSequenceRemove";
  inline static const char* const Documentation =
    "Remove message from sequence.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ----------------------------------------------------------------------------------------\n"
    "Signal string Signal Name (\"L2C\" for example)\n"
    "Index  int    Message index in sequence where to remove. Set to -1 to remove last message in sequence.";
  inline static const char* const TargetId = "";

  MessageSequenceRemove() : CommandBase(CmdName, TargetId) {}

  MessageSequenceRemove(const std::string& signal, int index) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setIndex(index);
  }

  static MessageSequenceRemovePtr create(const std::string& signal, int index)
  {
    return std::make_shared<MessageSequenceRemove>(signal, index);
  }

  static MessageSequenceRemovePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<MessageSequenceRemove>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<int>::is_valid(m_values["Index"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Index"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int index() const { return parse_json<int>::parse(m_values["Index"]); }

  void setIndex(int index)
  {
    m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(MessageSequenceRemove);
} // namespace Cmd
} // namespace Sdx
