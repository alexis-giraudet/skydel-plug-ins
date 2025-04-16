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
/// Result of GetIntTxCW.
///
/// Name               Type            Description
/// ------------------ --------------- ---------------------------------------------------
/// Enabled            bool            Enable (true) or disable (false) the signal
/// CentralFreq        double          Central frequency (Hz)
/// Power              double          Power (dB), relative to transmitter reference power
/// TransmitterId      string          Transmitter unique identifier.
/// SignalId           string          CW unique identifier.
/// InitialPhaseOffset optional double Initial phase offset, in radians. Defaults to 0.
/// Group              optional int    Group, if not using default group.
///

class GetIntTxCWResult;
typedef std::shared_ptr<GetIntTxCWResult> GetIntTxCWResultPtr;

class GetIntTxCWResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIntTxCWResult";
  inline static const char* const Documentation =
    "Result of GetIntTxCW.\n"
    "\n"
    "Name               Type            Description\n"
    "------------------ --------------- ---------------------------------------------------\n"
    "Enabled            bool            Enable (true) or disable (false) the signal\n"
    "CentralFreq        double          Central frequency (Hz)\n"
    "Power              double          Power (dB), relative to transmitter reference power\n"
    "TransmitterId      string          Transmitter unique identifier.\n"
    "SignalId           string          CW unique identifier.\n"
    "InitialPhaseOffset optional double Initial phase offset, in radians. Defaults to 0.\n"
    "Group              optional int    Group, if not using default group.";
  inline static const char* const TargetId = "";

  GetIntTxCWResult() : CommandResult(CmdName, TargetId) {}

  GetIntTxCWResult(bool enabled,
                   double centralFreq,
                   double power,
                   const std::string& transmitterId,
                   const std::string& signalId,
                   const std::optional<double>& initialPhaseOffset = {},
                   const std::optional<int>& group = {}) :
    CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setInitialPhaseOffset(initialPhaseOffset);
    setGroup(group);
  }

  GetIntTxCWResult(CommandBasePtr relatedCommand,
                   bool enabled,
                   double centralFreq,
                   double power,
                   const std::string& transmitterId,
                   const std::string& signalId,
                   const std::optional<double>& initialPhaseOffset = {},
                   const std::optional<int>& group = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setInitialPhaseOffset(initialPhaseOffset);
    setGroup(group);
  }

  static GetIntTxCWResultPtr create(bool enabled,
                                    double centralFreq,
                                    double power,
                                    const std::string& transmitterId,
                                    const std::string& signalId,
                                    const std::optional<double>& initialPhaseOffset = {},
                                    const std::optional<int>& group = {})
  {
    return std::make_shared<GetIntTxCWResult>(enabled,
                                              centralFreq,
                                              power,
                                              transmitterId,
                                              signalId,
                                              initialPhaseOffset,
                                              group);
  }

  static GetIntTxCWResultPtr create(CommandBasePtr relatedCommand,
                                    bool enabled,
                                    double centralFreq,
                                    double power,
                                    const std::string& transmitterId,
                                    const std::string& signalId,
                                    const std::optional<double>& initialPhaseOffset = {},
                                    const std::optional<int>& group = {})
  {
    return std::make_shared<GetIntTxCWResult>(relatedCommand,
                                              enabled,
                                              centralFreq,
                                              power,
                                              transmitterId,
                                              signalId,
                                              initialPhaseOffset,
                                              group);
  }

  static GetIntTxCWResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxCWResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<double>::is_valid(m_values["CentralFreq"]) && parse_json<double>::is_valid(m_values["Power"]) &&
           parse_json<std::string>::is_valid(m_values["TransmitterId"]) &&
           parse_json<std::string>::is_valid(m_values["SignalId"]) &&
           parse_json<std::optional<double>>::is_valid(m_values["InitialPhaseOffset"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["Group"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Enabled", "CentralFreq", "Power", "TransmitterId", "SignalId", "InitialPhaseOffset", "Group"};
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

  std::optional<double> initialPhaseOffset() const
  {
    return parse_json<std::optional<double>>::parse(m_values["InitialPhaseOffset"]);
  }

  void setInitialPhaseOffset(const std::optional<double>& initialPhaseOffset)
  {
    m_values.AddMember("InitialPhaseOffset",
                       parse_json<std::optional<double>>::format(initialPhaseOffset, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(GetIntTxCWResult);
} // namespace Cmd
} // namespace Sdx
