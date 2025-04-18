#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/RIC.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetEphemerisErrorForSV.
///
/// Name     Type   Description
/// -------- ------ -----------------------------------------------------------------------------------
/// System   string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// SvId     int    Satellite SV ID.
/// Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.
/// DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.
/// DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.
///

class GetEphemerisErrorForSVResult;
typedef std::shared_ptr<GetEphemerisErrorForSVResult> GetEphemerisErrorForSVResultPtr;

class GetEphemerisErrorForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetEphemerisErrorForSVResult";
  inline static const char* const Documentation =
    "Result of GetEphemerisErrorForSV.\n"
    "\n"
    "Name     Type   Description\n"
    "-------- ------ -----------------------------------------------------------------------------------\n"
    "System   string \"GPS\", \"Galileo\", \"GLONASS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId     int    Satellite SV ID.\n"
    "Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.\n"
    "DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.\n"
    "DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.";
  inline static const char* const TargetId = "";

  GetEphemerisErrorForSVResult() : CommandResult(CmdName, TargetId) {}

  GetEphemerisErrorForSVResult(const std::string& system,
                               int svId,
                               const Sdx::RIC& orbit,
                               double deltaAf0,
                               double deltaAf1) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setOrbit(orbit);
    setDeltaAf0(deltaAf0);
    setDeltaAf1(deltaAf1);
  }

  GetEphemerisErrorForSVResult(CommandBasePtr relatedCommand,
                               const std::string& system,
                               int svId,
                               const Sdx::RIC& orbit,
                               double deltaAf0,
                               double deltaAf1) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setOrbit(orbit);
    setDeltaAf0(deltaAf0);
    setDeltaAf1(deltaAf1);
  }

  static GetEphemerisErrorForSVResultPtr create(const std::string& system,
                                                int svId,
                                                const Sdx::RIC& orbit,
                                                double deltaAf0,
                                                double deltaAf1)
  {
    return std::make_shared<GetEphemerisErrorForSVResult>(system, svId, orbit, deltaAf0, deltaAf1);
  }

  static GetEphemerisErrorForSVResultPtr create(CommandBasePtr relatedCommand,
                                                const std::string& system,
                                                int svId,
                                                const Sdx::RIC& orbit,
                                                double deltaAf0,
                                                double deltaAf1)
  {
    return std::make_shared<GetEphemerisErrorForSVResult>(relatedCommand, system, svId, orbit, deltaAf0, deltaAf1);
  }

  static GetEphemerisErrorForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEphemerisErrorForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<Sdx::RIC>::is_valid(m_values["Orbit"]) &&
           parse_json<double>::is_valid(m_values["DeltaAf0"]) && parse_json<double>::is_valid(m_values["DeltaAf1"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "Orbit", "DeltaAf0", "DeltaAf1"};
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

  Sdx::RIC orbit() const { return parse_json<Sdx::RIC>::parse(m_values["Orbit"]); }

  void setOrbit(const Sdx::RIC& orbit)
  {
    m_values.AddMember("Orbit", parse_json<Sdx::RIC>::format(orbit, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double deltaAf0() const { return parse_json<double>::parse(m_values["DeltaAf0"]); }

  void setDeltaAf0(double deltaAf0)
  {
    m_values.AddMember("DeltaAf0",
                       parse_json<double>::format(deltaAf0, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double deltaAf1() const { return parse_json<double>::parse(m_values["DeltaAf1"]); }

  void setDeltaAf1(double deltaAf1)
  {
    m_values.AddMember("DeltaAf1",
                       parse_json<double>::format(deltaAf1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetEphemerisErrorForSVResult);
} // namespace Cmd
} // namespace Sdx
