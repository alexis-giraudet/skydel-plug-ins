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
/// Set vehicle trajectory type
///
/// Name Type   Description
/// ---- ------ -----------------------------------------------------------------------
/// Type string Trajectory type ("Fix", "Circular", "HIL", "Track", "Route" or "Orbit")
///

class SetVehicleTrajectory;
typedef std::shared_ptr<SetVehicleTrajectory> SetVehicleTrajectoryPtr;

class SetVehicleTrajectory : public CommandBase
{
public:
  inline static const char* const CmdName = "SetVehicleTrajectory";
  inline static const char* const Documentation =
    "Set vehicle trajectory type\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ -----------------------------------------------------------------------\n"
    "Type string Trajectory type (\"Fix\", \"Circular\", \"HIL\", \"Track\", \"Route\" or \"Orbit\")";
  inline static const char* const TargetId = "";

  SetVehicleTrajectory() : CommandBase(CmdName, TargetId) {}

  SetVehicleTrajectory(const std::string& type) : CommandBase(CmdName, TargetId) { setType(type); }

  static SetVehicleTrajectoryPtr create(const std::string& type)
  {
    return std::make_shared<SetVehicleTrajectory>(type);
  }

  static SetVehicleTrajectoryPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetVehicleTrajectory>(ptr);
  }

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
REGISTER_COMMAND_TO_FACTORY(SetVehicleTrajectory);
} // namespace Cmd
} // namespace Sdx
