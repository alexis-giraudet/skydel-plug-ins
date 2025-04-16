#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get vehicle static position and orientation
///
///
///

class GetVehicleTrajectoryFix;
typedef std::shared_ptr<GetVehicleTrajectoryFix> GetVehicleTrajectoryFixPtr;

class GetVehicleTrajectoryFix : public CommandBase
{
public:
  inline static const char* const CmdName = "GetVehicleTrajectoryFix";
  inline static const char* const Documentation = "Get vehicle static position and orientation";
  inline static const char* const TargetId = "";

  GetVehicleTrajectoryFix() : CommandBase(CmdName, TargetId) {}

  static GetVehicleTrajectoryFixPtr create() { return std::make_shared<GetVehicleTrajectoryFix>(); }

  static GetVehicleTrajectoryFixPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleTrajectoryFix>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryFix);
} // namespace Cmd
} // namespace Sdx
