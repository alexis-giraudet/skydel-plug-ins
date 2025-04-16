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
/// Result of GetPulsarX1HealthForSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..258, or use 0 to apply new value to all satellites. Health      bool            X1 health, false
/// = Signal not operational, true = Signal operational DataSetName optional string Optional name of the data set to
/// use. If no value is provided, the active data set is used.
///

class GetPulsarX1HealthForSVResult;
typedef std::shared_ptr<GetPulsarX1HealthForSVResult> GetPulsarX1HealthForSVResultPtr;

class GetPulsarX1HealthForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetPulsarX1HealthForSVResult";
  inline static const char* const Documentation =
    "Result of GetPulsarX1HealthForSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
    "Health      bool            X1 health, false = Signal not operational, true = Signal operational\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetPulsarX1HealthForSVResult() : CommandResult(CmdName, TargetId) {}

  GetPulsarX1HealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  GetPulsarX1HealthForSVResult(CommandBasePtr relatedCommand,
                               int svId,
                               bool health,
                               const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  static GetPulsarX1HealthForSVResultPtr create(int svId,
                                                bool health,
                                                const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetPulsarX1HealthForSVResult>(svId, health, dataSetName);
  }

  static GetPulsarX1HealthForSVResultPtr create(CommandBasePtr relatedCommand,
                                                int svId,
                                                bool health,
                                                const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetPulsarX1HealthForSVResult>(relatedCommand, svId, health, dataSetName);
  }

  static GetPulsarX1HealthForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPulsarX1HealthForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<bool>::is_valid(m_values["Health"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Health", "DataSetName"};
    return names;
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool health() const { return parse_json<bool>::parse(m_values["Health"]); }

  void setHealth(bool health)
  {
    m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(GetPulsarX1HealthForSVResult);
} // namespace Cmd
} // namespace Sdx
