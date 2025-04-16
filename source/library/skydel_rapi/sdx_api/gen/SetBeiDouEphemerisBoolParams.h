#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command SetBeiDouEphemerisBoolParams is deprecated since 21.3. You may use
/// SetBeiDouEphBoolParamForEachSV.
///
/// Please note the command SetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use
/// SetConstellationParameterForSV.
///
/// Set BeiDou ephemeris boolean parameter value for all satellites
///
/// Name        Type            Description
/// ----------- ---------------
/// -------------------------------------------------------------------------------------------------- ParamName string
/// Refer to SetBeiDouEphBoolParamForSV for accepted names Val         array bool      Parameter value for each
/// satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc) DataSetName optional string Optional name
/// of the data set to use. If no value is provided, the active data set is used.
///

class SetBeiDouEphemerisBoolParams;
typedef std::shared_ptr<SetBeiDouEphemerisBoolParams> SetBeiDouEphemerisBoolParamsPtr;

class SetBeiDouEphemerisBoolParams : public CommandBase
{
public:
  inline static const char* const CmdName = "SetBeiDouEphemerisBoolParams";
  inline static const char* const Documentation =
    "Please note the command SetBeiDouEphemerisBoolParams is deprecated since 21.3. You may use SetBeiDouEphBoolParamForEachSV.\n"
    "\n"
    "Please note the command SetBeiDouEphBoolParamForEachSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
    "\n"
    "Set BeiDou ephemeris boolean parameter value for all satellites\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- --------------------------------------------------------------------------------------------------\n"
    "ParamName   string          Refer to SetBeiDouEphBoolParamForSV for accepted names\n"
    "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command SetBeiDouEphemerisBoolParams is deprecated since 23.11. You may use SetConstellationParameterForSV.";

  SetBeiDouEphemerisBoolParams() : CommandBase(CmdName, TargetId) {}

  SetBeiDouEphemerisBoolParams(const std::string& paramName,
                               const std::vector<bool>& val,
                               const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setParamName(paramName);
    setVal(val);
    setDataSetName(dataSetName);
  }

  static SetBeiDouEphemerisBoolParamsPtr create(const std::string& paramName,
                                                const std::vector<bool>& val,
                                                const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetBeiDouEphemerisBoolParams>(paramName, val, dataSetName);
  }

  static SetBeiDouEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetBeiDouEphemerisBoolParams>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ParamName"]) &&
           parse_json<std::vector<bool>>::is_valid(m_values["Val"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"};
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

  std::vector<bool> val() const { return parse_json<std::vector<bool>>::parse(m_values["Val"]); }

  void setVal(const std::vector<bool>& val)
  {
    m_values.AddMember("Val",
                       parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(SetBeiDouEphemerisBoolParams);
} // namespace Cmd
} // namespace Sdx
