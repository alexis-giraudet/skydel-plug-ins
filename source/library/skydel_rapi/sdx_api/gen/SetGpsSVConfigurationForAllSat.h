#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command SetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use
/// SetGpsConfigurationForEachSV.
///
/// Set GPS SV configuration flag for each SVs
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvConfigs   array int SV
/// Config of all satellite DataSetName optional string Optional name of the data set to use. If no value is provided,
/// the active data set is used.
///

class SetGpsSVConfigurationForAllSat;
typedef std::shared_ptr<SetGpsSVConfigurationForAllSat> SetGpsSVConfigurationForAllSatPtr;

class SetGpsSVConfigurationForAllSat : public CommandBase
{
public:
  inline static const char* const CmdName = "SetGpsSVConfigurationForAllSat";
  inline static const char* const Documentation =
    "Please note the command SetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use SetGpsConfigurationForEachSV.\n"
    "\n"
    "Set GPS SV configuration flag for each SVs\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvConfigs   array int       SV Config of all satellite\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  SetGpsSVConfigurationForAllSat() : CommandBase(CmdName, TargetId) {}

  SetGpsSVConfigurationForAllSat(const std::vector<int>& svConfigs,
                                 const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSvConfigs(svConfigs);
    setDataSetName(dataSetName);
  }

  static SetGpsSVConfigurationForAllSatPtr create(const std::vector<int>& svConfigs,
                                                  const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetGpsSVConfigurationForAllSat>(svConfigs, dataSetName);
  }

  static SetGpsSVConfigurationForAllSatPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetGpsSVConfigurationForAllSat>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<int>>::is_valid(m_values["SvConfigs"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvConfigs", "DataSetName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::vector<int> svConfigs() const { return parse_json<std::vector<int>>::parse(m_values["SvConfigs"]); }

  void setSvConfigs(const std::vector<int>& svConfigs)
  {
    m_values.AddMember("SvConfigs",
                       parse_json<std::vector<int>>::format(svConfigs, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(SetGpsSVConfigurationForAllSat);
} // namespace Cmd
} // namespace Sdx
