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
/// Set PULSAR X5 health (Health of X5 Signal)
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..258, or use 0 to apply new value to all satellites. Health      bool            X5 health, false
/// = Signal not operational, true = Signal operational DataSetName optional string Optional name of the data set to
/// use. If no value is provided, the active data set is used.
///

class SetPulsarX5HealthForSV;
typedef std::shared_ptr<SetPulsarX5HealthForSV> SetPulsarX5HealthForSVPtr;

class SetPulsarX5HealthForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPulsarX5HealthForSV";
  inline static const char* const Documentation =
    "Set PULSAR X5 health (Health of X5 Signal)\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"
    "Health      bool            X5 health, false = Signal not operational, true = Signal operational\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  SetPulsarX5HealthForSV() : CommandBase(CmdName, TargetId) {}

  SetPulsarX5HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
    setDataSetName(dataSetName);
  }

  static SetPulsarX5HealthForSVPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetPulsarX5HealthForSV>(svId, health, dataSetName);
  }

  static SetPulsarX5HealthForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetPulsarX5HealthForSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetPulsarX5HealthForSV);
} // namespace Cmd
} // namespace Sdx
