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
/// Set GPS SV configuration flag for one satellite
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..32 SvConfig    int             SV Config 0..4 DataSetName optional string Optional name of the
/// data set to use. If no value is provided, the active data set is used.
///

class SetGpsConfigurationCodeForSV;
typedef std::shared_ptr<SetGpsConfigurationCodeForSV> SetGpsConfigurationCodeForSVPtr;

class SetGpsConfigurationCodeForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetGpsConfigurationCodeForSV";
  inline static const char* const Documentation =
    "Set GPS SV configuration flag for one satellite\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..32\n"
    "SvConfig    int             SV Config 0..4\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  SetGpsConfigurationCodeForSV() : CommandBase(CmdName, TargetId) {}

  SetGpsConfigurationCodeForSV(int svId, int svConfig, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setSvConfig(svConfig);
    setDataSetName(dataSetName);
  }

  static SetGpsConfigurationCodeForSVPtr create(int svId,
                                                int svConfig,
                                                const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetGpsConfigurationCodeForSV>(svId, svConfig, dataSetName);
  }

  static SetGpsConfigurationCodeForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetGpsConfigurationCodeForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<int>::is_valid(m_values["SvConfig"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "SvConfig", "DataSetName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int svConfig() const { return parse_json<int>::parse(m_values["SvConfig"]); }

  void setSvConfig(int svConfig)
  {
    m_values.AddMember("SvConfig", parse_json<int>::format(svConfig, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(SetGpsConfigurationCodeForSV);
} // namespace Cmd
} // namespace Sdx
