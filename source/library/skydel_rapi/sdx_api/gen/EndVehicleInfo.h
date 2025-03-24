#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// End receiving simulated vehicle informations.
///
///
///

class EndVehicleInfo;
typedef std::shared_ptr<EndVehicleInfo> EndVehicleInfoPtr;

class EndVehicleInfo : public CommandBase
{
public:
  inline static const char* const CmdName = "EndVehicleInfo";
  inline static const char* const Documentation = "End receiving simulated vehicle informations.";
  inline static const char* const TargetId = "";

  EndVehicleInfo() : CommandBase(CmdName, TargetId) {}

  static EndVehicleInfoPtr create() { return std::make_shared<EndVehicleInfo>(); }

  static EndVehicleInfoPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<EndVehicleInfo>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(EndVehicleInfo);
} // namespace Cmd
} // namespace Sdx
