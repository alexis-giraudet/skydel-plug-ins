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
/// Skydel special calibration function, internal use only
///
/// Name          Type   Description
/// ------------- ------
/// ------------------------------------------------------------------------------------------------------------- SvId
/// int    SV ID for GPS, Galileo, BeiDou, GLONASS, QZSS, NavIC, SBAS and PULSAR. Signal        string Accepted signal
/// keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                            "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I",
///                                            "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5",
///                                            "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
///                                            "PULSARXL", "PULSARX1" and "PULSARX5"
/// EnableSV      bool   Enable/Disable multiplication by satellite and Navigation Message
/// EnableDoppler bool   Enable/Disable Doppler Frequency and Phase offset
/// PhaseOffet    double Carrier Phase Offset applied to Line Of Sight
///

class CalibFunction;
typedef std::shared_ptr<CalibFunction> CalibFunctionPtr;

class CalibFunction : public CommandBase
{
public:
  inline static const char* const CmdName = "CalibFunction";
  inline static const char* const Documentation =
    "Skydel special calibration function, internal use only\n"
    "\n"
    "Name          Type   Description\n"
    "------------- ------ -------------------------------------------------------------------------------------------------------------\n"
    "SvId          int    SV ID for GPS, Galileo, BeiDou, GLONASS, QZSS, NavIC, SBAS and PULSAR.\n"
    "Signal        string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                           \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\",\n"
    "                                           \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
    "                                           \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"\n"
    "EnableSV      bool   Enable/Disable multiplication by satellite and Navigation Message\n"
    "EnableDoppler bool   Enable/Disable Doppler Frequency and Phase offset\n"
    "PhaseOffet    double Carrier Phase Offset applied to Line Of Sight";
  inline static const char* const TargetId = "";

  CalibFunction() : CommandBase(CmdName, TargetId) {}

  CalibFunction(int svId, const std::string& signal, bool enableSV, bool enableDoppler, double phaseOffet) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setSignal(signal);
    setEnableSV(enableSV);
    setEnableDoppler(enableDoppler);
    setPhaseOffet(phaseOffet);
  }

  static CalibFunctionPtr create(int svId,
                                 const std::string& signal,
                                 bool enableSV,
                                 bool enableDoppler,
                                 double phaseOffet)
  {
    return std::make_shared<CalibFunction>(svId, signal, enableSV, enableDoppler, phaseOffet);
  }

  static CalibFunctionPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<CalibFunction>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::string>::is_valid(m_values["Signal"]) && parse_json<bool>::is_valid(m_values["EnableSV"]) &&
           parse_json<bool>::is_valid(m_values["EnableDoppler"]) &&
           parse_json<double>::is_valid(m_values["PhaseOffet"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Signal", "EnableSV", "EnableDoppler", "PhaseOffet"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool enableSV() const { return parse_json<bool>::parse(m_values["EnableSV"]); }

  void setEnableSV(bool enableSV)
  {
    m_values.AddMember("EnableSV",
                       parse_json<bool>::format(enableSV, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool enableDoppler() const { return parse_json<bool>::parse(m_values["EnableDoppler"]); }

  void setEnableDoppler(bool enableDoppler)
  {
    m_values.AddMember("EnableDoppler",
                       parse_json<bool>::format(enableDoppler, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phaseOffet() const { return parse_json<double>::parse(m_values["PhaseOffet"]); }

  void setPhaseOffet(double phaseOffet)
  {
    m_values.AddMember("PhaseOffet",
                       parse_json<double>::format(phaseOffet, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(CalibFunction);
} // namespace Cmd
} // namespace Sdx
