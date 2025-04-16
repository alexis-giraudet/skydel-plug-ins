#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the default vehicle antenna model.
///
///
///

class GetDefaultVehicleAntennaModel;
typedef std::shared_ptr<GetDefaultVehicleAntennaModel> GetDefaultVehicleAntennaModelPtr;

class GetDefaultVehicleAntennaModel : public CommandBase
{
public:
  inline static const char* const CmdName = "GetDefaultVehicleAntennaModel";
  inline static const char* const Documentation = "Get the default vehicle antenna model.";
  inline static const char* const TargetId = "";

  GetDefaultVehicleAntennaModel() : CommandBase(CmdName, TargetId) {}

  static GetDefaultVehicleAntennaModelPtr create() { return std::make_shared<GetDefaultVehicleAntennaModel>(); }

  static GetDefaultVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetDefaultVehicleAntennaModel>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetDefaultVehicleAntennaModel);
} // namespace Cmd
} // namespace Sdx
