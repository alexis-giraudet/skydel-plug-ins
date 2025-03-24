#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set Chirp signal to interference transmitter. A transmitter can combine
/// multiple signals of different types to create complex waveform. The signal id (SignalId) can be an empty
/// string. In such case, Skydel will assign a unique ID. If the signal id is already in use for the
/// specified transmitted, the existing signal is updated, ortherwise a new signal is added.
///
/// Name          Type         Description
/// ------------- ------------ ---------------------------------------------------
/// Enabled       bool         Enable (true) or disable (false) the signal
/// CentralFreq   double       Central frequency (Hz)
/// Power         double       Power (dB), relative to transmitter reference power
/// Bandwidth     double       Bandwidth (Hz)
/// SweepTime     double       sweep Time (us)
/// TransmitterId string       Transmitter unique identifier.
/// SignalId      string       Chirp unique identifier.
/// Group         optional int Group, if not using default group.
///

class SetIntTxChirp;
typedef std::shared_ptr<SetIntTxChirp> SetIntTxChirpPtr;

class SetIntTxChirp : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIntTxChirp";
  inline static const char* const Documentation =
    "Set Chirp signal to interference transmitter. A transmitter can combine\n"
    "multiple signals of different types to create complex waveform. The signal id (SignalId) can be an empty\n"
    "string. In such case, Skydel will assign a unique ID. If the signal id is already in use for the\n"
    "specified transmitted, the existing signal is updated, ortherwise a new signal is added.\n"
    "\n"
    "Name          Type         Description\n"
    "------------- ------------ ---------------------------------------------------\n"
    "Enabled       bool         Enable (true) or disable (false) the signal\n"
    "CentralFreq   double       Central frequency (Hz)\n"
    "Power         double       Power (dB), relative to transmitter reference power\n"
    "Bandwidth     double       Bandwidth (Hz)\n"
    "SweepTime     double       sweep Time (us)\n"
    "TransmitterId string       Transmitter unique identifier.\n"
    "SignalId      string       Chirp unique identifier.\n"
    "Group         optional int Group, if not using default group.";
  inline static const char* const TargetId = "";

  SetIntTxChirp() : CommandBase(CmdName, TargetId) {}

  SetIntTxChirp(bool enabled,
                double centralFreq,
                double power,
                double bandwidth,
                double sweepTime,
                const std::string& transmitterId,
                const std::string& signalId,
                const std::optional<int>& group = {}) :
    CommandBase(CmdName, TargetId)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setBandwidth(bandwidth);
    setSweepTime(sweepTime);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setGroup(group);
  }

  static SetIntTxChirpPtr create(bool enabled,
                                 double centralFreq,
                                 double power,
                                 double bandwidth,
                                 double sweepTime,
                                 const std::string& transmitterId,
                                 const std::string& signalId,
                                 const std::optional<int>& group = {})
  {
    return std::make_shared<SetIntTxChirp>(enabled,
                                           centralFreq,
                                           power,
                                           bandwidth,
                                           sweepTime,
                                           transmitterId,
                                           signalId,
                                           group);
  }

  static SetIntTxChirpPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIntTxChirp>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<double>::is_valid(m_values["CentralFreq"]) && parse_json<double>::is_valid(m_values["Power"]) &&
           parse_json<double>::is_valid(m_values["Bandwidth"]) && parse_json<double>::is_valid(m_values["SweepTime"]) &&
           parse_json<std::string>::is_valid(m_values["TransmitterId"]) &&
           parse_json<std::string>::is_valid(m_values["SignalId"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["Group"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Enabled", "CentralFreq", "Power", "Bandwidth", "SweepTime", "TransmitterId", "SignalId", "Group"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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

  double bandwidth() const { return parse_json<double>::parse(m_values["Bandwidth"]); }

  void setBandwidth(double bandwidth)
  {
    m_values.AddMember("Bandwidth",
                       parse_json<double>::format(bandwidth, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double sweepTime() const { return parse_json<double>::parse(m_values["SweepTime"]); }

  void setSweepTime(double sweepTime)
  {
    m_values.AddMember("SweepTime",
                       parse_json<double>::format(sweepTime, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(SetIntTxChirp);
} // namespace Cmd
} // namespace Sdx
