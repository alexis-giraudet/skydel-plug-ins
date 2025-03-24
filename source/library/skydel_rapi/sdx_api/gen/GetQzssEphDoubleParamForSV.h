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
/// Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use
/// GetConstellationParameterForSV.
///
/// Get various parameters in the QZSS ephemeris.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int The
/// satellite's SV ID 1..10 (use 0 to apply to all satellites) ParamName   string          In meters:  "Crs", "Crc"
///                             In radians: "Cis", "Cic", "Cus", "Cuc"
///                             In seconds: "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
/// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is
/// used.
///

class GetQzssEphDoubleParamForSV;
typedef std::shared_ptr<GetQzssEphDoubleParamForSV> GetQzssEphDoubleParamForSVPtr;

class GetQzssEphDoubleParamForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetQzssEphDoubleParamForSV";
  inline static const char* const Documentation =
    "Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
    "\n"
    "Get various parameters in the QZSS ephemeris.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             The satellite's SV ID 1..10 (use 0 to apply to all satellites)\n"
    "ParamName   string          In meters:  \"Crs\", \"Crc\"\n"
    "                            In radians: \"Cis\", \"Cic\", \"Cus\", \"Cuc\"\n"
    "                            In seconds: \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command GetQzssEphDoubleParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";

  GetQzssEphDoubleParamForSV() : CommandBase(CmdName, TargetId) {}

  GetQzssEphDoubleParamForSV(int svId,
                             const std::string& paramName,
                             const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setParamName(paramName);
    setDataSetName(dataSetName);
  }

  static GetQzssEphDoubleParamForSVPtr create(int svId,
                                              const std::string& paramName,
                                              const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetQzssEphDoubleParamForSV>(svId, paramName, dataSetName);
  }

  static GetQzssEphDoubleParamForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetQzssEphDoubleParamForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::string>::is_valid(m_values["ParamName"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"};
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
REGISTER_COMMAND_TO_FACTORY(GetQzssEphDoubleParamForSV);
} // namespace Cmd
} // namespace Sdx
