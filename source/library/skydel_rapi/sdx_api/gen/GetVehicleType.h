#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get vehicle type for Route Trajectory
///
///
///

class GetVehicleType;
typedef std::shared_ptr<GetVehicleType> GetVehicleTypePtr;

class GetVehicleType : public CommandBase
{
public:
  inline static const char* const CmdName = "GetVehicleType";
  inline static const char* const Documentation = "Get vehicle type for Route Trajectory";
  inline static const char* const TargetId = "";

  GetVehicleType() : CommandBase(CmdName, TargetId) {}

  static GetVehicleTypePtr create() { return std::make_shared<GetVehicleType>(); }

  static GetVehicleTypePtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetVehicleType>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleType);
} // namespace Cmd
} // namespace Sdx
