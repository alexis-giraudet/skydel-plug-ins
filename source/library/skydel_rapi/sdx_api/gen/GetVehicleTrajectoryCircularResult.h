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
/// Result of GetVehicleTrajectoryCircular.
///
/// Name        Type            Description
/// ----------- --------------- --------------------------------
/// Type        string          Trajectory type ("Circular")
/// Lat         double          Center latitude (rad)
/// Lon         double          Center longitude (rad)
/// Alt         double          Altitude (m)
/// Radius      double          Radius (m)
/// Speed       double          Speed (m/s)
/// Clockwise   bool            If true, vehicle turns clockwise
/// OriginAngle optional double Vehicle angle at elapsed time 0.
///

class GetVehicleTrajectoryCircularResult;
typedef std::shared_ptr<GetVehicleTrajectoryCircularResult> GetVehicleTrajectoryCircularResultPtr;

class GetVehicleTrajectoryCircularResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVehicleTrajectoryCircularResult";
  inline static const char* const Documentation = "Result of GetVehicleTrajectoryCircular.\n"
                                                  "\n"
                                                  "Name        Type            Description\n"
                                                  "----------- --------------- --------------------------------\n"
                                                  "Type        string          Trajectory type (\"Circular\")\n"
                                                  "Lat         double          Center latitude (rad)\n"
                                                  "Lon         double          Center longitude (rad)\n"
                                                  "Alt         double          Altitude (m)\n"
                                                  "Radius      double          Radius (m)\n"
                                                  "Speed       double          Speed (m/s)\n"
                                                  "Clockwise   bool            If true, vehicle turns clockwise\n"
                                                  "OriginAngle optional double Vehicle angle at elapsed time 0.";
  inline static const char* const TargetId = "";

  GetVehicleTrajectoryCircularResult() : CommandResult(CmdName, TargetId) {}

  GetVehicleTrajectoryCircularResult(const std::string& type,
                                     double lat,
                                     double lon,
                                     double alt,
                                     double radius,
                                     double speed,
                                     bool clockwise,
                                     const std::optional<double>& originAngle = {}) :
    CommandResult(CmdName, TargetId)
  {

    setType(type);
    setLat(lat);
    setLon(lon);
    setAlt(alt);
    setRadius(radius);
    setSpeed(speed);
    setClockwise(clockwise);
    setOriginAngle(originAngle);
  }

  GetVehicleTrajectoryCircularResult(CommandBasePtr relatedCommand,
                                     const std::string& type,
                                     double lat,
                                     double lon,
                                     double alt,
                                     double radius,
                                     double speed,
                                     bool clockwise,
                                     const std::optional<double>& originAngle = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setType(type);
    setLat(lat);
    setLon(lon);
    setAlt(alt);
    setRadius(radius);
    setSpeed(speed);
    setClockwise(clockwise);
    setOriginAngle(originAngle);
  }

  static GetVehicleTrajectoryCircularResultPtr create(const std::string& type,
                                                      double lat,
                                                      double lon,
                                                      double alt,
                                                      double radius,
                                                      double speed,
                                                      bool clockwise,
                                                      const std::optional<double>& originAngle = {})
  {
    return std::make_shared<GetVehicleTrajectoryCircularResult>(type,
                                                                lat,
                                                                lon,
                                                                alt,
                                                                radius,
                                                                speed,
                                                                clockwise,
                                                                originAngle);
  }

  static GetVehicleTrajectoryCircularResultPtr create(CommandBasePtr relatedCommand,
                                                      const std::string& type,
                                                      double lat,
                                                      double lon,
                                                      double alt,
                                                      double radius,
                                                      double speed,
                                                      bool clockwise,
                                                      const std::optional<double>& originAngle = {})
  {
    return std::make_shared<GetVehicleTrajectoryCircularResult>(relatedCommand,
                                                                type,
                                                                lat,
                                                                lon,
                                                                alt,
                                                                radius,
                                                                speed,
                                                                clockwise,
                                                                originAngle);
  }

  static GetVehicleTrajectoryCircularResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleTrajectoryCircularResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]) &&
           parse_json<double>::is_valid(m_values["Lat"]) && parse_json<double>::is_valid(m_values["Lon"]) &&
           parse_json<double>::is_valid(m_values["Alt"]) && parse_json<double>::is_valid(m_values["Radius"]) &&
           parse_json<double>::is_valid(m_values["Speed"]) && parse_json<bool>::is_valid(m_values["Clockwise"]) &&
           parse_json<std::optional<double>>::is_valid(m_values["OriginAngle"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Type", "Lat", "Lon", "Alt", "Radius", "Speed", "Clockwise", "OriginAngle"};
    return names;
  }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double lat() const { return parse_json<double>::parse(m_values["Lat"]); }

  void setLat(double lat)
  {
    m_values.AddMember("Lat", parse_json<double>::format(lat, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double lon() const { return parse_json<double>::parse(m_values["Lon"]); }

  void setLon(double lon)
  {
    m_values.AddMember("Lon", parse_json<double>::format(lon, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double alt() const { return parse_json<double>::parse(m_values["Alt"]); }

  void setAlt(double alt)
  {
    m_values.AddMember("Alt", parse_json<double>::format(alt, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double radius() const { return parse_json<double>::parse(m_values["Radius"]); }

  void setRadius(double radius)
  {
    m_values.AddMember("Radius", parse_json<double>::format(radius, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double speed() const { return parse_json<double>::parse(m_values["Speed"]); }

  void setSpeed(double speed)
  {
    m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool clockwise() const { return parse_json<bool>::parse(m_values["Clockwise"]); }

  void setClockwise(bool clockwise)
  {
    m_values.AddMember("Clockwise",
                       parse_json<bool>::format(clockwise, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<double> originAngle() const
  {
    return parse_json<std::optional<double>>::parse(m_values["OriginAngle"]);
  }

  void setOriginAngle(const std::optional<double>& originAngle)
  {
    m_values.AddMember("OriginAngle",
                       parse_json<std::optional<double>>::format(originAngle, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryCircularResult);
} // namespace Cmd
} // namespace Sdx
