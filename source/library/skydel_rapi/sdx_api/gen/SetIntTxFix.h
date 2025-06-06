#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set interference transmitter static position and orientation
///
/// Name  Type   Description
/// ----- ------ ------------------------------
/// Lat   double Latitude (rad)
/// Lon   double Longitude (rad)
/// Alt   double Altitude (m)
/// Yaw   double Yaw (rad)
/// Pitch double Pitch (rad)
/// Roll  double Roll (rad)
/// Id    string Transmitter unique identifier.
///

class SetIntTxFix;
typedef std::shared_ptr<SetIntTxFix> SetIntTxFixPtr;

class SetIntTxFix : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIntTxFix";
  inline static const char* const Documentation = "Set interference transmitter static position and orientation\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------------\n"
                                                  "Lat   double Latitude (rad)\n"
                                                  "Lon   double Longitude (rad)\n"
                                                  "Alt   double Altitude (m)\n"
                                                  "Yaw   double Yaw (rad)\n"
                                                  "Pitch double Pitch (rad)\n"
                                                  "Roll  double Roll (rad)\n"
                                                  "Id    string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetIntTxFix() : CommandBase(CmdName, TargetId) {}

  SetIntTxFix(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setLat(lat);
    setLon(lon);
    setAlt(alt);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setId(id);
  }

  static SetIntTxFixPtr
  create(double lat, double lon, double alt, double yaw, double pitch, double roll, const std::string& id)
  {
    return std::make_shared<SetIntTxFix>(lat, lon, alt, yaw, pitch, roll, id);
  }

  static SetIntTxFixPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIntTxFix>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Lat"]) &&
           parse_json<double>::is_valid(m_values["Lon"]) && parse_json<double>::is_valid(m_values["Alt"]) &&
           parse_json<double>::is_valid(m_values["Yaw"]) && parse_json<double>::is_valid(m_values["Pitch"]) &&
           parse_json<double>::is_valid(m_values["Roll"]) && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Lat", "Lon", "Alt", "Yaw", "Pitch", "Roll", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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

  double yaw() const { return parse_json<double>::parse(m_values["Yaw"]); }

  void setYaw(double yaw)
  {
    m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double pitch() const { return parse_json<double>::parse(m_values["Pitch"]); }

  void setPitch(double pitch)
  {
    m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double roll() const { return parse_json<double>::parse(m_values["Roll"]); }

  void setRoll(double roll)
  {
    m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetIntTxFix);
} // namespace Cmd
} // namespace Sdx
