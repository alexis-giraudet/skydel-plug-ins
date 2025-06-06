#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command SetWFAntennaElementOffset is deprecated since 23.11. You may use SetVehicleAntennaOffset.
///
/// Set WF antenna offset and orientation relative to CRPA Antenna frame for the specified element index.
///
/// Name    Type   Description
/// ------- ------ -------------------------------------------------------
/// X       double WF Element X offset in the CRPA antenna frame (meter)
/// Y       double WF Element Y offset in the CRPA antenna frame (meter)
/// Z       double WF Element Z offset in the CRPA antenna frame (meter)
/// Yaw     double WF Element Yaw offset in the CRPA antenna frame (rad)
/// Pitch   double WF Element Pitch offset in the CRPA antenna frame (rad)
/// Roll    double WF Element Roll offset in the CRPA antenna frame (rad)
/// Element int    One-based index for element in antenna.
///

class SetWFAntennaElementOffset;
typedef std::shared_ptr<SetWFAntennaElementOffset> SetWFAntennaElementOffsetPtr;

class SetWFAntennaElementOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "SetWFAntennaElementOffset";
  inline static const char* const Documentation =
    "Please note the command SetWFAntennaElementOffset is deprecated since 23.11. You may use SetVehicleAntennaOffset.\n"
    "\n"
    "Set WF antenna offset and orientation relative to CRPA Antenna frame for the specified element index.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ -------------------------------------------------------\n"
    "X       double WF Element X offset in the CRPA antenna frame (meter)\n"
    "Y       double WF Element Y offset in the CRPA antenna frame (meter)\n"
    "Z       double WF Element Z offset in the CRPA antenna frame (meter)\n"
    "Yaw     double WF Element Yaw offset in the CRPA antenna frame (rad)\n"
    "Pitch   double WF Element Pitch offset in the CRPA antenna frame (rad)\n"
    "Roll    double WF Element Roll offset in the CRPA antenna frame (rad)\n"
    "Element int    One-based index for element in antenna.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command SetWFAntennaElementOffset is deprecated since 23.11. You may use SetVehicleAntennaOffset.";

  SetWFAntennaElementOffset() : CommandBase(CmdName, TargetId) {}

  SetWFAntennaElementOffset(double x, double y, double z, double yaw, double pitch, double roll, int element) :
    CommandBase(CmdName, TargetId)
  {

    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setElement(element);
  }

  static SetWFAntennaElementOffsetPtr
  create(double x, double y, double z, double yaw, double pitch, double roll, int element)
  {
    return std::make_shared<SetWFAntennaElementOffset>(x, y, z, yaw, pitch, roll, element);
  }

  static SetWFAntennaElementOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetWFAntennaElementOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["X"]) &&
           parse_json<double>::is_valid(m_values["Y"]) && parse_json<double>::is_valid(m_values["Z"]) &&
           parse_json<double>::is_valid(m_values["Yaw"]) && parse_json<double>::is_valid(m_values["Pitch"]) &&
           parse_json<double>::is_valid(m_values["Roll"]) && parse_json<int>::is_valid(m_values["Element"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Element"};
    return names;
  }

  std::optional<std::string> deprecated() const { return std::optional<std::string> {Deprecated}; }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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

  int element() const { return parse_json<int>::parse(m_values["Element"]); }

  void setElement(int element)
  {
    m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetWFAntennaElementOffset);
} // namespace Cmd
} // namespace Sdx
