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
/// Delete a vehicle antenna model. The default vehicle antenna model can't be deleted.
///
/// Name Type   Description
/// ---- ------ --------------------------
/// Name string Vehicle antenna model name
///

class DeleteVehicleAntennaModel;
typedef std::shared_ptr<DeleteVehicleAntennaModel> DeleteVehicleAntennaModelPtr;

class DeleteVehicleAntennaModel : public CommandBase
{
public:
  inline static const char* const CmdName = "DeleteVehicleAntennaModel";
  inline static const char* const Documentation =
    "Delete a vehicle antenna model. The default vehicle antenna model can't be deleted.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ --------------------------\n"
    "Name string Vehicle antenna model name";
  inline static const char* const TargetId = "";

  DeleteVehicleAntennaModel() : CommandBase(CmdName, TargetId) {}

  DeleteVehicleAntennaModel(const std::string& name) : CommandBase(CmdName, TargetId) { setName(name); }

  static DeleteVehicleAntennaModelPtr create(const std::string& name)
  {
    return std::make_shared<DeleteVehicleAntennaModel>(name);
  }

  static DeleteVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<DeleteVehicleAntennaModel>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Name"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string name() const { return parse_json<std::string>::parse(m_values["Name"]); }

  void setName(const std::string& name)
  {
    m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(DeleteVehicleAntennaModel);
} // namespace Cmd
} // namespace Sdx
