#pragma once

#include <map>
#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/SignalPower.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetAllPowerForSV.
///
/// Name            Type                    Description
/// --------------- -----------------------
/// ----------------------------------------------------------------------------- System          string "GPS",
/// "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR". SvId            int                     The
/// Satellite's SV ID. NominalPower    double                  The nominal power in dBm. GlobalOffset    double The
/// global power offset (dB). SignalPowerDict dict string:SignalPower A dictionary of signal power pairs.
///                                         Accepted keys are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C",
///                                         "L2P",
///                                                            "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
///                                                            "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
///                                                            "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
///                                                            "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
///                                                            "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1"
///                                                            and "PULSARX5"
///

class GetAllPowerForSVResult;
typedef std::shared_ptr<GetAllPowerForSVResult> GetAllPowerForSVResultPtr;

class GetAllPowerForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllPowerForSVResult";
  inline static const char* const Documentation =
    "Result of GetAllPowerForSV.\n"
    "\n"
    "Name            Type                    Description\n"
    "--------------- ----------------------- -----------------------------------------------------------------------------\n"
    "System          string                  \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
    "SvId            int                     The Satellite's SV ID.\n"
    "NominalPower    double                  The nominal power in dBm.\n"
    "GlobalOffset    double                  The global power offset (dB).\n"
    "SignalPowerDict dict string:SignalPower A dictionary of signal power pairs.\n"
    "                                        Accepted keys are: \"All\", \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\",\n"
    "                                                           \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\",\n"
    "                                                           \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
    "                                                           \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
    "                                                           \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
    "                                                           \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and\n"
    "                                                           \"PULSARX5\"";
  inline static const char* const TargetId = "";

  GetAllPowerForSVResult() : CommandResult(CmdName, TargetId) {}

  GetAllPowerForSVResult(const std::string& system,
                         int svId,
                         double nominalPower,
                         double globalOffset,
                         const std::map<std::string, Sdx::SignalPower>& signalPowerDict) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setNominalPower(nominalPower);
    setGlobalOffset(globalOffset);
    setSignalPowerDict(signalPowerDict);
  }

  GetAllPowerForSVResult(CommandBasePtr relatedCommand,
                         const std::string& system,
                         int svId,
                         double nominalPower,
                         double globalOffset,
                         const std::map<std::string, Sdx::SignalPower>& signalPowerDict) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setNominalPower(nominalPower);
    setGlobalOffset(globalOffset);
    setSignalPowerDict(signalPowerDict);
  }

  static GetAllPowerForSVResultPtr create(const std::string& system,
                                          int svId,
                                          double nominalPower,
                                          double globalOffset,
                                          const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
  {
    return std::make_shared<GetAllPowerForSVResult>(system, svId, nominalPower, globalOffset, signalPowerDict);
  }

  static GetAllPowerForSVResultPtr create(CommandBasePtr relatedCommand,
                                          const std::string& system,
                                          int svId,
                                          double nominalPower,
                                          double globalOffset,
                                          const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
  {
    return std::make_shared<GetAllPowerForSVResult>(relatedCommand,
                                                    system,
                                                    svId,
                                                    nominalPower,
                                                    globalOffset,
                                                    signalPowerDict);
  }

  static GetAllPowerForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllPowerForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<double>::is_valid(m_values["NominalPower"]) &&
           parse_json<double>::is_valid(m_values["GlobalOffset"]) &&
           parse_json<std::map<std::string, Sdx::SignalPower>>::is_valid(m_values["SignalPowerDict"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "NominalPower", "GlobalOffset", "SignalPowerDict"};
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

  double nominalPower() const { return parse_json<double>::parse(m_values["NominalPower"]); }

  void setNominalPower(double nominalPower)
  {
    m_values.AddMember("NominalPower",
                       parse_json<double>::format(nominalPower, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double globalOffset() const { return parse_json<double>::parse(m_values["GlobalOffset"]); }

  void setGlobalOffset(double globalOffset)
  {
    m_values.AddMember("GlobalOffset",
                       parse_json<double>::format(globalOffset, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::map<std::string, Sdx::SignalPower> signalPowerDict() const
  {
    return parse_json<std::map<std::string, Sdx::SignalPower>>::parse(m_values["SignalPowerDict"]);
  }

  void setSignalPowerDict(const std::map<std::string, Sdx::SignalPower>& signalPowerDict)
  {
    m_values.AddMember("SignalPowerDict",
                       parse_json<std::map<std::string, Sdx::SignalPower>>::format(signalPowerDict,
                                                                                   m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetAllPowerForSVResult);
} // namespace Cmd
} // namespace Sdx
