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
/// Result of GetMultipathForID.
///
/// Name         Type   Description
/// ------------ ------
/// ------------------------------------------------------------------------------------------------------------- Id
/// string A multipath ID System       string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Signal       string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                           "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1",
///                                           "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S",
///                                           "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL",
///                                           "PULSARX1" and "PULSARX5"
/// SvId         int    The satellite's SV ID
/// PowerLoss    double Power loss in dB (value must be positive)
/// Pseudorange  double Pseudorange offset in meters (value must be positive)
/// Doppler      double Doppler frequency offset in Hz
/// CarrierPhase double Carrier phase offset in radians
/// Echo         int    Echo number [1..5], or use zero to let Skydel assign an echo number.
///

class GetMultipathForIDResult;
typedef std::shared_ptr<GetMultipathForIDResult> GetMultipathForIDResultPtr;

class GetMultipathForIDResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetMultipathForIDResult";
  inline static const char* const Documentation =
    "Result of GetMultipathForID.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ -------------------------------------------------------------------------------------------------------------\n"
    "Id           string A multipath ID\n"
    "System       string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Signal       string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                          \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\",\n"
    "                                          \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
    "                                          \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"\n"
    "SvId         int    The satellite's SV ID\n"
    "PowerLoss    double Power loss in dB (value must be positive)\n"
    "Pseudorange  double Pseudorange offset in meters (value must be positive)\n"
    "Doppler      double Doppler frequency offset in Hz\n"
    "CarrierPhase double Carrier phase offset in radians\n"
    "Echo         int    Echo number [1..5], or use zero to let Skydel assign an echo number.";
  inline static const char* const TargetId = "";

  GetMultipathForIDResult() : CommandResult(CmdName, TargetId) {}

  GetMultipathForIDResult(const std::string& id,
                          const std::string& system,
                          const std::string& signal,
                          int svId,
                          double powerLoss,
                          double pseudorange,
                          double doppler,
                          double carrierPhase,
                          int echo) :
    CommandResult(CmdName, TargetId)
  {

    setId(id);
    setSystem(system);
    setSignal(signal);
    setSvId(svId);
    setPowerLoss(powerLoss);
    setPseudorange(pseudorange);
    setDoppler(doppler);
    setCarrierPhase(carrierPhase);
    setEcho(echo);
  }

  GetMultipathForIDResult(CommandBasePtr relatedCommand,
                          const std::string& id,
                          const std::string& system,
                          const std::string& signal,
                          int svId,
                          double powerLoss,
                          double pseudorange,
                          double doppler,
                          double carrierPhase,
                          int echo) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setId(id);
    setSystem(system);
    setSignal(signal);
    setSvId(svId);
    setPowerLoss(powerLoss);
    setPseudorange(pseudorange);
    setDoppler(doppler);
    setCarrierPhase(carrierPhase);
    setEcho(echo);
  }

  static GetMultipathForIDResultPtr create(const std::string& id,
                                           const std::string& system,
                                           const std::string& signal,
                                           int svId,
                                           double powerLoss,
                                           double pseudorange,
                                           double doppler,
                                           double carrierPhase,
                                           int echo)
  {
    return std::make_shared<GetMultipathForIDResult>(id,
                                                     system,
                                                     signal,
                                                     svId,
                                                     powerLoss,
                                                     pseudorange,
                                                     doppler,
                                                     carrierPhase,
                                                     echo);
  }

  static GetMultipathForIDResultPtr create(CommandBasePtr relatedCommand,
                                           const std::string& id,
                                           const std::string& system,
                                           const std::string& signal,
                                           int svId,
                                           double powerLoss,
                                           double pseudorange,
                                           double doppler,
                                           double carrierPhase,
                                           int echo)
  {
    return std::make_shared<GetMultipathForIDResult>(relatedCommand,
                                                     id,
                                                     system,
                                                     signal,
                                                     svId,
                                                     powerLoss,
                                                     pseudorange,
                                                     doppler,
                                                     carrierPhase,
                                                     echo);
  }

  static GetMultipathForIDResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMultipathForIDResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::string>::is_valid(m_values["Signal"]) && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<double>::is_valid(m_values["PowerLoss"]) &&
           parse_json<double>::is_valid(m_values["Pseudorange"]) && parse_json<double>::is_valid(m_values["Doppler"]) &&
           parse_json<double>::is_valid(m_values["CarrierPhase"]) && parse_json<int>::is_valid(m_values["Echo"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Id", "System", "Signal", "SvId", "PowerLoss", "Pseudorange", "Doppler", "CarrierPhase", "Echo"};
    return names;
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double powerLoss() const { return parse_json<double>::parse(m_values["PowerLoss"]); }

  void setPowerLoss(double powerLoss)
  {
    m_values.AddMember("PowerLoss",
                       parse_json<double>::format(powerLoss, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double pseudorange() const { return parse_json<double>::parse(m_values["Pseudorange"]); }

  void setPseudorange(double pseudorange)
  {
    m_values.AddMember("Pseudorange",
                       parse_json<double>::format(pseudorange, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double doppler() const { return parse_json<double>::parse(m_values["Doppler"]); }

  void setDoppler(double doppler)
  {
    m_values.AddMember("Doppler",
                       parse_json<double>::format(doppler, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double carrierPhase() const { return parse_json<double>::parse(m_values["CarrierPhase"]); }

  void setCarrierPhase(double carrierPhase)
  {
    m_values.AddMember("CarrierPhase",
                       parse_json<double>::format(carrierPhase, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int echo() const { return parse_json<int>::parse(m_values["Echo"]); }

  void setEcho(int echo)
  {
    m_values.AddMember("Echo", parse_json<int>::format(echo, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMultipathForIDResult);
} // namespace Cmd
} // namespace Sdx
