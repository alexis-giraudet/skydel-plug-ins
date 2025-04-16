#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetGlonassEphDoubleParamForEachSV.
///
/// Name      Type         Description
/// --------- ------------
/// -------------------------------------------------------------------------------------------------- ParamName string
/// Refer to SetGlonassEphDoubleParamForSV for accepted names Val       array double Parameter value for each satellite.
/// Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
///

class GetGlonassEphDoubleParamForEachSVResult;
typedef std::shared_ptr<GetGlonassEphDoubleParamForEachSVResult> GetGlonassEphDoubleParamForEachSVResultPtr;
typedef GetGlonassEphDoubleParamForEachSVResult GetGlonassDoubleParamsResult;
typedef std::shared_ptr<GetGlonassDoubleParamsResult> GetGlonassDoubleParamsResultPtr;

class GetGlonassEphDoubleParamForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetGlonassEphDoubleParamForEachSVResult";
  inline static const char* const Documentation =
    "Result of GetGlonassEphDoubleParamForEachSV.\n"
    "\n"
    "Name      Type         Description\n"
    "--------- ------------ --------------------------------------------------------------------------------------------------\n"
    "ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names\n"
    "Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
  inline static const char* const TargetId = "";

  GetGlonassEphDoubleParamForEachSVResult() : CommandResult(CmdName, TargetId) {}

  GetGlonassEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val) :
    CommandResult(CmdName, TargetId)
  {

    setParamName(paramName);
    setVal(val);
  }

  GetGlonassEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand,
                                          const std::string& paramName,
                                          const std::vector<double>& val) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setParamName(paramName);
    setVal(val);
  }

  static GetGlonassEphDoubleParamForEachSVResultPtr create(const std::string& paramName, const std::vector<double>& val)
  {
    return std::make_shared<GetGlonassEphDoubleParamForEachSVResult>(paramName, val);
  }

  static GetGlonassEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand,
                                                           const std::string& paramName,
                                                           const std::vector<double>& val)
  {
    return std::make_shared<GetGlonassEphDoubleParamForEachSVResult>(relatedCommand, paramName, val);
  }

  static GetGlonassEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForEachSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ParamName"]) &&
           parse_json<std::vector<double>>::is_valid(m_values["Val"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ParamName", "Val"};
    return names;
  }

  std::string paramName() const { return parse_json<std::string>::parse(m_values["ParamName"]); }

  void setParamName(const std::string& paramName)
  {
    m_values.AddMember("ParamName",
                       parse_json<std::string>::format(paramName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<double> val() const { return parse_json<std::vector<double>>::parse(m_values["Val"]); }

  void setVal(const std::vector<double>& val)
  {
    m_values.AddMember("Val",
                       parse_json<std::vector<double>>::format(val, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGlonassEphDoubleParamForEachSVResult);
} // namespace Cmd
} // namespace Sdx
