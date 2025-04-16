#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/ElevationAzimuth.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetElevationAzimuthForSV.
///
/// Name             Type                      Description
/// ---------------- -------------------------
/// --------------------------------------------------------------------------- System           string "GPS",
/// "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR". SvId             int Satellite's SV ID.
/// ElevationAzimuth optional ElevationAzimuth Elevation and Azimuth position angles of the satellite.
///

class GetElevationAzimuthForSVResult;
typedef std::shared_ptr<GetElevationAzimuthForSVResult> GetElevationAzimuthForSVResultPtr;

class GetElevationAzimuthForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetElevationAzimuthForSVResult";
  inline static const char* const Documentation =
    "Result of GetElevationAzimuthForSV.\n"
    "\n"
    "Name             Type                      Description\n"
    "---------------- ------------------------- ---------------------------------------------------------------------------\n"
    "System           string                    \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
    "SvId             int                       Satellite's SV ID.\n"
    "ElevationAzimuth optional ElevationAzimuth Elevation and Azimuth position angles of the satellite.";
  inline static const char* const TargetId = "";

  GetElevationAzimuthForSVResult() : CommandResult(CmdName, TargetId) {}

  GetElevationAzimuthForSVResult(const std::string& system,
                                 int svId,
                                 const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setElevationAzimuth(elevationAzimuth);
  }

  GetElevationAzimuthForSVResult(CommandBasePtr relatedCommand,
                                 const std::string& system,
                                 int svId,
                                 const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setElevationAzimuth(elevationAzimuth);
  }

  static GetElevationAzimuthForSVResultPtr create(const std::string& system,
                                                  int svId,
                                                  const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {})
  {
    return std::make_shared<GetElevationAzimuthForSVResult>(system, svId, elevationAzimuth);
  }

  static GetElevationAzimuthForSVResultPtr create(CommandBasePtr relatedCommand,
                                                  const std::string& system,
                                                  int svId,
                                                  const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth = {})
  {
    return std::make_shared<GetElevationAzimuthForSVResult>(relatedCommand, system, svId, elevationAzimuth);
  }

  static GetElevationAzimuthForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetElevationAzimuthForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::optional<Sdx::ElevationAzimuth>>::is_valid(m_values["ElevationAzimuth"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "ElevationAzimuth"};
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

  std::optional<Sdx::ElevationAzimuth> elevationAzimuth() const
  {
    return parse_json<std::optional<Sdx::ElevationAzimuth>>::parse(m_values["ElevationAzimuth"]);
  }

  void setElevationAzimuth(const std::optional<Sdx::ElevationAzimuth>& elevationAzimuth)
  {
    m_values.AddMember("ElevationAzimuth",
                       parse_json<std::optional<Sdx::ElevationAzimuth>>::format(elevationAzimuth,
                                                                                m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetElevationAzimuthForSVResult);
} // namespace Cmd
} // namespace Sdx
