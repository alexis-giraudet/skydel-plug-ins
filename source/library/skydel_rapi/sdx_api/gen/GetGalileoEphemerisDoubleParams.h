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
/// Please note the command GetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use
/// GetGalileoEphDoubleParamForEachSV.
///
/// Please note the command GetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use
/// GetConstellationParameterForSV.
///
/// Get Galileo ephemeris parameter value for all satellites
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- ParamName   string Refer
/// to SetGalileoEphDoubleParamForSV for accepted names DataSetName optional string Optional name of the data set to
/// use. If no value is provided, the active data set is used.
///

class GetGalileoEphemerisDoubleParams;
typedef std::shared_ptr<GetGalileoEphemerisDoubleParams> GetGalileoEphemerisDoubleParamsPtr;

class GetGalileoEphemerisDoubleParams : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGalileoEphemerisDoubleParams";
  inline static const char* const Documentation =
    "Please note the command GetGalileoEphemerisDoubleParams is deprecated since 21.3. You may use GetGalileoEphDoubleParamForEachSV.\n"
    "\n"
    "Please note the command GetGalileoEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
    "\n"
    "Get Galileo ephemeris parameter value for all satellites\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "ParamName   string          Refer to SetGalileoEphDoubleParamForSV for accepted names\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command GetGalileoEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

  GetGalileoEphemerisDoubleParams() : CommandBase(CmdName, TargetId) {}

  GetGalileoEphemerisDoubleParams(const std::string& paramName, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setParamName(paramName);
    setDataSetName(dataSetName);
  }

  static GetGalileoEphemerisDoubleParamsPtr create(const std::string& paramName,
                                                   const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetGalileoEphemerisDoubleParams>(paramName, dataSetName);
  }

  static GetGalileoEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGalileoEphemerisDoubleParams>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ParamName"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ParamName", "DataSetName"};
    return names;
  }

  std::optional<std::string> deprecated() const { return std::optional<std::string> {Deprecated}; }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string paramName() const { return parse_json<std::string>::parse(m_values["ParamName"]); }

  void setParamName(const std::string& paramName)
  {
    m_values.AddMember("ParamName",
                       parse_json<std::string>::format(paramName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<std::string> dataSetName() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
  }

  void setDataSetName(const std::optional<std::string>& dataSetName)
  {
    m_values.AddMember("DataSetName",
                       parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGalileoEphemerisDoubleParams);
} // namespace Cmd
} // namespace Sdx
