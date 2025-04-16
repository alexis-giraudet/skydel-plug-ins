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
/// Set spoofer transmitter circular trajectory
///
/// Name        Type            Description
/// ----------- --------------- --------------------------------
/// Lat         double          Center latitude (rad)
/// Lon         double          Center longitude (rad)
/// Alt         double          Altitude (m)
/// Radius      double          Radius (m)
/// Speed       double          Speed (m/s)
/// Clockwise   bool            If true, vehicle turns clockwise
/// Id          string          Transmitter unique identifier.
/// OriginAngle optional double Vehicle angle at elapsed time 0.
///

class SetSpoofTxCircular;
typedef std::shared_ptr<SetSpoofTxCircular> SetSpoofTxCircularPtr;

class SetSpoofTxCircular : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpoofTxCircular";
  inline static const char* const Documentation = "Set spoofer transmitter circular trajectory\n"
                                                  "\n"
                                                  "Name        Type            Description\n"
                                                  "----------- --------------- --------------------------------\n"
                                                  "Lat         double          Center latitude (rad)\n"
                                                  "Lon         double          Center longitude (rad)\n"
                                                  "Alt         double          Altitude (m)\n"
                                                  "Radius      double          Radius (m)\n"
                                                  "Speed       double          Speed (m/s)\n"
                                                  "Clockwise   bool            If true, vehicle turns clockwise\n"
                                                  "Id          string          Transmitter unique identifier.\n"
                                                  "OriginAngle optional double Vehicle angle at elapsed time 0.";
  inline static const char* const TargetId = "";

  SetSpoofTxCircular() : CommandBase(CmdName, TargetId) {}

  SetSpoofTxCircular(double lat,
                     double lon,
                     double alt,
                     double radius,
                     double speed,
                     bool clockwise,
                     const std::string& id,
                     const std::optional<double>& originAngle = {}) :
    CommandBase(CmdName, TargetId)
  {

    setLat(lat);
    setLon(lon);
    setAlt(alt);
    setRadius(radius);
    setSpeed(speed);
    setClockwise(clockwise);
    setId(id);
    setOriginAngle(originAngle);
  }

  static SetSpoofTxCircularPtr create(double lat,
                                      double lon,
                                      double alt,
                                      double radius,
                                      double speed,
                                      bool clockwise,
                                      const std::string& id,
                                      const std::optional<double>& originAngle = {})
  {
    return std::make_shared<SetSpoofTxCircular>(lat, lon, alt, radius, speed, clockwise, id, originAngle);
  }

  static SetSpoofTxCircularPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpoofTxCircular>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Lat"]) &&
           parse_json<double>::is_valid(m_values["Lon"]) && parse_json<double>::is_valid(m_values["Alt"]) &&
           parse_json<double>::is_valid(m_values["Radius"]) && parse_json<double>::is_valid(m_values["Speed"]) &&
           parse_json<bool>::is_valid(m_values["Clockwise"]) && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<std::optional<double>>::is_valid(m_values["OriginAngle"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"Lat", "Lon", "Alt", "Radius", "Speed", "Clockwise", "Id", "OriginAngle"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(SetSpoofTxCircular);
} // namespace Cmd
} // namespace Sdx
