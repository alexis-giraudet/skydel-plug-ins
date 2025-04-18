#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetWFAntennaOffset.
///
/// Name  Type   Description
/// ----- ------ -----------------------------------------------
/// X     double WF Antenna X offset in the body frame (meter)
/// Y     double WF Antenna Y offset in the body frame (meter)
/// Z     double WF Antenna Z offset in the body frame (meter)
/// Yaw   double WF Antenna Yaw offset in the body frame (rad)
/// Pitch double WF Antenna Pitch offset in the body frame (rad)
/// Roll  double WF Antenna Roll offset in the body frame (rad)
///

class GetWFAntennaOffsetResult;
typedef std::shared_ptr<GetWFAntennaOffsetResult> GetWFAntennaOffsetResultPtr;

class GetWFAntennaOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetWFAntennaOffsetResult";
  inline static const char* const Documentation = "Result of GetWFAntennaOffset.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ -----------------------------------------------\n"
                                                  "X     double WF Antenna X offset in the body frame (meter)\n"
                                                  "Y     double WF Antenna Y offset in the body frame (meter)\n"
                                                  "Z     double WF Antenna Z offset in the body frame (meter)\n"
                                                  "Yaw   double WF Antenna Yaw offset in the body frame (rad)\n"
                                                  "Pitch double WF Antenna Pitch offset in the body frame (rad)\n"
                                                  "Roll  double WF Antenna Roll offset in the body frame (rad)";
  inline static const char* const TargetId = "";

  GetWFAntennaOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetWFAntennaOffsetResult(double x, double y, double z, double yaw, double pitch, double roll) :
    CommandResult(CmdName, TargetId)
  {

    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
  }

  GetWFAntennaOffsetResult(CommandBasePtr relatedCommand,
                           double x,
                           double y,
                           double z,
                           double yaw,
                           double pitch,
                           double roll) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
  }

  static GetWFAntennaOffsetResultPtr create(double x, double y, double z, double yaw, double pitch, double roll)
  {
    return std::make_shared<GetWFAntennaOffsetResult>(x, y, z, yaw, pitch, roll);
  }

  static GetWFAntennaOffsetResultPtr
  create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll)
  {
    return std::make_shared<GetWFAntennaOffsetResult>(relatedCommand, x, y, z, yaw, pitch, roll);
  }

  static GetWFAntennaOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetWFAntennaOffsetResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["X"]) &&
           parse_json<double>::is_valid(m_values["Y"]) && parse_json<double>::is_valid(m_values["Z"]) &&
           parse_json<double>::is_valid(m_values["Yaw"]) && parse_json<double>::is_valid(m_values["Pitch"]) &&
           parse_json<double>::is_valid(m_values["Roll"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll"};
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
};
REGISTER_COMMAND_TO_FACTORY(GetWFAntennaOffsetResult);
} // namespace Cmd
} // namespace Sdx
