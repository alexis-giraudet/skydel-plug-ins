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
/// Result of GetQzssNavAlertFlagForSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..10, or use 0 to apply new value to all satellites. Alert       bool            QZSS NAV Alert
/// Flag, false = No Alert, true = Alert DataSetName optional string Optional name of the data set to use. If no value
/// is provided, the active data set is used.
///

class GetQzssNavAlertFlagForSVResult;
typedef std::shared_ptr<GetQzssNavAlertFlagForSVResult> GetQzssNavAlertFlagForSVResultPtr;
typedef GetQzssNavAlertFlagForSVResult GetQzssSatelliteNavAlertFlagResult;
typedef std::shared_ptr<GetQzssSatelliteNavAlertFlagResult> GetQzssSatelliteNavAlertFlagResultPtr;

class GetQzssNavAlertFlagForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetQzssNavAlertFlagForSVResult";
  inline static const char* const Documentation =
    "Result of GetQzssNavAlertFlagForSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
    "Alert       bool            QZSS NAV Alert Flag, false = No Alert, true = Alert\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetQzssNavAlertFlagForSVResult() : CommandResult(CmdName, TargetId) {}

  GetQzssNavAlertFlagForSVResult(int svId, bool alert, const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setAlert(alert);
    setDataSetName(dataSetName);
  }

  GetQzssNavAlertFlagForSVResult(CommandBasePtr relatedCommand,
                                 int svId,
                                 bool alert,
                                 const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setAlert(alert);
    setDataSetName(dataSetName);
  }

  static GetQzssNavAlertFlagForSVResultPtr create(int svId,
                                                  bool alert,
                                                  const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetQzssNavAlertFlagForSVResult>(svId, alert, dataSetName);
  }

  static GetQzssNavAlertFlagForSVResultPtr create(CommandBasePtr relatedCommand,
                                                  int svId,
                                                  bool alert,
                                                  const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetQzssNavAlertFlagForSVResult>(relatedCommand, svId, alert, dataSetName);
  }

  static GetQzssNavAlertFlagForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetQzssNavAlertFlagForSVResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetQzssNavAlertFlagForSVResult);
} // namespace Cmd
} // namespace Sdx
