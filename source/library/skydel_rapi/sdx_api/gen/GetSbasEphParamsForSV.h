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
/// Get parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)
///
/// Name       Type         Description
/// ---------- ------------ ----------------------------------------------------------------------------
/// SvId       int          The satellite's SV ID
/// ParamArray array string An array of params.
///                         Accepted values are: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z",
///                                              "VelocityX", "VelocityY", "VelocityZ", "AccelerationX",
///                                              "AccelerationY", "AccelerationZ", "Health", "URA" and
///                                              "UraIndex"
///

class GetSbasEphParamsForSV;
typedef std::shared_ptr<GetSbasEphParamsForSV> GetSbasEphParamsForSVPtr;

class GetSbasEphParamsForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSbasEphParamsForSV";
  inline static const char* const Documentation =
    "Get parameters for a SBAS satellite ephemeris (runtime modification only available for health parameter)\n"
    "\n"
    "Name       Type         Description\n"
    "---------- ------------ ----------------------------------------------------------------------------\n"
    "SvId       int          The satellite's SV ID\n"
    "ParamArray array string An array of params.\n"
    "                        Accepted values are: \"ClockBias\", \"RelativeFrequencyBias\", \"X\", \"Y\", \"Z\",\n"
    "                                             \"VelocityX\", \"VelocityY\", \"VelocityZ\", \"AccelerationX\",\n"
    "                                             \"AccelerationY\", \"AccelerationZ\", \"Health\", \"URA\" and\n"
    "                                             \"UraIndex\"";
  inline static const char* const TargetId = "";

  GetSbasEphParamsForSV() : CommandBase(CmdName, TargetId) {}

  GetSbasEphParamsForSV(int svId, const std::vector<std::string>& paramArray) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setParamArray(paramArray);
  }

  static GetSbasEphParamsForSVPtr create(int svId, const std::vector<std::string>& paramArray)
  {
    return std::make_shared<GetSbasEphParamsForSV>(svId, paramArray);
  }

  static GetSbasEphParamsForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasEphParamsForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::vector<std::string>>::is_valid(m_values["ParamArray"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "ParamArray"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::vector<std::string> paramArray() const
  {
    return parse_json<std::vector<std::string>>::parse(m_values["ParamArray"]);
  }

  void setParamArray(const std::vector<std::string>& paramArray)
  {
    m_values.AddMember("ParamArray",
                       parse_json<std::vector<std::string>>::format(paramArray, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSbasEphParamsForSV);
} // namespace Cmd
} // namespace Sdx
