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
/// Result of GetGalileoDataHealthForSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID number 1..36. Component   string          Component is either "E5a", "E5b", or "E1B" Health bool
/// False means Navigation data valid; True means Working without guarantee DataSetName optional string Optional name of
/// the data set to use. If no value is provided, the active data set is used.
///

class GetGalileoDataHealthForSVResult;
typedef std::shared_ptr<GetGalileoDataHealthForSVResult> GetGalileoDataHealthForSVResultPtr;

class GetGalileoDataHealthForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetGalileoDataHealthForSVResult";
  inline static const char* const Documentation =
    "Result of GetGalileoDataHealthForSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID number 1..36.\n"
    "Component   string          Component is either \"E5a\", \"E5b\", or \"E1B\"\n"
    "Health      bool            False means Navigation data valid; True means Working without guarantee\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetGalileoDataHealthForSVResult() : CommandResult(CmdName, TargetId) {}

  GetGalileoDataHealthForSVResult(int svId,
                                  const std::string& component,
                                  bool health,
                                  const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setComponent(component);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  GetGalileoDataHealthForSVResult(CommandBasePtr relatedCommand,
                                  int svId,
                                  const std::string& component,
                                  bool health,
                                  const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setComponent(component);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  static GetGalileoDataHealthForSVResultPtr create(int svId,
                                                   const std::string& component,
                                                   bool health,
                                                   const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetGalileoDataHealthForSVResult>(svId, component, health, dataSetName);
  }

  static GetGalileoDataHealthForSVResultPtr create(CommandBasePtr relatedCommand,
                                                   int svId,
                                                   const std::string& component,
                                                   bool health,
                                                   const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetGalileoDataHealthForSVResult>(relatedCommand, svId, component, health, dataSetName);
  }

  static GetGalileoDataHealthForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGalileoDataHealthForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::string>::is_valid(m_values["Component"]) && parse_json<bool>::is_valid(m_values["Health"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Component", "Health", "DataSetName"};
    return names;
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string component() const { return parse_json<std::string>::parse(m_values["Component"]); }

  void setComponent(const std::string& component)
  {
    m_values.AddMember("Component",
                       parse_json<std::string>::format(component, m_values.GetAllocator()),
                       m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(GetGalileoDataHealthForSVResult);
} // namespace Cmd
} // namespace Sdx
