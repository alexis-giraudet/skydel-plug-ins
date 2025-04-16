#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetNmeaLoggerSerialPortDelay.
///
/// Name  Type Description
/// ----- ---- ---------------------------------
/// Delay int  Delay from 0 to 100 milliseconds.
///

class GetNmeaLoggerSerialPortDelayResult;
typedef std::shared_ptr<GetNmeaLoggerSerialPortDelayResult> GetNmeaLoggerSerialPortDelayResultPtr;

class GetNmeaLoggerSerialPortDelayResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetNmeaLoggerSerialPortDelayResult";
  inline static const char* const Documentation = "Result of GetNmeaLoggerSerialPortDelay.\n"
                                                  "\n"
                                                  "Name  Type Description\n"
                                                  "----- ---- ---------------------------------\n"
                                                  "Delay int  Delay from 0 to 100 milliseconds.";
  inline static const char* const TargetId = "";

  GetNmeaLoggerSerialPortDelayResult() : CommandResult(CmdName, TargetId) {}

  GetNmeaLoggerSerialPortDelayResult(int delay) : CommandResult(CmdName, TargetId) { setDelay(delay); }

  GetNmeaLoggerSerialPortDelayResult(CommandBasePtr relatedCommand, int delay) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setDelay(delay);
  }

  static GetNmeaLoggerSerialPortDelayResultPtr create(int delay)
  {
    return std::make_shared<GetNmeaLoggerSerialPortDelayResult>(delay);
  }

  static GetNmeaLoggerSerialPortDelayResultPtr create(CommandBasePtr relatedCommand, int delay)
  {
    return std::make_shared<GetNmeaLoggerSerialPortDelayResult>(relatedCommand, delay);
  }

  static GetNmeaLoggerSerialPortDelayResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetNmeaLoggerSerialPortDelayResult>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Delay"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Delay"};
    return names;
  }

  int delay() const { return parse_json<int>::parse(m_values["Delay"]); }

  void setDelay(int delay)
  {
    m_values.AddMember("Delay", parse_json<int>::format(delay, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetNmeaLoggerSerialPortDelayResult);
} // namespace Cmd
} // namespace Sdx
