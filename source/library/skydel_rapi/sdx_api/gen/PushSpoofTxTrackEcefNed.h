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
/// Push a spoofer transmitter track ECEF and NED attitude node. Must be called after BeginSpoofTxTrackDefinition and
/// before EndSpoofTxTrackDefinition.
///
/// Name  Type   Description
/// ----- ------ ---------------------------------------
/// Time  int    Node Timestamp in miliseconds.
/// X     double X distance from earth-center in meters.
/// Y     double Y distance from earth-center in meters.
/// Z     double Z distance from earth-center in meters.
/// Yaw   double Yaw in radians.
/// Pitch double Pitch in radians.
/// Roll  double Roll in radians.
/// Id    string Transmitter unique identifier.
///

class PushSpoofTxTrackEcefNed;
typedef std::shared_ptr<PushSpoofTxTrackEcefNed> PushSpoofTxTrackEcefNedPtr;

class PushSpoofTxTrackEcefNed : public CommandBase
{
public:
  inline static const char* const CmdName = "PushSpoofTxTrackEcefNed";
  inline static const char* const Documentation =
    "Push a spoofer transmitter track ECEF and NED attitude node. Must be called after BeginSpoofTxTrackDefinition and before EndSpoofTxTrackDefinition.\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ ---------------------------------------\n"
    "Time  int    Node Timestamp in miliseconds.\n"
    "X     double X distance from earth-center in meters.\n"
    "Y     double Y distance from earth-center in meters.\n"
    "Z     double Z distance from earth-center in meters.\n"
    "Yaw   double Yaw in radians.\n"
    "Pitch double Pitch in radians.\n"
    "Roll  double Roll in radians.\n"
    "Id    string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  PushSpoofTxTrackEcefNed() : CommandBase(CmdName, TargetId) {}

  PushSpoofTxTrackEcefNed(int time,
                          double x,
                          double y,
                          double z,
                          double yaw,
                          double pitch,
                          double roll,
                          const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setTime(time);
    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setId(id);
  }

  static PushSpoofTxTrackEcefNedPtr
  create(int time, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
  {
    return std::make_shared<PushSpoofTxTrackEcefNed>(time, x, y, z, yaw, pitch, roll, id);
  }

  static PushSpoofTxTrackEcefNedPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<PushSpoofTxTrackEcefNed>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Time"]) &&
           parse_json<double>::is_valid(m_values["X"]) && parse_json<double>::is_valid(m_values["Y"]) &&
           parse_json<double>::is_valid(m_values["Z"]) && parse_json<double>::is_valid(m_values["Yaw"]) &&
           parse_json<double>::is_valid(m_values["Pitch"]) && parse_json<double>::is_valid(m_values["Roll"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int time() const { return parse_json<int>::parse(m_values["Time"]); }

  void setTime(int time)
  {
    m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double x() const { return parse_json<double>::parse(m_values["X"]); }

  void setX(double x)
  {
    m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double y() const { return parse_json<double>::parse(m_values["Y"]); }

  void setY(double y)
  {
    m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double z() const { return parse_json<double>::parse(m_values["Z"]); }

  void setZ(double z)
  {
    m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(PushSpoofTxTrackEcefNed);
} // namespace Cmd
} // namespace Sdx
