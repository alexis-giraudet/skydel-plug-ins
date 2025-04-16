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
/// Result of GetModulationTargetSignals.
///
/// Name             Type            Description
/// ---------------- ---------------
/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// Output           int             Output index (zero based)
/// MinRate          int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)
/// MaxRate          int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)
/// Band             string          Frequency band ("LowerL", "UpperL", "S-Band" or "C-Band")
/// Signal           string          Comma separated signal keys, accepted signal keys: "L1CA", "L1C", "L1P", "L1ME",
/// "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I",
/// "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1",
/// "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5" Gain             int             The gain associated to this
/// output (dB). This value has to be between the radio minimum value and 115. A negative value means to use the radio
/// default value. GaussianNoise    bool            If true, add Gaussian noise to ensure realistic signal to noise
/// ratio. When combining multiple outputs, only one should have Gaussian noise enabled. Id               string Target
/// identifier CentralFrequency optional double Forced central frequency to this value. Central frequency can only be
/// one of this values: 1176450000, 1191795000, 1202000000, 1207140000, 1217370000, 1222000000, 1227000000, 1227600000,
/// 1230000000, 1235000000, 1246000000, 1561098000, 1575420000, 1582000000, 1584000000, 1586000000, 1602000000,
/// 2492028000.
///

class GetModulationTargetSignalsResult;
typedef std::shared_ptr<GetModulationTargetSignalsResult> GetModulationTargetSignalsResultPtr;

class GetModulationTargetSignalsResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetModulationTargetSignalsResult";
  inline static const char* const Documentation =
    "Result of GetModulationTargetSignals.\n"
    "\n"
    "Name             Type            Description\n"
    "---------------- --------------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "Output           int             Output index (zero based)\n"
    "MinRate          int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
    "MaxRate          int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
    "Band             string          Frequency band (\"LowerL\", \"UpperL\", \"S-Band\" or \"C-Band\")\n"
    "Signal           string          Comma separated signal keys, accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
    "Gain             int             The gain associated to this output (dB). This value has to be between the radio minimum value and 115. A negative value means to use the radio default value.\n"
    "GaussianNoise    bool            If true, add Gaussian noise to ensure realistic signal to noise ratio. When combining multiple outputs, only one should have Gaussian noise enabled.\n"
    "Id               string          Target identifier\n"
    "CentralFrequency optional double Forced central frequency to this value. Central frequency can only be one of this values: 1176450000, 1191795000, 1202000000, 1207140000, 1217370000, 1222000000, 1227000000, 1227600000, 1230000000, 1235000000, 1246000000, 1561098000, 1575420000, 1582000000, 1584000000, 1586000000, 1602000000, 2492028000.";
  inline static const char* const TargetId = "";

  GetModulationTargetSignalsResult() : CommandResult(CmdName, TargetId) {}

  GetModulationTargetSignalsResult(int output,
                                   int minRate,
                                   int maxRate,
                                   const std::string& band,
                                   const std::string& signal,
                                   int gain,
                                   bool gaussianNoise,
                                   const std::string& id,
                                   const std::optional<double>& centralFrequency = {}) :
    CommandResult(CmdName, TargetId)
  {

    setOutput(output);
    setMinRate(minRate);
    setMaxRate(maxRate);
    setBand(band);
    setSignal(signal);
    setGain(gain);
    setGaussianNoise(gaussianNoise);
    setId(id);
    setCentralFrequency(centralFrequency);
  }

  GetModulationTargetSignalsResult(CommandBasePtr relatedCommand,
                                   int output,
                                   int minRate,
                                   int maxRate,
                                   const std::string& band,
                                   const std::string& signal,
                                   int gain,
                                   bool gaussianNoise,
                                   const std::string& id,
                                   const std::optional<double>& centralFrequency = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setOutput(output);
    setMinRate(minRate);
    setMaxRate(maxRate);
    setBand(band);
    setSignal(signal);
    setGain(gain);
    setGaussianNoise(gaussianNoise);
    setId(id);
    setCentralFrequency(centralFrequency);
  }

  static GetModulationTargetSignalsResultPtr create(int output,
                                                    int minRate,
                                                    int maxRate,
                                                    const std::string& band,
                                                    const std::string& signal,
                                                    int gain,
                                                    bool gaussianNoise,
                                                    const std::string& id,
                                                    const std::optional<double>& centralFrequency = {})
  {
    return std::make_shared<GetModulationTargetSignalsResult>(output,
                                                              minRate,
                                                              maxRate,
                                                              band,
                                                              signal,
                                                              gain,
                                                              gaussianNoise,
                                                              id,
                                                              centralFrequency);
  }

  static GetModulationTargetSignalsResultPtr create(CommandBasePtr relatedCommand,
                                                    int output,
                                                    int minRate,
                                                    int maxRate,
                                                    const std::string& band,
                                                    const std::string& signal,
                                                    int gain,
                                                    bool gaussianNoise,
                                                    const std::string& id,
                                                    const std::optional<double>& centralFrequency = {})
  {
    return std::make_shared<GetModulationTargetSignalsResult>(relatedCommand,
                                                              output,
                                                              minRate,
                                                              maxRate,
                                                              band,
                                                              signal,
                                                              gain,
                                                              gaussianNoise,
                                                              id,
                                                              centralFrequency);
  }

  static GetModulationTargetSignalsResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetModulationTargetSignalsResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Output"]) &&
           parse_json<int>::is_valid(m_values["MinRate"]) && parse_json<int>::is_valid(m_values["MaxRate"]) &&
           parse_json<std::string>::is_valid(m_values["Band"]) &&
           parse_json<std::string>::is_valid(m_values["Signal"]) && parse_json<int>::is_valid(m_values["Gain"]) &&
           parse_json<bool>::is_valid(m_values["GaussianNoise"]) && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<std::optional<double>>::is_valid(m_values["CentralFrequency"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Output", "MinRate", "MaxRate", "Band", "Signal", "Gain", "GaussianNoise", "Id", "CentralFrequency"};
    return names;
  }

  int output() const { return parse_json<int>::parse(m_values["Output"]); }

  void setOutput(int output)
  {
    m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int minRate() const { return parse_json<int>::parse(m_values["MinRate"]); }

  void setMinRate(int minRate)
  {
    m_values.AddMember("MinRate", parse_json<int>::format(minRate, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int maxRate() const { return parse_json<int>::parse(m_values["MaxRate"]); }

  void setMaxRate(int maxRate)
  {
    m_values.AddMember("MaxRate", parse_json<int>::format(maxRate, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string band() const { return parse_json<std::string>::parse(m_values["Band"]); }

  void setBand(const std::string& band)
  {
    m_values.AddMember("Band", parse_json<std::string>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int gain() const { return parse_json<int>::parse(m_values["Gain"]); }

  void setGain(int gain)
  {
    m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool gaussianNoise() const { return parse_json<bool>::parse(m_values["GaussianNoise"]); }

  void setGaussianNoise(bool gaussianNoise)
  {
    m_values.AddMember("GaussianNoise",
                       parse_json<bool>::format(gaussianNoise, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<double> centralFrequency() const
  {
    return parse_json<std::optional<double>>::parse(m_values["CentralFrequency"]);
  }

  void setCentralFrequency(const std::optional<double>& centralFrequency)
  {
    m_values.AddMember("CentralFrequency",
                       parse_json<std::optional<double>>::format(centralFrequency, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetModulationTargetSignalsResult);
} // namespace Cmd
} // namespace Sdx
