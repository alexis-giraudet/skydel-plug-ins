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
/// Set the specified target and output index to a group of interferences.
/// An interference transmitter is mapped to a specific RF output by using the same Interference Group Number.
/// Skydel tries to keep the sampling rate as low as possible,
/// but it is possible to set constaints with MinRate and MaxRate.
///
/// Name        Type            Description
/// ----------- ---------------
/// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// Output      int             Output index (zero based)
/// MinRate     int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)
/// MaxRate     int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)
/// Group       int             Interference group number [1..16] or 0 for no group
/// CentralFreq double          Central frequency (Hz). Put 0.0 and complete signal list to let Skydel choose
/// automatically the central frequency. Gain        int             The gain associated to this output (dB). As of
/// today, accepted values are 0, 20, 40, 60 and 80. Values at 40 and under are not recommended. Use a negative value to
/// use the default value (60). Id          string          Target identifier Signal      optional string Comma
/// separated signal keys if you want to match central frequency and sampling rate with a particular list of signals.
/// Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1",
/// "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5",
/// "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5"
///

class ChangeModulationTargetInterference;
typedef std::shared_ptr<ChangeModulationTargetInterference> ChangeModulationTargetInterferencePtr;

class ChangeModulationTargetInterference : public CommandBase
{
public:
  inline static const char* const CmdName = "ChangeModulationTargetInterference";
  inline static const char* const Documentation =
    "Set the specified target and output index to a group of interferences.\n"
    "An interference transmitter is mapped to a specific RF output by using the same Interference Group Number.\n"
    "Skydel tries to keep the sampling rate as low as possible,\n"
    "but it is possible to set constaints with MinRate and MaxRate.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "Output      int             Output index (zero based)\n"
    "MinRate     int             Minimum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
    "MaxRate     int             Maximum sampling rate (12500000, 25000000, 50000000, 60000000, 100000000)\n"
    "Group       int             Interference group number [1..16] or 0 for no group\n"
    "CentralFreq double          Central frequency (Hz). Put 0.0 and complete signal list to let Skydel choose automatically the central frequency.\n"
    "Gain        int             The gain associated to this output (dB). As of today, accepted values are 0, 20, 40, 60 and 80. Values at 40 and under are not recommended. Use a negative value to use the default value (60).\n"
    "Id          string          Target identifier\n"
    "Signal      optional string Comma separated signal keys if you want to match central frequency and sampling rate with a particular list of signals. Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"";
  inline static const char* const TargetId = "";

  ChangeModulationTargetInterference() : CommandBase(CmdName, TargetId) {}

  ChangeModulationTargetInterference(int output,
                                     int minRate,
                                     int maxRate,
                                     int group,
                                     double centralFreq,
                                     int gain,
                                     const std::string& id,
                                     const std::optional<std::string>& signal = {}) :
    CommandBase(CmdName, TargetId)
  {

    setOutput(output);
    setMinRate(minRate);
    setMaxRate(maxRate);
    setGroup(group);
    setCentralFreq(centralFreq);
    setGain(gain);
    setId(id);
    setSignal(signal);
  }

  static ChangeModulationTargetInterferencePtr create(int output,
                                                      int minRate,
                                                      int maxRate,
                                                      int group,
                                                      double centralFreq,
                                                      int gain,
                                                      const std::string& id,
                                                      const std::optional<std::string>& signal = {})
  {
    return std::make_shared<ChangeModulationTargetInterference>(output,
                                                                minRate,
                                                                maxRate,
                                                                group,
                                                                centralFreq,
                                                                gain,
                                                                id,
                                                                signal);
  }

  static ChangeModulationTargetInterferencePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ChangeModulationTargetInterference>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Output"]) &&
           parse_json<int>::is_valid(m_values["MinRate"]) && parse_json<int>::is_valid(m_values["MaxRate"]) &&
           parse_json<int>::is_valid(m_values["Group"]) && parse_json<double>::is_valid(m_values["CentralFreq"]) &&
           parse_json<int>::is_valid(m_values["Gain"]) && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Signal"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Output", "MinRate", "MaxRate", "Group", "CentralFreq", "Gain", "Id", "Signal"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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

  int group() const { return parse_json<int>::parse(m_values["Group"]); }

  void setGroup(int group)
  {
    m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double centralFreq() const { return parse_json<double>::parse(m_values["CentralFreq"]); }

  void setCentralFreq(double centralFreq)
  {
    m_values.AddMember("CentralFreq",
                       parse_json<double>::format(centralFreq, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int gain() const { return parse_json<int>::parse(m_values["Gain"]); }

  void setGain(int gain)
  {
    m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<std::string> signal() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["Signal"]);
  }

  void setSignal(const std::optional<std::string>& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::optional<std::string>>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ChangeModulationTargetInterference);
} // namespace Cmd
} // namespace Sdx
