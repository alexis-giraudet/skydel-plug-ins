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
/// Set the satellite pseudorange noise Gauss-Markov process attributes for all satellites.
///
/// Name    Type         Description
/// ------- ------------ --------------------------------------------------------------------------
/// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Process int          Gauss-Markov Process number (0 or 1)
/// Enabled array bool   If true, Gauss-Markov process is enabled
/// Sigma   array double Standard devition
/// Time    array double Time constant
/// Seed    array int    Random seed
///

class SetPseudorangeNoiseGaussMarkovForEachSV;
typedef std::shared_ptr<SetPseudorangeNoiseGaussMarkovForEachSV> SetPseudorangeNoiseGaussMarkovForEachSVPtr;

class SetPseudorangeNoiseGaussMarkovForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPseudorangeNoiseGaussMarkovForEachSV";
  inline static const char* const Documentation =
    "Set the satellite pseudorange noise Gauss-Markov process attributes for all satellites.\n"
    "\n"
    "Name    Type         Description\n"
    "------- ------------ --------------------------------------------------------------------------\n"
    "System  string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Process int          Gauss-Markov Process number (0 or 1)\n"
    "Enabled array bool   If true, Gauss-Markov process is enabled\n"
    "Sigma   array double Standard devition\n"
    "Time    array double Time constant\n"
    "Seed    array int    Random seed";
  inline static const char* const TargetId = "";

  SetPseudorangeNoiseGaussMarkovForEachSV() : CommandBase(CmdName, TargetId) {}

  SetPseudorangeNoiseGaussMarkovForEachSV(const std::string& system,
                                          int process,
                                          const std::vector<bool>& enabled,
                                          const std::vector<double>& sigma,
                                          const std::vector<double>& time,
                                          const std::vector<int>& seed) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setProcess(process);
    setEnabled(enabled);
    setSigma(sigma);
    setTime(time);
    setSeed(seed);
  }

  static SetPseudorangeNoiseGaussMarkovForEachSVPtr create(const std::string& system,
                                                           int process,
                                                           const std::vector<bool>& enabled,
                                                           const std::vector<double>& sigma,
                                                           const std::vector<double>& time,
                                                           const std::vector<int>& seed)
  {
    return std::make_shared<SetPseudorangeNoiseGaussMarkovForEachSV>(system, process, enabled, sigma, time, seed);
  }

  static SetPseudorangeNoiseGaussMarkovForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetPseudorangeNoiseGaussMarkovForEachSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["Process"]) &&
           parse_json<std::vector<bool>>::is_valid(m_values["Enabled"]) &&
           parse_json<std::vector<double>>::is_valid(m_values["Sigma"]) &&
           parse_json<std::vector<double>>::is_valid(m_values["Time"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["Seed"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Process", "Enabled", "Sigma", "Time", "Seed"};
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

  int process() const { return parse_json<int>::parse(m_values["Process"]); }

  void setProcess(int process)
  {
    m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::vector<bool> enabled() const { return parse_json<std::vector<bool>>::parse(m_values["Enabled"]); }

  void setEnabled(const std::vector<bool>& enabled)
  {
    m_values.AddMember("Enabled",
                       parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<double> sigma() const { return parse_json<std::vector<double>>::parse(m_values["Sigma"]); }

  void setSigma(const std::vector<double>& sigma)
  {
    m_values.AddMember("Sigma",
                       parse_json<std::vector<double>>::format(sigma, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<double> time() const { return parse_json<std::vector<double>>::parse(m_values["Time"]); }

  void setTime(const std::vector<double>& time)
  {
    m_values.AddMember("Time",
                       parse_json<std::vector<double>>::format(time, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<int> seed() const { return parse_json<std::vector<int>>::parse(m_values["Seed"]); }

  void setSeed(const std::vector<int>& seed)
  {
    m_values.AddMember("Seed",
                       parse_json<std::vector<int>>::format(seed, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPseudorangeNoiseGaussMarkovForEachSV);
} // namespace Cmd
} // namespace Sdx
