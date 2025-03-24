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
/// Get various parameters for GLONASS
///
///   ParamName       Unit               Range          Description
///   "TauC"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time
///   "TauGps"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time
///   "TauN"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time
///   "TLambda"       sec                0..44100       Time of the first ascending node passage
///   "Lambda"        semicircle         +/- 1          Longitude of the first ascending node
///   "DeltaI"        semicircle         +/- 0.067      Correction to the mean value of inclination
///   "Omega"         semicircle         +/- 1          Argument of perigee
///   "Eccentricity"  -                  0..0.03        Eccentricity
///   "DeltaT"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period
///   "DeltaTRate"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period
///
/// Name      Type   Description
/// --------- ------ --------------------------------------------------------------------
/// SvId      int    Satellite SV ID 1..24, or use 0 to apply new value to all satellites
/// ParamName string Parameter name (see table above for accepted names)
///

class GetGlonassEphDoubleParamForSV;
typedef std::shared_ptr<GetGlonassEphDoubleParamForSV> GetGlonassEphDoubleParamForSVPtr;

class GetGlonassEphDoubleParamForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGlonassEphDoubleParamForSV";
  inline static const char* const Documentation =
    "Get various parameters for GLONASS\n"
    "\n"
    "  ParamName       Unit               Range          Description\n"
    "  \"TauC\"          sec                +/- 1          GLONASS time scale correction to UTC(SU) time\n"
    "  \"TauGps\"        day                +/- 1.9x10^-3  Correction to GPS time relative to GLONASS time\n"
    "  \"TauN\"          sec                +/- 1.9x10^-3  Coarse value of satellite time correction to GLONASS time\n"
    "  \"TLambda\"       sec                0..44100       Time of the first ascending node passage\n"
    "  \"Lambda\"        semicircle         +/- 1          Longitude of the first ascending node\n"
    "  \"DeltaI\"        semicircle         +/- 0.067      Correction to the mean value of inclination\n"
    "  \"Omega\"         semicircle         +/- 1          Argument of perigee\n"
    "  \"Eccentricity\"  -                  0..0.03        Eccentricity\n"
    "  \"DeltaT\"        sec/orb. period    +/- 3.6x10^3   Correction to the mean value of Draconian period\n"
    "  \"DeltaTRate\"    sec/orb. period^2  +/- 2^-8       Rate of change of Draconian period\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ --------------------------------------------------------------------\n"
    "SvId      int    Satellite SV ID 1..24, or use 0 to apply new value to all satellites\n"
    "ParamName string Parameter name (see table above for accepted names)";
  inline static const char* const TargetId = "";

  GetGlonassEphDoubleParamForSV() : CommandBase(CmdName, TargetId) {}

  GetGlonassEphDoubleParamForSV(int svId, const std::string& paramName) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setParamName(paramName);
  }

  static GetGlonassEphDoubleParamForSVPtr create(int svId, const std::string& paramName)
  {
    return std::make_shared<GetGlonassEphDoubleParamForSV>(svId, paramName);
  }

  static GetGlonassEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::string>::is_valid(m_values["ParamName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "ParamName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string paramName() const { return parse_json<std::string>::parse(m_values["ParamName"]); }

  void setParamName(const std::string& paramName)
  {
    m_values.AddMember("ParamName",
                       parse_json<std::string>::format(paramName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGlonassEphDoubleParamForSV);
} // namespace Cmd
} // namespace Sdx
