#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetPseudorangeNoiseSineWaveForSV.
///
/// Name      Type   Description
/// --------- ------ --------------------------------------------------------------------------
/// System    string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId      int    The satellite's SV ID
/// SineWave  int    Sine wave number (0 or 1)
/// Enabled   bool   If true, sine wave is enabled
/// Amplitude double Sine wave amplitude in meters
/// Period    int    Sine wave period in seconds (minimum 3 seconds)
/// Offset    double Phase offset in radians
///

class GetPseudorangeNoiseSineWaveForSVResult;
typedef std::shared_ptr<GetPseudorangeNoiseSineWaveForSVResult> GetPseudorangeNoiseSineWaveForSVResultPtr;

class GetPseudorangeNoiseSineWaveForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetPseudorangeNoiseSineWaveForSVResult";
  inline static const char* const Documentation =
    "Result of GetPseudorangeNoiseSineWaveForSV.\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ --------------------------------------------------------------------------\n"
    "System    string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId      int    The satellite's SV ID\n"
    "SineWave  int    Sine wave number (0 or 1)\n"
    "Enabled   bool   If true, sine wave is enabled\n"
    "Amplitude double Sine wave amplitude in meters\n"
    "Period    int    Sine wave period in seconds (minimum 3 seconds)\n"
    "Offset    double Phase offset in radians";
  inline static const char* const TargetId = "";

  GetPseudorangeNoiseSineWaveForSVResult() : CommandResult(CmdName, TargetId) {}

  GetPseudorangeNoiseSineWaveForSVResult(const std::string& system,
                                         int svId,
                                         int sineWave,
                                         bool enabled,
                                         double amplitude,
                                         int period,
                                         double offset) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setSineWave(sineWave);
    setEnabled(enabled);
    setAmplitude(amplitude);
    setPeriod(period);
    setOffset(offset);
  }

  GetPseudorangeNoiseSineWaveForSVResult(CommandBasePtr relatedCommand,
                                         const std::string& system,
                                         int svId,
                                         int sineWave,
                                         bool enabled,
                                         double amplitude,
                                         int period,
                                         double offset) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setSineWave(sineWave);
    setEnabled(enabled);
    setAmplitude(amplitude);
    setPeriod(period);
    setOffset(offset);
  }

  static GetPseudorangeNoiseSineWaveForSVResultPtr
  create(const std::string& system, int svId, int sineWave, bool enabled, double amplitude, int period, double offset)
  {
    return std::make_shared<GetPseudorangeNoiseSineWaveForSVResult>(system,
                                                                    svId,
                                                                    sineWave,
                                                                    enabled,
                                                                    amplitude,
                                                                    period,
                                                                    offset);
  }

  static GetPseudorangeNoiseSineWaveForSVResultPtr create(CommandBasePtr relatedCommand,
                                                          const std::string& system,
                                                          int svId,
                                                          int sineWave,
                                                          bool enabled,
                                                          double amplitude,
                                                          int period,
                                                          double offset)
  {
    return std::make_shared<GetPseudorangeNoiseSineWaveForSVResult>(relatedCommand,
                                                                    system,
                                                                    svId,
                                                                    sineWave,
                                                                    enabled,
                                                                    amplitude,
                                                                    period,
                                                                    offset);
  }

  static GetPseudorangeNoiseSineWaveForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<int>::is_valid(m_values["SineWave"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]) && parse_json<double>::is_valid(m_values["Amplitude"]) &&
           parse_json<int>::is_valid(m_values["Period"]) && parse_json<double>::is_valid(m_values["Offset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"System", "SvId", "SineWave", "Enabled", "Amplitude", "Period", "Offset"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int sineWave() const { return parse_json<int>::parse(m_values["SineWave"]); }

  void setSineWave(int sineWave)
  {
    m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double amplitude() const { return parse_json<double>::parse(m_values["Amplitude"]); }

  void setAmplitude(double amplitude)
  {
    m_values.AddMember("Amplitude",
                       parse_json<double>::format(amplitude, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int period() const { return parse_json<int>::parse(m_values["Period"]); }

  void setPeriod(int period)
  {
    m_values.AddMember("Period", parse_json<int>::format(period, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double offset() const { return parse_json<double>::parse(m_values["Offset"]); }

  void setOffset(double offset)
  {
    m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetPseudorangeNoiseSineWaveForSVResult);
} // namespace Cmd
} // namespace Sdx
