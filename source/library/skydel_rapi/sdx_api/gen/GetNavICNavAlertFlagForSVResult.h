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
/// Result of GetNavICNavAlertFlagForSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..14, or use 0 to apply new value to all satellites. Alert       bool            NavIC NAV Alert
/// Flag, false = No Alert, true = Alert DataSetName optional string Optional name of the data set to use. If no value
/// is provided, the active data set is used.
///

class GetNavICNavAlertFlagForSVResult;
typedef std::shared_ptr<GetNavICNavAlertFlagForSVResult> GetNavICNavAlertFlagForSVResultPtr;
typedef GetNavICNavAlertFlagForSVResult GetNavICSatelliteNavAlertFlagResult;
typedef std::shared_ptr<GetNavICSatelliteNavAlertFlagResult> GetNavICSatelliteNavAlertFlagResultPtr;

class GetNavICNavAlertFlagForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetNavICNavAlertFlagForSVResult";
  inline static const char* const Documentation =
    "Result of GetNavICNavAlertFlagForSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
    "Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetNavICNavAlertFlagForSVResult() : CommandResult(CmdName, TargetId) {}

  GetNavICNavAlertFlagForSVResult(int svId, bool alert, const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setAlert(alert);
    setDataSetName(dataSetName);
  }

  GetNavICNavAlertFlagForSVResult(CommandBasePtr relatedCommand,
                                  int svId,
                                  bool alert,
                                  const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setAlert(alert);
    setDataSetName(dataSetName);
  }

  static GetNavICNavAlertFlagForSVResultPtr create(int svId,
                                                   bool alert,
                                                   const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetNavICNavAlertFlagForSVResult>(svId, alert, dataSetName);
  }

  static GetNavICNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand,
                                                   int svId,
                                                   bool alert,
                                                   const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetNavICNavAlertFlagForSVResult>(relatedCommand, svId, alert, dataSetName);
  }

  static GetNavICNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetNavICNavAlertFlagForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<bool>::is_valid(m_values["Alert"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"};
    return names;
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool alert() const { return parse_json<bool>::parse(m_values["Alert"]); }

  void setAlert(bool alert)
  {
    m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(GetNavICNavAlertFlagForSVResult);
} // namespace Cmd
} // namespace Sdx
