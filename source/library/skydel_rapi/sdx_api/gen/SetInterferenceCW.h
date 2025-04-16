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
/// Add or update continuous wave interference signal.
///
/// Name        Type   Description
/// ----------- ------
/// -------------------------------------------------------------------------------------------------------------------------
/// StartTime   int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59
/// minutes and 59 seconds). StopTime    int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum
/// = 86399 s (23 hours, 59 minutes and 59 seconds). CentralFreq double Central frequency (Hz). Minimum = 100000000 Hz
/// (100 MHz), Maximum = 6000000000 Hz (6 GHz). Power       double Power (dB) relative to nominal power. Minimum = -40
/// dB, Maximum = 43 dB. Enabled     bool   Enables or disables the interference signal. Id          string Interference
/// signal unique identifier.
///

class SetInterferenceCW;
typedef std::shared_ptr<SetInterferenceCW> SetInterferenceCWPtr;

class SetInterferenceCW : public CommandBase
{
public:
  inline static const char* const CmdName = "SetInterferenceCW";
  inline static const char* const Documentation =
    "Add or update continuous wave interference signal.\n"
    "\n"
    "Name        Type   Description\n"
    "----------- ------ -------------------------------------------------------------------------------------------------------------------------\n"
    "StartTime   int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
    "StopTime    int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
    "CentralFreq double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
    "Power       double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
    "Enabled     bool   Enables or disables the interference signal.\n"
    "Id          string Interference signal unique identifier.";
  inline static const char* const TargetId = "";

  SetInterferenceCW() : CommandBase(CmdName, TargetId) {}

  SetInterferenceCW(int startTime,
                    int stopTime,
                    double centralFreq,
                    double power,
                    bool enabled,
                    const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setStartTime(startTime);
    setStopTime(stopTime);
    setCentralFreq(centralFreq);
    setPower(power);
    setEnabled(enabled);
    setId(id);
  }

  static SetInterferenceCWPtr create(int startTime,
                                     int stopTime,
                                     double centralFreq,
                                     double power,
                                     bool enabled,
                                     const std::string& id)
  {
    return std::make_shared<SetInterferenceCW>(startTime, stopTime, centralFreq, power, enabled, id);
  }

  static SetInterferenceCWPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetInterferenceCW>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["StartTime"]) &&
           parse_json<int>::is_valid(m_values["StopTime"]) && parse_json<double>::is_valid(m_values["CentralFreq"]) &&
           parse_json<double>::is_valid(m_values["Power"]) && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"StartTime", "StopTime", "CentralFreq", "Power", "Enabled", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  int startTime() const { return parse_json<int>::parse(m_values["StartTime"]); }

  void setStartTime(int startTime)
  {
    m_values.AddMember("StartTime",
                       parse_json<int>::format(startTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int stopTime() const { return parse_json<int>::parse(m_values["StopTime"]); }

  void setStopTime(int stopTime)
  {
    m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double centralFreq() const { return parse_json<double>::parse(m_values["CentralFreq"]); }

  void setCentralFreq(double centralFreq)
  {
    m_values.AddMember("CentralFreq",
                       parse_json<double>::format(centralFreq, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double power() const { return parse_json<double>::parse(m_values["Power"]); }

  void setPower(double power)
  {
    m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetInterferenceCW);
} // namespace Cmd
} // namespace Sdx
