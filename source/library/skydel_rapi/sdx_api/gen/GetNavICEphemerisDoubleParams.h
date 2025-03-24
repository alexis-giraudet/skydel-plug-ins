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
/// Please note the command GetNavICEphemerisDoubleParams is deprecated since 21.3. You may use
/// GetNavICEphDoubleParamForEachSV.
///
/// Please note the command GetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use
/// GetConstellationParameterForSV.
///
/// Get NavIC ephemeris parameter value for all satellites
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- ParamName   string Refer
/// to SetNavICEphDoubleParamForSV for accepted names DataSetName optional string Optional name of the data set to use.
/// If no value is provided, the active data set is used.
///

class GetNavICEphemerisDoubleParams;
typedef std::shared_ptr<GetNavICEphemerisDoubleParams> GetNavICEphemerisDoubleParamsPtr;

class GetNavICEphemerisDoubleParams : public CommandBase
{
public:
  inline static const char* const CmdName = "GetNavICEphemerisDoubleParams";
  inline static const char* const Documentation =
    "Please note the command GetNavICEphemerisDoubleParams is deprecated since 21.3. You may use GetNavICEphDoubleParamForEachSV.\n"
    "\n"
    "Please note the command GetNavICEphDoubleParamForEachSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"
    "\n"
    "Get NavIC ephemeris parameter value for all satellites\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command GetNavICEphemerisDoubleParams is deprecated since 23.11. You may use GetConstellationParameterForSV.";

  GetNavICEphemerisDoubleParams() : CommandBase(CmdName, TargetId) {}

  GetNavICEphemerisDoubleParams(const std::string& paramName, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setParamName(paramName);
    setDataSetName(dataSetName);
  }

  static GetNavICEphemerisDoubleParamsPtr create(const std::string& paramName,
                                                 const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetNavICEphemerisDoubleParams>(paramName, dataSetName);
  }

  static GetNavICEphemerisDoubleParamsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetNavICEphemerisDoubleParams>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetNavICEphemerisDoubleParams);
} // namespace Cmd
} // namespace Sdx
