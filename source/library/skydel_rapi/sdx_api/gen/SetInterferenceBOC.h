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
/// Add or update a BOC interference signal.
///
/// Name           Type   Description
/// -------------- ------
/// -------------------------------------------------------------------------------------------------------------------------------------
/// StartTime      int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours,
/// 59 minutes and 59 seconds). StopTime       int    Elapsed time at which the signal is disabled (s). Minimum = 0 s,
/// Maximum = 86399 s (23 hours, 59 minutes and 59 seconds). CentralFreq    double Central frequency (Hz). Minimum =
/// 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz). Power          double Power (dB) relative to nominal power.
/// Minimum = -40 dB, Maximum = 43 dB. CodeRate       int    Code rate (Chips/s). Must be a multiple of 1 kChips/s.
/// Minimum = 1000 Chips/s (1 kChips/s), Maximum = 60000000 Chips/s (60 MChips/s). CodeLengthMs   int    Code length
/// (ms). Minimum = 1 ms, Maximum = 100 ms. SubCarrierRate int    Sub-carrier rate (Hz). Must be a multiple of 1 kHz.
/// Minimum = 1000 Hz (1 kHz), Maximum = 60000000 (60 MHz). CosinePhaseBoc bool   Use Cosine-Phase BOC instead of
/// default Sine-Phase BOC. Enabled        bool   Enables or disables the interference signal. Id             string
/// Interference signal unique identifier.
///

class SetInterferenceBOC;
typedef std::shared_ptr<SetInterferenceBOC> SetInterferenceBOCPtr;

class SetInterferenceBOC : public CommandBase
{
public:
  inline static const char* const CmdName = "SetInterferenceBOC";
  inline static const char* const Documentation =
    "Add or update a BOC interference signal.\n"
    "\n"
    "Name           Type   Description\n"
    "-------------- ------ -------------------------------------------------------------------------------------------------------------------------------------\n"
    "StartTime      int    Elapsed time at which the signal is enabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
    "StopTime       int    Elapsed time at which the signal is disabled (s). Minimum = 0 s, Maximum = 86399 s (23 hours, 59 minutes and 59 seconds).\n"
    "CentralFreq    double Central frequency (Hz). Minimum = 100000000 Hz (100 MHz), Maximum = 6000000000 Hz (6 GHz).\n"
    "Power          double Power (dB) relative to nominal power. Minimum = -40 dB, Maximum = 43 dB.\n"
    "CodeRate       int    Code rate (Chips/s). Must be a multiple of 1 kChips/s. Minimum = 1000 Chips/s (1 kChips/s), Maximum = 60000000 Chips/s (60 MChips/s).\n"
    "CodeLengthMs   int    Code length (ms). Minimum = 1 ms, Maximum = 100 ms.\n"
    "SubCarrierRate int    Sub-carrier rate (Hz). Must be a multiple of 1 kHz. Minimum = 1000 Hz (1 kHz), Maximum = 60000000 (60 MHz).\n"
    "CosinePhaseBoc bool   Use Cosine-Phase BOC instead of default Sine-Phase BOC.\n"
    "Enabled        bool   Enables or disables the interference signal.\n"
    "Id             string Interference signal unique identifier.";
  inline static const char* const TargetId = "";

  SetInterferenceBOC() : CommandBase(CmdName, TargetId) {}

  SetInterferenceBOC(int startTime,
                     int stopTime,
                     double centralFreq,
                     double power,
                     int codeRate,
                     int codeLengthMs,
                     int subCarrierRate,
                     bool cosinePhaseBoc,
                     bool enabled,
                     const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setStartTime(startTime);
    setStopTime(stopTime);
    setCentralFreq(centralFreq);
    setPower(power);
    setCodeRate(codeRate);
    setCodeLengthMs(codeLengthMs);
    setSubCarrierRate(subCarrierRate);
    setCosinePhaseBoc(cosinePhaseBoc);
    setEnabled(enabled);
    setId(id);
  }

  static SetInterferenceBOCPtr create(int startTime,
                                      int stopTime,
                                      double centralFreq,
                                      double power,
                                      int codeRate,
                                      int codeLengthMs,
                                      int subCarrierRate,
                                      bool cosinePhaseBoc,
                                      bool enabled,
                                      const std::string& id)
  {
    return std::make_shared<SetInterferenceBOC>(startTime,
                                                stopTime,
                                                centralFreq,
                                                power,
                                                codeRate,
                                                codeLengthMs,
                                                subCarrierRate,
                                                cosinePhaseBoc,
                                                enabled,
                                                id);
  }

  static SetInterferenceBOCPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetInterferenceBOC>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["StartTime"]) &&
           parse_json<int>::is_valid(m_values["StopTime"]) && parse_json<double>::is_valid(m_values["CentralFreq"]) &&
           parse_json<double>::is_valid(m_values["Power"]) && parse_json<int>::is_valid(m_values["CodeRate"]) &&
           parse_json<int>::is_valid(m_values["CodeLengthMs"]) &&
           parse_json<int>::is_valid(m_values["SubCarrierRate"]) &&
           parse_json<bool>::is_valid(m_values["CosinePhaseBoc"]) && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"StartTime",
                                                 "StopTime",
                                                 "CentralFreq",
                                                 "Power",
                                                 "CodeRate",
                                                 "CodeLengthMs",
                                                 "SubCarrierRate",
                                                 "CosinePhaseBoc",
                                                 "Enabled",
                                                 "Id"};
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
REGISTER_COMMAND_TO_FACTORY(SetInterferenceBOC);
} // namespace Cmd
} // namespace Sdx
