#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command SetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use
/// SetPseudorangeNoiseSineWaveForEachSV.
///
/// Set the satellite pseudorange noise sine wave attributes for all satellites.
///
/// Name      Type         Description
/// --------- ------------ --------------------------------------------------------------------------
/// System    string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SineWave  int          Sine wave number (0 or 1)
/// Enabled   array bool   If true, sine wave is enabled
/// Amplitude array double Sine wave amplitude in meters
/// Period    array int    sine wave period in seconds
/// Offset    array double Phase offset in radians
///

class SetAllSatellitesPseudorangeNoiseSineWave;
typedef std::shared_ptr<SetAllSatellitesPseudorangeNoiseSineWave> SetAllSatellitesPseudorangeNoiseSineWavePtr;

class SetAllSatellitesPseudorangeNoiseSineWave : public CommandBase
{
public:
  inline static const char* const CmdName = "SetAllSatellitesPseudorangeNoiseSineWave";
  inline static const char* const Documentation =
    "Please note the command SetAllSatellitesPseudorangeNoiseSineWave is deprecated since 21.3. You may use SetPseudorangeNoiseSineWaveForEachSV.\n"
    "\n"
    "Set the satellite pseudorange noise sine wave attributes for all satellites.\n"
    "\n"
    "Name      Type         Description\n"
    "--------- ------------ --------------------------------------------------------------------------\n"
    "System    string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SineWave  int          Sine wave number (0 or 1)\n"
    "Enabled   array bool   If true, sine wave is enabled\n"
    "Amplitude array double Sine wave amplitude in meters\n"
    "Period    array int    sine wave period in seconds\n"
    "Offset    array double Phase offset in radians";
  inline static const char* const TargetId = "";

  SetAllSatellitesPseudorangeNoiseSineWave() : CommandBase(CmdName, TargetId) {}

  SetAllSatellitesPseudorangeNoiseSineWave(const std::string& system,
                                           int sineWave,
                                           const std::vector<bool>& enabled,
                                           const std::vector<double>& amplitude,
                                           const std::vector<int>& period,
                                           const std::vector<double>& offset) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSineWave(sineWave);
    setEnabled(enabled);
    setAmplitude(amplitude);
    setPeriod(period);
    setOffset(offset);
  }

  static SetAllSatellitesPseudorangeNoiseSineWavePtr create(const std::string& system,
                                                            int sineWave,
                                                            const std::vector<bool>& enabled,
                                                            const std::vector<double>& amplitude,
                                                            const std::vector<int>& period,
                                                            const std::vector<double>& offset)
  {
    return std::make_shared<SetAllSatellitesPseudorangeNoiseSineWave>(system,
                                                                      sineWave,
                                                                      enabled,
                                                                      amplitude,
                                                                      period,
                                                                      offset);
  }

  static SetAllSatellitesPseudorangeNoiseSineWavePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetAllSatellitesPseudorangeNoiseSineWave>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SineWave"]) &&
           parse_json<std::vector<bool>>::is_valid(m_values["Enabled"]) &&
           parse_json<std::vector<double>>::is_valid(m_values["Amplitude"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["Period"]) &&
           parse_json<std::vector<double>>::is_valid(m_values["Offset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SineWave", "Enabled", "Amplitude", "Period", "Offset"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int sineWave() const { return parse_json<int>::parse(m_values["SineWave"]); }

  void setSineWave(int sineWave)
  {
    m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::vector<bool> enabled() const { return parse_json<std::vector<bool>>::parse(m_values["Enabled"]); }

  void setEnabled(const std::vector<bool>& enabled)
  {
    m_values.AddMember("Enabled",
                       parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<double> amplitude() const { return parse_json<std::vector<double>>::parse(m_values["Amplitude"]); }

  void setAmplitude(const std::vector<double>& amplitude)
  {
    m_values.AddMember("Amplitude",
                       parse_json<std::vector<double>>::format(amplitude, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<int> period() const { return parse_json<std::vector<int>>::parse(m_values["Period"]); }

  void setPeriod(const std::vector<int>& period)
  {
    m_values.AddMember("Period",
                       parse_json<std::vector<int>>::format(period, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<double> offset() const { return parse_json<std::vector<double>>::parse(m_values["Offset"]); }

  void setOffset(const std::vector<double>& offset)
  {
    m_values.AddMember("Offset",
                       parse_json<std::vector<double>>::format(offset, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetAllSatellitesPseudorangeNoiseSineWave);
} // namespace Cmd
} // namespace Sdx
