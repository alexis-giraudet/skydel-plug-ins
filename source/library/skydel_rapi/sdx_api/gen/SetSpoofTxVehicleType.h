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
/// Set spoofer transmitter vehicle type for Track Trajectory.
///
/// Name Type   Description
/// ---- ------ -----------------------------------------------------------
/// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne").
/// Id   string Transmitter unique identifier.
///

class SetSpoofTxVehicleType;
typedef std::shared_ptr<SetSpoofTxVehicleType> SetSpoofTxVehicleTypePtr;

class SetSpoofTxVehicleType : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpoofTxVehicleType";
  inline static const char* const Documentation =
    "Set spoofer transmitter vehicle type for Track Trajectory.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ -----------------------------------------------------------\n"
    "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\").\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetSpoofTxVehicleType() : CommandBase(CmdName, TargetId) {}

  SetSpoofTxVehicleType(const std::string& type, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setType(type);
    setId(id);
  }

  static SetSpoofTxVehicleTypePtr create(const std::string& type, const std::string& id)
  {
    return std::make_shared<SetSpoofTxVehicleType>(type, id);
  }

  static SetSpoofTxVehicleTypePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpoofTxVehicleType>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSpoofTxVehicleType);
} // namespace Cmd
} // namespace Sdx
