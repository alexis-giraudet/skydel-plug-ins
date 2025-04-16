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
/// Result of GetIntTxBOC.
///
/// Name           Type         Description
/// -------------- ------------ ------------------------------------------------------------------------------------
/// Enabled        bool         Enable (true) or disable (false) the signal
/// CentralFreq    double       Central frequency (Hz)
/// Power          double       Power (dB), relative to transmitter reference power
/// CodeRate       int          Code rate (Chips/s). Must be between 1000 and 60000000 and a multiple of 1 kChips/s.
/// CodeLengthMs   int          Code length (ms). Must be between 1 and 100.
/// SubCarrierRate int          Sub-carrier rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.
/// CosinePhaseBoc bool         Use Cosine-Phase BOC instead of default Sine-Phase BOC.
/// TransmitterId  string       Transmitter unique identifier.
/// SignalId       string       BOC unique identifier.
/// Group          optional int Group, if not using default group.
///

class GetIntTxBOCResult;
typedef std::shared_ptr<GetIntTxBOCResult> GetIntTxBOCResultPtr;

class GetIntTxBOCResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIntTxBOCResult";
  inline static const char* const Documentation =
    "Result of GetIntTxBOC.\n"
    "\n"
    "Name           Type         Description\n"
    "-------------- ------------ ------------------------------------------------------------------------------------\n"
    "Enabled        bool         Enable (true) or disable (false) the signal\n"
    "CentralFreq    double       Central frequency (Hz)\n"
    "Power          double       Power (dB), relative to transmitter reference power\n"
    "CodeRate       int          Code rate (Chips/s). Must be between 1000 and 60000000 and a multiple of 1 kChips/s.\n"
    "CodeLengthMs   int          Code length (ms). Must be between 1 and 100.\n"
    "SubCarrierRate int          Sub-carrier rate (Hz). Must be between 1000 and 60000000 and a multiple of 1KHz.\n"
    "CosinePhaseBoc bool         Use Cosine-Phase BOC instead of default Sine-Phase BOC.\n"
    "TransmitterId  string       Transmitter unique identifier.\n"
    "SignalId       string       BOC unique identifier.\n"
    "Group          optional int Group, if not using default group.";
  inline static const char* const TargetId = "";

  GetIntTxBOCResult() : CommandResult(CmdName, TargetId) {}

  GetIntTxBOCResult(bool enabled,
                    double centralFreq,
                    double power,
                    int codeRate,
                    int codeLengthMs,
                    int subCarrierRate,
                    bool cosinePhaseBoc,
                    const std::string& transmitterId,
                    const std::string& signalId,
                    const std::optional<int>& group = {}) :
    CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setCodeRate(codeRate);
    setCodeLengthMs(codeLengthMs);
    setSubCarrierRate(subCarrierRate);
    setCosinePhaseBoc(cosinePhaseBoc);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setGroup(group);
  }

  GetIntTxBOCResult(CommandBasePtr relatedCommand,
                    bool enabled,
                    double centralFreq,
                    double power,
                    int codeRate,
                    int codeLengthMs,
                    int subCarrierRate,
                    bool cosinePhaseBoc,
                    const std::string& transmitterId,
                    const std::string& signalId,
                    const std::optional<int>& group = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
    setCentralFreq(centralFreq);
    setPower(power);
    setCodeRate(codeRate);
    setCodeLengthMs(codeLengthMs);
    setSubCarrierRate(subCarrierRate);
    setCosinePhaseBoc(cosinePhaseBoc);
    setTransmitterId(transmitterId);
    setSignalId(signalId);
    setGroup(group);
  }

  static GetIntTxBOCResultPtr create(bool enabled,
                                     double centralFreq,
                                     double power,
                                     int codeRate,
                                     int codeLengthMs,
                                     int subCarrierRate,
                                     bool cosinePhaseBoc,
                                     const std::string& transmitterId,
                                     const std::string& signalId,
                                     const std::optional<int>& group = {})
  {
    return std::make_shared<GetIntTxBOCResult>(enabled,
                                               centralFreq,
                                               power,
                                               codeRate,
                                               codeLengthMs,
                                               subCarrierRate,
                                               cosinePhaseBoc,
                                               transmitterId,
                                               signalId,
                                               group);
  }

  static GetIntTxBOCResultPtr create(CommandBasePtr relatedCommand,
                                     bool enabled,
                                     double centralFreq,
                                     double power,
                                     int codeRate,
                                     int codeLengthMs,
                                     int subCarrierRate,
                                     bool cosinePhaseBoc,
                                     const std::string& transmitterId,
                                     const std::string& signalId,
                                     const std::optional<int>& group = {})
  {
    return std::make_shared<GetIntTxBOCResult>(relatedCommand,
                                               enabled,
                                               centralFreq,
                                               power,
                                               codeRate,
                                               codeLengthMs,
                                               subCarrierRate,
                                               cosinePhaseBoc,
                                               transmitterId,
                                               signalId,
                                               group);
  }

  static GetIntTxBOCResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxBOCResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<double>::is_valid(m_values["CentralFreq"]) && parse_json<double>::is_valid(m_values["Power"]) &&
           parse_json<int>::is_valid(m_values["CodeRate"]) && parse_json<int>::is_valid(m_values["CodeLengthMs"]) &&
           parse_json<int>::is_valid(m_values["SubCarrierRate"]) &&
           parse_json<bool>::is_valid(m_values["CosinePhaseBoc"]) &&
           parse_json<std::string>::is_valid(m_values["TransmitterId"]) &&
           parse_json<std::string>::is_valid(m_values["SignalId"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["Group"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled",
                                                 "CentralFreq",
                                                 "Power",
                                                 "CodeRate",
                                                 "CodeLengthMs",
                                                 "SubCarrierRate",
                                                 "CosinePhaseBoc",
                                                 "TransmitterId",
                                                 "SignalId",
                                                 "Group"};
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

  int codeRate() const { return parse_json<int>::parse(m_values["CodeRate"]); }

  void setCodeRate(int codeRate)
  {
    m_values.AddMember("CodeRate", parse_json<int>::format(codeRate, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int codeLengthMs() const { return parse_json<int>::parse(m_values["CodeLengthMs"]); }

  void setCodeLengthMs(int codeLengthMs)
  {
    m_values.AddMember("CodeLengthMs",
                       parse_json<int>::format(codeLengthMs, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int subCarrierRate() const { return parse_json<int>::parse(m_values["SubCarrierRate"]); }

  void setSubCarrierRate(int subCarrierRate)
  {
    m_values.AddMember("SubCarrierRate",
                       parse_json<int>::format(subCarrierRate, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool cosinePhaseBoc() const { return parse_json<bool>::parse(m_values["CosinePhaseBoc"]); }

  void setCosinePhaseBoc(bool cosinePhaseBoc)
  {
    m_values.AddMember("CosinePhaseBoc",
                       parse_json<bool>::format(cosinePhaseBoc, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(GetIntTxBOCResult);
} // namespace Cmd
} // namespace Sdx
