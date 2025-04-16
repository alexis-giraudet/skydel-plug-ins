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
/// Result of IsSVForcedGeo.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" SvId        int             The satellite SV ID IsGeo bool
/// True for geostationary satellite Longitude   double          The longitude to use, in degree DataSetName optional
/// string Optional name of the data set to use. If no value is provided, the active data set is used.
///

class IsSVForcedGeoResult;
typedef std::shared_ptr<IsSVForcedGeoResult> IsSVForcedGeoResultPtr;

class IsSVForcedGeoResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsSVForcedGeoResult";
  inline static const char* const Documentation =
    "Result of IsSVForcedGeo.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId        int             The satellite SV ID\n"
    "IsGeo       bool            True for geostationary satellite\n"
    "Longitude   double          The longitude to use, in degree\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  IsSVForcedGeoResult() : CommandResult(CmdName, TargetId) {}

  IsSVForcedGeoResult(const std::string& system,
                      int svId,
                      bool isGeo,
                      double longitude,
                      const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setIsGeo(isGeo);
    setLongitude(longitude);
    setDataSetName(dataSetName);
  }

  IsSVForcedGeoResult(CommandBasePtr relatedCommand,
                      const std::string& system,
                      int svId,
                      bool isGeo,
                      double longitude,
                      const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setIsGeo(isGeo);
    setLongitude(longitude);
    setDataSetName(dataSetName);
  }

  static IsSVForcedGeoResultPtr create(const std::string& system,
                                       int svId,
                                       bool isGeo,
                                       double longitude,
                                       const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<IsSVForcedGeoResult>(system, svId, isGeo, longitude, dataSetName);
  }

  static IsSVForcedGeoResultPtr create(CommandBasePtr relatedCommand,
                                       const std::string& system,
                                       int svId,
                                       bool isGeo,
                                       double longitude,
                                       const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<IsSVForcedGeoResult>(relatedCommand, system, svId, isGeo, longitude, dataSetName);
  }

  static IsSVForcedGeoResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSVForcedGeoResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<bool>::is_valid(m_values["IsGeo"]) &&
           parse_json<double>::is_valid(m_values["Longitude"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "IsGeo", "Longitude", "DataSetName"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool isGeo() const { return parse_json<bool>::parse(m_values["IsGeo"]); }

  void setIsGeo(bool isGeo)
  {
    m_values.AddMember("IsGeo", parse_json<bool>::format(isGeo, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double longitude() const { return parse_json<double>::parse(m_values["Longitude"]); }

  void setLongitude(double longitude)
  {
    m_values.AddMember("Longitude",
                       parse_json<double>::format(longitude, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(IsSVForcedGeoResult);
} // namespace Cmd
} // namespace Sdx
