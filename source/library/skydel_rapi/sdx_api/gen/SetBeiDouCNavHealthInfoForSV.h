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
/// Set BeiDou CNav satellite health info
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..35, or use 0 to apply new value to all satellites. Health      int             Health Info, 8-bit
/// integer : 0, 32, 64, 96, 128 or 255 DataSetName optional string Optional name of the data set to use. If no value is
/// provided, the active data set is used.
///

class SetBeiDouCNavHealthInfoForSV;
typedef std::shared_ptr<SetBeiDouCNavHealthInfoForSV> SetBeiDouCNavHealthInfoForSVPtr;

class SetBeiDouCNavHealthInfoForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetBeiDouCNavHealthInfoForSV";
  inline static const char* const Documentation =
    "Set BeiDou CNav satellite health info\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites.\n"
    "Health      int             Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  SetBeiDouCNavHealthInfoForSV() : CommandBase(CmdName, TargetId) {}

  SetBeiDouCNavHealthInfoForSV(int svId, int health, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  static SetBeiDouCNavHealthInfoForSVPtr create(int svId,
                                                int health,
                                                const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetBeiDouCNavHealthInfoForSV>(svId, health, dataSetName);
  }

  static SetBeiDouCNavHealthInfoForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetBeiDouCNavHealthInfoForSV>(ptr);
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

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(SetBeiDouCNavHealthInfoForSV);
} // namespace Cmd
} // namespace Sdx
