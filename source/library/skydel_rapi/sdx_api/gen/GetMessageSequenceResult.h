#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetMessageSequence.
///
/// Name     Type      Description
/// -------- --------- -------------------------------
/// Signal   string    Signal Name ("L2C" for example)
/// Sequence array int List of message type
///

class GetMessageSequenceResult;
typedef std::shared_ptr<GetMessageSequenceResult> GetMessageSequenceResultPtr;

class GetMessageSequenceResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetMessageSequenceResult";
  inline static const char* const Documentation = "Result of GetMessageSequence.\n"
                                                  "\n"
                                                  "Name     Type      Description\n"
                                                  "-------- --------- -------------------------------\n"
                                                  "Signal   string    Signal Name (\"L2C\" for example)\n"
                                                  "Sequence array int List of message type";
  inline static const char* const TargetId = "";

  GetMessageSequenceResult() : CommandResult(CmdName, TargetId) {}

  GetMessageSequenceResult(const std::string& signal, const std::vector<int>& sequence) :
    CommandResult(CmdName, TargetId)
  {

    setSignal(signal);
    setSequence(sequence);
  }

  GetMessageSequenceResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& sequence) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSignal(signal);
    setSequence(sequence);
  }

  static GetMessageSequenceResultPtr create(const std::string& signal, const std::vector<int>& sequence)
  {
    return std::make_shared<GetMessageSequenceResult>(signal, sequence);
  }

  static GetMessageSequenceResultPtr create(CommandBasePtr relatedCommand,
                                            const std::string& signal,
                                            const std::vector<int>& sequence)
  {
    return std::make_shared<GetMessageSequenceResult>(relatedCommand, signal, sequence);
  }

  static GetMessageSequenceResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMessageSequenceResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["Sequence"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Sequence"};
    return names;
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<int> sequence() const { return parse_json<std::vector<int>>::parse(m_values["Sequence"]); }

  void setSequence(const std::vector<int>& sequence)
  {
    m_values.AddMember("Sequence",
                       parse_json<std::vector<int>>::format(sequence, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMessageSequenceResult);
} // namespace Cmd
} // namespace Sdx
