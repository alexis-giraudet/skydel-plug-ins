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
/// Result of GetBeiDouHealthInfoForSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..35, or use 0 to apply new value to all satellites. Health      int             Health Info, 9-bit
/// integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511 DataSetName optional string Optional name of the data set to
/// use. If no value is provided, the active data set is used.
///

class GetBeiDouHealthInfoForSVResult;
typedef std::shared_ptr<GetBeiDouHealthInfoForSVResult> GetBeiDouHealthInfoForSVResultPtr;

class GetBeiDouHealthInfoForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetBeiDouHealthInfoForSVResult";
  inline static const char* const Documentation =
    "Result of GetBeiDouHealthInfoForSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
    "Health      int             Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetBeiDouHealthInfoForSVResult() : CommandResult(CmdName, TargetId) {}

  GetBeiDouHealthInfoForSVResult(int svId, int health, const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  GetBeiDouHealthInfoForSVResult(CommandBasePtr relatedCommand,
                                 int svId,
                                 int health,
                                 const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  static GetBeiDouHealthInfoForSVResultPtr create(int svId,
                                                  int health,
                                                  const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetBeiDouHealthInfoForSVResult>(svId, health, dataSetName);
  }

  static GetBeiDouHealthInfoForSVResultPtr create(CommandBasePtr relatedCommand,
                                                  int svId,
                                                  int health,
                                                  const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetBeiDouHealthInfoForSVResult>(relatedCommand, svId, health, dataSetName);
  }

  static GetBeiDouHealthInfoForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetBeiDouHealthInfoForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<int>::is_valid(m_values["Health"]) &&
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

  int health() const { return parse_json<int>::parse(m_values["Health"]); }

  void setHealth(int health)
  {
    m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(GetBeiDouHealthInfoForSVResult);
} // namespace Cmd
} // namespace Sdx
