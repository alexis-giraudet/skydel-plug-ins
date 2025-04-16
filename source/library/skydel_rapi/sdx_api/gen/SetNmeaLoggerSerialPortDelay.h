#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the delay of the NMEA serial port logging.
///
/// Name  Type Description
/// ----- ---- ---------------------------------
/// Delay int  Delay from 0 to 100 milliseconds.
///

class SetNmeaLoggerSerialPortDelay;
typedef std::shared_ptr<SetNmeaLoggerSerialPortDelay> SetNmeaLoggerSerialPortDelayPtr;

class SetNmeaLoggerSerialPortDelay : public CommandBase
{
public:
  inline static const char* const CmdName = "SetNmeaLoggerSerialPortDelay";
  inline static const char* const Documentation = "Set the delay of the NMEA serial port logging.\n"
                                                  "\n"
                                                  "Name  Type Description\n"
                                                  "----- ---- ---------------------------------\n"
                                                  "Delay int  Delay from 0 to 100 milliseconds.";
  inline static const char* const TargetId = "";

  SetNmeaLoggerSerialPortDelay() : CommandBase(CmdName, TargetId) {}

  SetNmeaLoggerSerialPortDelay(int delay) : CommandBase(CmdName, TargetId) { setDelay(delay); }

  static SetNmeaLoggerSerialPortDelayPtr create(int delay)
  {
    return std::make_shared<SetNmeaLoggerSerialPortDelay>(delay);
  }

  static SetNmeaLoggerSerialPortDelayPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetNmeaLoggerSerialPortDelay>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Delay"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Delay"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int delay() const { return parse_json<int>::parse(m_values["Delay"]); }

  void setDelay(int delay)
  {
    m_values.AddMember("Delay", parse_json<int>::format(delay, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetNmeaLoggerSerialPortDelay);
} // namespace Cmd
} // namespace Sdx
