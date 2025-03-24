#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIntTxPulse.
///
/// Name          Type         Description
/// ------------- ------------ --------------------------------------------------------------
/// Enabled       bool         Enable (true) or disable (false) the signal
/// CentralFreq   double       Central frequency (Hz)
/// Power         double       Power (dB), relative to transmitter reference power
/// DutyCycle     double       Duty Cycle between 0.01 and 100, as a percentage of Pulse Rate
/// PulseRate     int          Pulse rate (Hz), between 1 and 100000
/// TransmitterId string       Transmitter unique identifier.
/// SignalId      string       Pulse unique identifier.
/// Group         optional int Group, if not using default group.
///

class GetIntTxPulseResult;
typedef std::shared_ptr<GetIntTxPulseResult> GetIntTxPulseResultPtr;

class GetIntTxPulseResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIntTxPulseResult";
  inline static const char* const Documentation =
    "Result of GetIntTxPulse.\n"
    "\n"
    "Name          Type         Description\n"
    "------------- ------------ --------------------------------------------------------------\n"
    "Enabled       bool         Enable (true) or disable (false) the signal\n"
    "CentralFreq   double       Central frequency (Hz)\n"
    "Power         double       Power (dB), relative to transmitter reference power\n"
    "DutyCycle     double       Duty Cycle between 0.01 and 100, as a percentage of Pulse Rate\n"
    "PulseRate     int          Pulse rate (Hz), between 1 and 100000\n"
    "TransmitterId string       Transmitter unique identifier.\n"
    "SignalId      string       Pulse unique identifier.\n"
    "Group         optional int Group, if not using default group.";
  inline static const char* const TargetId = "";

  GetIntTxPulseResult() : CommandResult(CmdName, TargetId) {}

  GetIntTxPulseResult(bool enabled,
                      double centralFreq,
                      double power,
                      double dutyCycle,
                      int pulseRate,
                      const std::string& transmitterId,
                      const std::string& signalId,
                      const std::optional<int>& group = {}) :
    CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setDutyCycle(dutyCycle);
    setPulseRate(pulseRate);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setGroup(group);
  }

  GetIntTxPulseResult(CommandBasePtr relatedCommand,
                      bool enabled,
                      double centralFreq,
                      double power,
                      double dutyCycle,
                      int pulseRate,
                      const std::string& transmitterId,
                      const std::string& signalId,
                      const std::optional<int>& group = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setDutyCycle(dutyCycle);
    setPulseRate(pulseRate);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setGroup(group);
  }

  static GetIntTxPulseResultPtr create(bool enabled,
                                       double centralFreq,
                                       double power,
                                       double dutyCycle,
                                       int pulseRate,
                                       const std::string& transmitterId,
                                       const std::string& signalId,
                                       const std::optional<int>& group = {})
  {
    return std::make_shared<GetIntTxPulseResult>(enabled,
                                                 centralFreq,
                                                 power,
                                                 dutyCycle,
                                                 pulseRate,
                                                 transmitterId,
                                                 signalId,
                                                 group);
  }

  static GetIntTxPulseResultPtr create(CommandBasePtr relatedCommand,
                                       bool enabled,
                                       double centralFreq,
                                       double power,
                                       double dutyCycle,
                                       int pulseRate,
                                       const std::string& transmitterId,
                                       const std::string& signalId,
                                       const std::optional<int>& group = {})
  {
    return std::make_shared<GetIntTxPulseResult>(relatedCommand,
                                                 enabled,
                                                 centralFreq,
                                                 power,
                                                 dutyCycle,
                                                 pulseRate,
                                                 transmitterId,
                                                 signalId,
                                                 group);
  }

  static GetIntTxPulseResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxPulseResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<double>::is_valid(m_values["CentralFreq"]) && parse_json<double>::is_valid(m_values["Power"]) &&
           parse_json<double>::is_valid(m_values["DutyCycle"]) && parse_json<int>::is_valid(m_values["PulseRate"]) &&
           parse_json<std::string>::is_valid(m_values["TransmitterId"]) &&
           parse_json<std::string>::is_valid(m_values["SignalId"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["Group"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Enabled", "CentralFreq", "Power", "DutyCycle", "PulseRate", "TransmitterId", "SignalId", "Group"};
    return names;
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
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

  double dutyCycle() const { return parse_json<double>::parse(m_values["DutyCycle"]); }

  void setDutyCycle(double dutyCycle)
  {
    m_values.AddMember("DutyCycle",
                       parse_json<double>::format(dutyCycle, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int pulseRate() const { return parse_json<int>::parse(m_values["PulseRate"]); }

  void setPulseRate(int pulseRate)
  {
    m_values.AddMember("PulseRate",
                       parse_json<int>::format(pulseRate, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string transmitterId() const { return parse_json<std::string>::parse(m_values["TransmitterId"]); }

  void setTransmitterId(const std::string& transmitterId)
  {
    m_values.AddMember("TransmitterId",
                       parse_json<std::string>::format(transmitterId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string signalId() const { return parse_json<std::string>::parse(m_values["SignalId"]); }

  void setSignalId(const std::string& signalId)
  {
    m_values.AddMember("SignalId",
                       parse_json<std::string>::format(signalId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<int> group() const { return parse_json<std::optional<int>>::parse(m_values["Group"]); }

  void setGroup(const std::optional<int>& group)
  {
    m_values.AddMember("Group",
                       parse_json<std::optional<int>>::format(group, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIntTxPulseResult);
} // namespace Cmd
} // namespace Sdx
