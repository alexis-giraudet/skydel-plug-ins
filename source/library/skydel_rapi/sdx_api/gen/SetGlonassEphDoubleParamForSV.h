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
/// Set various parameters for GLONASS
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
/// Val       double Parameter value (see table above for unit)
///

class SetGlonassEphDoubleParamForSV;
typedef std::shared_ptr<SetGlonassEphDoubleParamForSV> SetGlonassEphDoubleParamForSVPtr;

class SetGlonassEphDoubleParamForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetGlonassEphDoubleParamForSV";
  inline static const char* const Documentation =
    "Set various parameters for GLONASS\n"
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
    "ParamName string Parameter name (see table above for accepted names)\n"
    "Val       double Parameter value (see table above for unit)";
  inline static const char* const TargetId = "";

  SetGlonassEphDoubleParamForSV() : CommandBase(CmdName, TargetId) {}

  SetGlonassEphDoubleParamForSV(int svId, const std::string& paramName, double val) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setParamName(paramName);
    setVal(val);
  }

  static SetGlonassEphDoubleParamForSVPtr create(int svId, const std::string& paramName, double val)
  {
    return std::make_shared<SetGlonassEphDoubleParamForSV>(svId, paramName, val);
  }

  static SetGlonassEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetGlonassEphDoubleParamForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::string>::is_valid(m_values["ParamName"]) && parse_json<double>::is_valid(m_values["Val"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "ParamName", "Val"};
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

  double val() const { return parse_json<double>::parse(m_values["Val"]); }

  void setVal(double val)
  {
    m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetGlonassEphDoubleParamForSV);
} // namespace Cmd
} // namespace Sdx
