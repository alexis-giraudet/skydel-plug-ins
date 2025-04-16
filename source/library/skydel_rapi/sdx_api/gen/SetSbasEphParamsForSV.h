#pragma once

#include <map>
#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)
///
/// Name           Type               Description
/// -------------- ------------------ --------------------------------------------------------------------------
/// SvId           int                The satellite's SV ID
/// ParamValueDict dict string:double A dictionary of param value pairs.
///                                   Accepted keys are: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z",
///                                                      "VelocityX", "VelocityY", "VelocityZ", "AccelerationX",
///                                                      "AccelerationY", "AccelerationZ", "Health", "URA" and
///                                                      "UraIndex"
///

class SetSbasEphParamsForSV;
typedef std::shared_ptr<SetSbasEphParamsForSV> SetSbasEphParamsForSVPtr;

class SetSbasEphParamsForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSbasEphParamsForSV";
  inline static const char* const Documentation =
    "Set parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)\n"
    "\n"
    "Name           Type               Description\n"
    "-------------- ------------------ --------------------------------------------------------------------------\n"
    "SvId           int                The satellite's SV ID\n"
    "ParamValueDict dict string:double A dictionary of param value pairs.\n"
    "                                  Accepted keys are: \"ClockBias\", \"RelativeFrequencyBias\", \"X\", \"Y\", \"Z\",\n"
    "                                                     \"VelocityX\", \"VelocityY\", \"VelocityZ\", \"AccelerationX\",\n"
    "                                                     \"AccelerationY\", \"AccelerationZ\", \"Health\", \"URA\" and\n"
    "                                                     \"UraIndex\"";
  inline static const char* const TargetId = "";

  SetSbasEphParamsForSV() : CommandBase(CmdName, TargetId) {}

  SetSbasEphParamsForSV(int svId, const std::map<std::string, double>& paramValueDict) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setParamValueDict(paramValueDict);
  }

  static SetSbasEphParamsForSVPtr create(int svId, const std::map<std::string, double>& paramValueDict)
  {
    return std::make_shared<SetSbasEphParamsForSV>(svId, paramValueDict);
  }

  static SetSbasEphParamsForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSbasEphParamsForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "ParamValueDict"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::map<std::string, double> paramValueDict() const
  {
    return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
  }

  void setParamValueDict(const std::map<std::string, double>& paramValueDict)
  {
    m_values.AddMember("ParamValueDict",
                       parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSbasEphParamsForSV);
} // namespace Cmd
} // namespace Sdx
