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
/// Result of GetVehicleAntennaOffset.
///
/// Name  Type            Description
/// ----- --------------- --------------------------------------------
/// X     double          Antenna X offset in the body frame (meter)
/// Y     double          Antenna Y offset in the body frame (meter)
/// Z     double          Antenna Z offset in the body frame (meter)
/// Yaw   double          Antenna Yaw offset in the body frame (rad)
/// Pitch double          Antenna Pitch offset in the body frame (rad)
/// Roll  double          Antenna Roll offset in the body frame (rad)
/// Name  optional string Unique vehicle antenna name
///

class GetVehicleAntennaOffsetResult;
typedef std::shared_ptr<GetVehicleAntennaOffsetResult> GetVehicleAntennaOffsetResultPtr;

class GetVehicleAntennaOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVehicleAntennaOffsetResult";
  inline static const char* const Documentation = "Result of GetVehicleAntennaOffset.\n"
                                                  "\n"
                                                  "Name  Type            Description\n"
                                                  "----- --------------- --------------------------------------------\n"
                                                  "X     double          Antenna X offset in the body frame (meter)\n"
                                                  "Y     double          Antenna Y offset in the body frame (meter)\n"
                                                  "Z     double          Antenna Z offset in the body frame (meter)\n"
                                                  "Yaw   double          Antenna Yaw offset in the body frame (rad)\n"
                                                  "Pitch double          Antenna Pitch offset in the body frame (rad)\n"
                                                  "Roll  double          Antenna Roll offset in the body frame (rad)\n"
                                                  "Name  optional string Unique vehicle antenna name";
  inline static const char* const TargetId = "";

  GetVehicleAntennaOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetVehicleAntennaOffsetResult(double x,
                                double y,
                                double z,
                                double yaw,
                                double pitch,
                                double roll,
                                const std::optional<std::string>& name = {}) :
    CommandResult(CmdName, TargetId)
  {

    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setName(name);
  }

  GetVehicleAntennaOffsetResult(CommandBasePtr relatedCommand,
                                double x,
                                double y,
                                double z,
                                double yaw,
                                double pitch,
                                double roll,
                                const std::optional<std::string>& name = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setName(name);
  }

  static GetVehicleAntennaOffsetResultPtr create(double x,
                                                 double y,
                                                 double z,
                                                 double yaw,
                                                 double pitch,
                                                 double roll,
                                                 const std::optional<std::string>& name = {})
  {
    return std::make_shared<GetVehicleAntennaOffsetResult>(x, y, z, yaw, pitch, roll, name);
  }

  static GetVehicleAntennaOffsetResultPtr create(CommandBasePtr relatedCommand,
                                                 double x,
                                                 double y,
                                                 double z,
                                                 double yaw,
                                                 double pitch,
                                                 double roll,
                                                 const std::optional<std::string>& name = {})
  {
    return std::make_shared<GetVehicleAntennaOffsetResult>(relatedCommand, x, y, z, yaw, pitch, roll, name);
  }

  static GetVehicleAntennaOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleAntennaOffsetResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["X"]) &&
           parse_json<double>::is_valid(m_values["Y"]) && parse_json<double>::is_valid(m_values["Z"]) &&
           parse_json<double>::is_valid(m_values["Yaw"]) && parse_json<double>::is_valid(m_values["Pitch"]) &&
           parse_json<double>::is_valid(m_values["Roll"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Name"};
    return names;
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

  std::optional<std::string> name() const { return parse_json<std::optional<std::string>>::parse(m_values["Name"]); }

  void setName(const std::optional<std::string>& name)
  {
    m_values.AddMember("Name",
                       parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaOffsetResult);
} // namespace Cmd
} // namespace Sdx
