#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Begin receiving simulated vehicle informations.
/// During simulation, you must call RemoteSimulator.lastVehicleInfo to get current simulation statistics or
/// RemoteSimulator.nextVehicleInfo to get pending simulation statistics
///
///
///

class BeginVehicleInfo;
typedef std::shared_ptr<BeginVehicleInfo> BeginVehicleInfoPtr;

class BeginVehicleInfo : public CommandBase
{
public:
  inline static const char* const CmdName = "BeginVehicleInfo";
  inline static const char* const Documentation =
    "Begin receiving simulated vehicle informations. \n"
    "During simulation, you must call RemoteSimulator.lastVehicleInfo to get current simulation statistics or RemoteSimulator.nextVehicleInfo to get pending simulation statistics";
  inline static const char* const TargetId = "";

  BeginVehicleInfo() : CommandBase(CmdName, TargetId) {}

  static BeginVehicleInfoPtr create() { return std::make_shared<BeginVehicleInfo>(); }

  static BeginVehicleInfoPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<BeginVehicleInfo>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(BeginVehicleInfo);
} // namespace Cmd
} // namespace Sdx
