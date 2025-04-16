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
/// Please note the command SetQzssEphDoubleParamForSV is deprecated since 23.11. You may use
/// SetConstellationParameterForSV.
///
/// Set various parameters in the QZSS ephemeris.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int The
/// satellite's SV ID 1..10 (use 0 to apply to all satellites) ParamName   string          In meters:  "Crs", "Crc"
///                             In radians: "Cis", "Cic", "Cus", "Cuc"
///                             In seconds: "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
/// Val         double          Parameter value (see ParamName above for unit)
/// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is
/// used.
///

class SetQzssEphDoubleParamForSV;
typedef std::shared_ptr<SetQzssEphDoubleParamForSV> SetQzssEphDoubleParamForSVPtr;

class SetQzssEphDoubleParamForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetQzssEphDoubleParamForSV";
  inline static const char* const Documentation =
    "Please note the command SetQzssEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.\n"
    "\n"
    "Set various parameters in the QZSS ephemeris.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)\n"
    "ParamName   string          In meters:  \"Crs\", \"Crc\"\n"
    "                            In radians: \"Cis\", \"Cic\", \"Cus\", \"Cuc\"\n"
    "                            In seconds: \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
    "Val         double          Parameter value (see ParamName above for unit)\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command SetQzssEphDoubleParamForSV is deprecated since 23.11. You may use SetConstellationParameterForSV.";

  SetQzssEphDoubleParamForSV() : CommandBase(CmdName, TargetId) {}

  SetQzssEphDoubleParamForSV(int svId,
                             const std::string& paramName,
                             double val,
                             const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setParamName(paramName);
    setVal(val);
    setDataSetName(dataSetName);
  }

  static SetQzssEphDoubleParamForSVPtr create(int svId,
                                              const std::string& paramName,
                                              double val,
                                              const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetQzssEphDoubleParamForSV>(svId, paramName, val, dataSetName);
  }

  static SetQzssEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetQzssEphDoubleParamForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::string>::is_valid(m_values["ParamName"]) && parse_json<double>::is_valid(m_values["Val"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"};
    return names;
  }

  std::optional<std::string> deprecated() const { return std::optional<std::string> {Deprecated}; }

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
REGISTER_COMMAND_TO_FACTORY(SetQzssEphDoubleParamForSV);
} // namespace Cmd
} // namespace Sdx
