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
/// Set whether a satellite is geostationary
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" SvId        int             The satellite SV ID IsGeo bool
/// True for geostationary satellite Longitude   double          The longitude to use, in degree DataSetName optional
/// string Optional name of the data set to use. If no value is provided, the active data set is used.
///

class ForceSVGeo;
typedef std::shared_ptr<ForceSVGeo> ForceSVGeoPtr;

class ForceSVGeo : public CommandBase
{
public:
  inline static const char* const CmdName = "ForceSVGeo";
  inline static const char* const Documentation =
    "Set whether a satellite is geostationary\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId        int             The satellite SV ID\n"
    "IsGeo       bool            True for geostationary satellite\n"
    "Longitude   double          The longitude to use, in degree\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  ForceSVGeo() : CommandBase(CmdName, TargetId) {}

  ForceSVGeo(const std::string& system,
             int svId,
             bool isGeo,
             double longitude,
             const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setIsGeo(isGeo);
    setLongitude(longitude);
    setDataSetName(dataSetName);
  }

  static ForceSVGeoPtr create(const std::string& system,
                              int svId,
                              bool isGeo,
                              double longitude,
                              const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<ForceSVGeo>(system, svId, isGeo, longitude, dataSetName);
  }

  static ForceSVGeoPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<ForceSVGeo>(ptr); }

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

  int executePermission() const { return EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(ForceSVGeo);
} // namespace Cmd
} // namespace Sdx
