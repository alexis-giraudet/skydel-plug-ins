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
/// Set QZSS L1 health (Health of L1C/A signal)
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..10, or use 0 to apply new value to all satellites. Health      bool            L1 health, false =
/// signal OK, true = signal bad DataSetName optional string Optional name of the data set to use. If no value is
/// provided, the active data set is used.
///

class SetQzssL1HealthForSV;
typedef std::shared_ptr<SetQzssL1HealthForSV> SetQzssL1HealthForSVPtr;

class SetQzssL1HealthForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetQzssL1HealthForSV";
  inline static const char* const Documentation =
    "Set QZSS L1 health (Health of L1C/A signal)\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"
    "Health      bool            L1 health, false = signal OK, true = signal bad\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  SetQzssL1HealthForSV() : CommandBase(CmdName, TargetId) {}

  SetQzssL1HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  static SetQzssL1HealthForSVPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetQzssL1HealthForSV>(svId, health, dataSetName);
  }

  static SetQzssL1HealthForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetQzssL1HealthForSV>(ptr);
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

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(SetQzssL1HealthForSV);
} // namespace Cmd
} // namespace Sdx
