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
/// Result of GetVehicleTrajectory.
///
/// Name Type   Description
/// ---- ------ -----------------------------------------------------------------------
/// Type string Trajectory type ("Fix", "Circular", "HIL", "Track", "Route" or "Orbit")
///

class GetVehicleTrajectoryResult;
typedef std::shared_ptr<GetVehicleTrajectoryResult> GetVehicleTrajectoryResultPtr;

class GetVehicleTrajectoryResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVehicleTrajectoryResult";
  inline static const char* const Documentation =
    "Result of GetVehicleTrajectory.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ -----------------------------------------------------------------------\n"
    "Type string Trajectory type (\"Fix\", \"Circular\", \"HIL\", \"Track\", \"Route\" or \"Orbit\")";
  inline static const char* const TargetId = "";

  GetVehicleTrajectoryResult() : CommandResult(CmdName, TargetId) {}

  GetVehicleTrajectoryResult(const std::string& type) : CommandResult(CmdName, TargetId) { setType(type); }

  GetVehicleTrajectoryResult(CommandBasePtr relatedCommand, const std::string& type) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setType(type);
  }

  static GetVehicleTrajectoryResultPtr create(const std::string& type)
  {
    return std::make_shared<GetVehicleTrajectoryResult>(type);
  }

  static GetVehicleTrajectoryResultPtr create(CommandBasePtr relatedCommand, const std::string& type)
  {
    return std::make_shared<GetVehicleTrajectoryResult>(relatedCommand, type);
  }

  static GetVehicleTrajectoryResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleTrajectoryResult>(ptr);
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

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryResult);
} // namespace Cmd
} // namespace Sdx
