#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"
#include "gen/AlmanacSVData.h"

namespace Sdx
{
namespace Cmd
{
///
/// Push a block of data defining the orbit, clock, and other parameters for one SV.
///   ParamName           Unit
///   "Time of ephemeris" sec (of GPS week)
///   "Week Number"       week
///   "Transmission Time" sec (of GPS week)
///   "ClockBias"         sec
///   "ClockDrift"        sec/sec
///   "ClockDriftRate"    sec/sec^2
///   "DeltaN"            rad/sec
///   "M0"                rad
///   "Eccentricity"      -
///   "SqrtA"             sqrt(meter)
///   "BigOmega"          rad
///   "I0"                rad
///   "LittleOmega"       rad
///   "BigOmegaDot"       rad/sec
///   "Idot"              rad/sec
///
/// Name    Type                Description
/// ------- ------------------- --------------------------------------------------------
/// System  string              "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR".
/// Toa     datetime            Time of applicability.
/// Almanac array AlmanacSVData Array of almanac data for SVs.
///

class PushDynamicAlmanacData;
typedef std::shared_ptr<PushDynamicAlmanacData> PushDynamicAlmanacDataPtr;

class PushDynamicAlmanacData : public CommandBase
{
public:
  inline static const char* const CmdName = "PushDynamicAlmanacData";
  inline static const char* const Documentation =
    "Push a block of data defining the orbit, clock, and other parameters for one SV.\n"
    "  ParamName           Unit\n"
    "  \"Time of ephemeris\" sec (of GPS week)\n"
    "  \"Week Number\"       week\n"
    "  \"Transmission Time\" sec (of GPS week)\n"
    "  \"ClockBias\"         sec\n"
    "  \"ClockDrift\"        sec/sec\n"
    "  \"ClockDriftRate\"    sec/sec^2\n"
    "  \"DeltaN\"            rad/sec\n"
    "  \"M0\"                rad\n"
    "  \"Eccentricity\"      -\n"
    "  \"SqrtA\"             sqrt(meter)\n"
    "  \"BigOmega\"          rad\n"
    "  \"I0\"                rad\n"
    "  \"LittleOmega\"       rad\n"
    "  \"BigOmegaDot\"       rad/sec\n"
    "  \"Idot\"              rad/sec\n"
    "\n"
    "Name    Type                Description\n"
    "------- ------------------- --------------------------------------------------------\n"
    "System  string              \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
    "Toa     datetime            Time of applicability.\n"
    "Almanac array AlmanacSVData Array of almanac data for SVs.";
  inline static const char* const TargetId = "";

  PushDynamicAlmanacData() : CommandBase(CmdName, TargetId) {}

  PushDynamicAlmanacData(const std::string& system,
                         const Sdx::DateTime& toa,
                         const std::vector<Sdx::AlmanacSVData>& almanac) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setToa(toa);
    setAlmanac(almanac);
  }

  static PushDynamicAlmanacDataPtr create(const std::string& system,
                                          const Sdx::DateTime& toa,
                                          const std::vector<Sdx::AlmanacSVData>& almanac)
  {
    return std::make_shared<PushDynamicAlmanacData>(system, toa, almanac);
  }

  static PushDynamicAlmanacDataPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<PushDynamicAlmanacData>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<Sdx::DateTime>::is_valid(m_values["Toa"]) &&
           parse_json<std::vector<Sdx::AlmanacSVData>>::is_valid(m_values["Almanac"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Toa", "Almanac"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::DateTime toa() const { return parse_json<Sdx::DateTime>::parse(m_values["Toa"]); }

  void setToa(const Sdx::DateTime& toa)
  {
    m_values.AddMember("Toa", parse_json<Sdx::DateTime>::format(toa, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::vector<Sdx::AlmanacSVData> almanac() const
  {
    return parse_json<std::vector<Sdx::AlmanacSVData>>::parse(m_values["Almanac"]);
  }

  void setAlmanac(const std::vector<Sdx::AlmanacSVData>& almanac)
  {
    m_values.AddMember("Almanac",
                       parse_json<std::vector<Sdx::AlmanacSVData>>::format(almanac, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(PushDynamicAlmanacData);
} // namespace Cmd
} // namespace Sdx
