#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetQzssEphDoubleParamForSV.
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

class GetQzssEphDoubleParamForSVResult;
typedef std::shared_ptr<GetQzssEphDoubleParamForSVResult> GetQzssEphDoubleParamForSVResultPtr;
typedef GetQzssEphDoubleParamForSVResult GetQzssEphemerisDoubleParamResult;
typedef std::shared_ptr<GetQzssEphemerisDoubleParamResult> GetQzssEphemerisDoubleParamResultPtr;

class GetQzssEphDoubleParamForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetQzssEphDoubleParamForSVResult";
  inline static const char* const Documentation =
    "Result of GetQzssEphDoubleParamForSV.\n"
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

  GetQzssEphDoubleParamForSVResult() : CommandResult(CmdName, TargetId) {}

  GetQzssEphDoubleParamForSVResult(int svId,
                                   const std::string& paramName,
                                   double val,
                                   const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setParamName(paramName);
    setVal(val);
    setDataSetName(dataSetName);
  }

  GetQzssEphDoubleParamForSVResult(CommandBasePtr relatedCommand,
                                   int svId,
                                   const std::string& paramName,
                                   double val,
                                   const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setParamName(paramName);
    setVal(val);
    setDataSetName(dataSetName);
  }

  static GetQzssEphDoubleParamForSVResultPtr create(int svId,
                                                    const std::string& paramName,
                                                    double val,
                                                    const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetQzssEphDoubleParamForSVResult>(svId, paramName, val, dataSetName);
  }

  static GetQzssEphDoubleParamForSVResultPtr create(CommandBasePtr relatedCommand,
                                                    int svId,
                                                    const std::string& paramName,
                                                    double val,
                                                    const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetQzssEphDoubleParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
  }

  static GetQzssEphDoubleParamForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetQzssEphDoubleParamForSVResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetQzssEphDoubleParamForSVResult);
} // namespace Cmd
} // namespace Sdx
