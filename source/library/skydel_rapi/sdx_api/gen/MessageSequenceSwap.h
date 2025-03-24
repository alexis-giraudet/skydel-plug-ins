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
/// Swap 2 messages in sequence.
///
/// Name   Type   Description
/// ------ ------ -------------------------------
/// Signal string Signal Name ("L2C" for example)
/// IndexI int    Message index i in sequence.
/// IndexJ int    Message index j in sequence.
///

class MessageSequenceSwap;
typedef std::shared_ptr<MessageSequenceSwap> MessageSequenceSwapPtr;

class MessageSequenceSwap : public CommandBase
{
public:
  inline static const char* const CmdName = "MessageSequenceSwap";
  inline static const char* const Documentation = "Swap 2 messages in sequence.\n"
                                                  "\n"
                                                  "Name   Type   Description\n"
                                                  "------ ------ -------------------------------\n"
                                                  "Signal string Signal Name (\"L2C\" for example)\n"
                                                  "IndexI int    Message index i in sequence.\n"
                                                  "IndexJ int    Message index j in sequence.";
  inline static const char* const TargetId = "";

  MessageSequenceSwap() : CommandBase(CmdName, TargetId) {}

  MessageSequenceSwap(const std::string& signal, int indexI, int indexJ) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setIndexI(indexI);
    setIndexJ(indexJ);
  }

  static MessageSequenceSwapPtr create(const std::string& signal, int indexI, int indexJ)
  {
    return std::make_shared<MessageSequenceSwap>(signal, indexI, indexJ);
  }

  static MessageSequenceSwapPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<MessageSequenceSwap>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<int>::is_valid(m_values["IndexI"]) && parse_json<int>::is_valid(m_values["IndexJ"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "IndexI", "IndexJ"};
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

  int indexI() const { return parse_json<int>::parse(m_values["IndexI"]); }

  void setIndexI(int indexI)
  {
    m_values.AddMember("IndexI", parse_json<int>::format(indexI, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int indexJ() const { return parse_json<int>::parse(m_values["IndexJ"]); }

  void setIndexJ(int indexJ)
  {
    m_values.AddMember("IndexJ", parse_json<int>::format(indexJ, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(MessageSequenceSwap);
} // namespace Cmd
} // namespace Sdx
