#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetGpsConfigurationForEachSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvConfigs   array int SV
/// Config of all satellite DataSetName optional string Optional name of the data set to use. If no value is provided,
/// the active data set is used.
///

class GetGpsConfigurationForEachSVResult;
typedef std::shared_ptr<GetGpsConfigurationForEachSVResult> GetGpsConfigurationForEachSVResultPtr;
typedef GetGpsConfigurationForEachSVResult GetGpsSVConfigurationForAllSatResult;
typedef std::shared_ptr<GetGpsSVConfigurationForAllSatResult> GetGpsSVConfigurationForAllSatResultPtr;

class GetGpsConfigurationForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetGpsConfigurationForEachSVResult";
  inline static const char* const Documentation =
    "Result of GetGpsConfigurationForEachSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvConfigs   array int       SV Config of all satellite\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetGpsConfigurationForEachSVResult() : CommandResult(CmdName, TargetId) {}

  GetGpsConfigurationForEachSVResult(const std::vector<int>& svConfigs,
                                     const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSvConfigs(svConfigs);
    setDataSetName(dataSetName);
  }

  GetGpsConfigurationForEachSVResult(CommandBasePtr relatedCommand,
                                     const std::vector<int>& svConfigs,
                                     const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvConfigs(svConfigs);
    setDataSetName(dataSetName);
  }

  static GetGpsConfigurationForEachSVResultPtr create(const std::vector<int>& svConfigs,
                                                      const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetGpsConfigurationForEachSVResult>(svConfigs, dataSetName);
  }

  static GetGpsConfigurationForEachSVResultPtr create(CommandBasePtr relatedCommand,
                                                      const std::vector<int>& svConfigs,
                                                      const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetGpsConfigurationForEachSVResult>(relatedCommand, svConfigs, dataSetName);
  }

  static GetGpsConfigurationForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGpsConfigurationForEachSVResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetGpsConfigurationForEachSVResult);
} // namespace Cmd
} // namespace Sdx
