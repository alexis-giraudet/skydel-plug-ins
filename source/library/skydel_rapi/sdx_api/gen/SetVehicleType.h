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
/// Set vehicle type for Route Trajectory
///
/// Name Type   Description
/// ---- ------ ----------------------------------------------------------
/// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne")
///

class SetVehicleType;
typedef std::shared_ptr<SetVehicleType> SetVehicleTypePtr;

class SetVehicleType : public CommandBase
{
public:
  inline static const char* const CmdName = "SetVehicleType";
  inline static const char* const Documentation =
    "Set vehicle type for Route Trajectory\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ----------------------------------------------------------\n"
    "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\")";
  inline static const char* const TargetId = "";

  SetVehicleType() : CommandBase(CmdName, TargetId) {}

  SetVehicleType(const std::string& type) : CommandBase(CmdName, TargetId) { setType(type); }

  static SetVehicleTypePtr create(const std::string& type) { return std::make_shared<SetVehicleType>(type); }

  static SetVehicleTypePtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetVehicleType>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetVehicleType);
} // namespace Cmd
} // namespace Sdx
