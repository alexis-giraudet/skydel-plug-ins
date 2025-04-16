#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get vehicle trajectory type
///
///
///

class GetVehicleTrajectory;
typedef std::shared_ptr<GetVehicleTrajectory> GetVehicleTrajectoryPtr;

class GetVehicleTrajectory : public CommandBase
{
public:
  inline static const char* const CmdName = "GetVehicleTrajectory";
  inline static const char* const Documentation = "Get vehicle trajectory type";
  inline static const char* const TargetId = "";

  GetVehicleTrajectory() : CommandBase(CmdName, TargetId) {}

  static GetVehicleTrajectoryPtr create() { return std::make_shared<GetVehicleTrajectory>(); }

  static GetVehicleTrajectoryPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleTrajectory>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectory);
} // namespace Cmd
} // namespace Sdx
