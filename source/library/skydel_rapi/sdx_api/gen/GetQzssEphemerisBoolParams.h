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
/// Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use
/// GetQzssEphBoolParamForEachSV.
///
/// Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use
/// GetConstellationParameterForSV.
///
/// Get QZSS ephemeris boolean parameter value for all satellites
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- ParamName   string Refer
/// to SetQzssEphemerisBoolParam for accepted names DataSetName optional string Optional name of the data set to use. If
/// no value is provided, the active data set is used.
///

class GetQzssEphemerisBoolParams;
typedef std::shared_ptr<GetQzssEphemerisBoolParams> GetQzssEphemerisBoolParamsPtr;

class GetQzssEphemerisBoolParams : public CommandBase
{
public:
  inline static const char* const CmdName = "GetQzssEphemerisBoolParams";
  inline static const char* const Documentation =
    "Please note the command GetQzssEphemerisBoolParams is deprecated since 21.3. You may use GetQzssEphBoolParamForEachSV.\n"
    "\n"
    "Please note the command GetQzssEphBoolParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
    "\n"
    "Get QZSS ephemeris boolean parameter value for all satellites\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command GetQzssEphemerisBoolParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

  GetQzssEphemerisBoolParams() : CommandBase(CmdName, TargetId) {}

  GetQzssEphemerisBoolParams(const std::string& paramName, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setParamName(paramName);
    setDataSetName(dataSetName);
  }

  static GetQzssEphemerisBoolParamsPtr create(const std::string& paramName,
                                              const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetQzssEphemerisBoolParams>(paramName, dataSetName);
  }

  static GetQzssEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetQzssEphemerisBoolParams>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetQzssEphemerisBoolParams);
} // namespace Cmd
} // namespace Sdx
