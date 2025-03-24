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
/// Please note the command SetGlonassDoubleParams is deprecated since 21.3. You may use
/// SetGlonassEphDoubleParamForEachSV.
///
/// Set GLONASS parameter value for all satellites
///
/// Name      Type         Description
/// --------- ------------
/// -------------------------------------------------------------------------------------------------- ParamName string
/// Refer to SetGlonassEphDoubleParamForSV for accepted names Val       array double Parameter value for each satellite.
/// Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
///

class SetGlonassDoubleParams;
typedef std::shared_ptr<SetGlonassDoubleParams> SetGlonassDoubleParamsPtr;

class SetGlonassDoubleParams : public CommandBase
{
public:
  inline static const char* const CmdName = "SetGlonassDoubleParams";
  inline static const char* const Documentation =
    "Please note the command SetGlonassDoubleParams is deprecated since 21.3. You may use SetGlonassEphDoubleParamForEachSV.\n"
    "\n"
    "Set GLONASS parameter value for all satellites\n"
    "\n"
    "Name      Type         Description\n"
    "--------- ------------ --------------------------------------------------------------------------------------------------\n"
    "ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names\n"
    "Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
  inline static const char* const TargetId = "";

  SetGlonassDoubleParams() : CommandBase(CmdName, TargetId) {}

  SetGlonassDoubleParams(const std::string& paramName, const std::vector<double>& val) : CommandBase(CmdName, TargetId)
  {

    setParamName(paramName);
    setVal(val);
  }

  static SetGlonassDoubleParamsPtr create(const std::string& paramName, const std::vector<double>& val)
  {
    return std::make_shared<SetGlonassDoubleParams>(paramName, val);
  }

  static SetGlonassDoubleParamsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetGlonassDoubleParams>(ptr);
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

  int executePermission() const { return EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(SetGlonassDoubleParams);
} // namespace Cmd
} // namespace Sdx
