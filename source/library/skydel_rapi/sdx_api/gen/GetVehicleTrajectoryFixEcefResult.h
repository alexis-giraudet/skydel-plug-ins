#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetVehicleTrajectoryFixEcef.
///
/// Name  Type   Description
/// ----- ------ -----------------------
/// Type  string Trajectory type ("Fix")
/// X     double ECEF X (m)
/// Y     double ECEF Y (m)
/// Z     double ECEF Z (m)
/// Yaw   double Yaw (rad)
/// Pitch double Pitch (rad)
/// Roll  double Roll (rad)
///

class GetVehicleTrajectoryFixEcefResult;
typedef std::shared_ptr<GetVehicleTrajectoryFixEcefResult> GetVehicleTrajectoryFixEcefResultPtr;

class GetVehicleTrajectoryFixEcefResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVehicleTrajectoryFixEcefResult";
  inline static const char* const Documentation = "Result of GetVehicleTrajectoryFixEcef.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ -----------------------\n"
                                                  "Type  string Trajectory type (\"Fix\")\n"
                                                  "X     double ECEF X (m)\n"
                                                  "Y     double ECEF Y (m)\n"
                                                  "Z     double ECEF Z (m)\n"
                                                  "Yaw   double Yaw (rad)\n"
                                                  "Pitch double Pitch (rad)\n"
                                                  "Roll  double Roll (rad)";
  inline static const char* const TargetId = "";

  GetVehicleTrajectoryFixEcefResult() : CommandResult(CmdName, TargetId) {}

  GetVehicleTrajectoryFixEcefResult(const std::string& type,
                                    double x,
                                    double y,
                                    double z,
                                    double yaw,
                                    double pitch,
                                    double roll) :
    CommandResult(CmdName, TargetId)
  {

    setType(type);
    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
  }

  GetVehicleTrajectoryFixEcefResult(CommandBasePtr relatedCommand,
                                    const std::string& type,
                                    double x,
                                    double y,
                                    double z,
                                    double yaw,
                                    double pitch,
                                    double roll) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setType(type);
    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
  }

  static GetVehicleTrajectoryFixEcefResultPtr
  create(const std::string& type, double x, double y, double z, double yaw, double pitch, double roll)
  {
    return std::make_shared<GetVehicleTrajectoryFixEcefResult>(type, x, y, z, yaw, pitch, roll);
  }

  static GetVehicleTrajectoryFixEcefResultPtr create(CommandBasePtr relatedCommand,
                                                     const std::string& type,
                                                     double x,
                                                     double y,
                                                     double z,
                                                     double yaw,
                                                     double pitch,
                                                     double roll)
  {
    return std::make_shared<GetVehicleTrajectoryFixEcefResult>(relatedCommand, type, x, y, z, yaw, pitch, roll);
  }

  static GetVehicleTrajectoryFixEcefResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleTrajectoryFixEcefResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]) &&
           parse_json<double>::is_valid(m_values["X"]) && parse_json<double>::is_valid(m_values["Y"]) &&
           parse_json<double>::is_valid(m_values["Z"]) && parse_json<double>::is_valid(m_values["Yaw"]) &&
           parse_json<double>::is_valid(m_values["Pitch"]) && parse_json<double>::is_valid(m_values["Roll"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type", "X", "Y", "Z", "Yaw", "Pitch", "Roll"};
    return names;
  }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
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
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryFixEcefResult);
} // namespace Cmd
} // namespace Sdx
