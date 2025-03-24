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
/// Rename a vehicle antenna model.
///
/// Name    Type   Description
/// ------- ------ ------------------------------------
/// Name    string Reference vehicle antenna model name
/// NewName string New vehicle antenna model name
///

class RenameVehicleAntennaModel;
typedef std::shared_ptr<RenameVehicleAntennaModel> RenameVehicleAntennaModelPtr;

class RenameVehicleAntennaModel : public CommandBase
{
public:
  inline static const char* const CmdName = "RenameVehicleAntennaModel";
  inline static const char* const Documentation = "Rename a vehicle antenna model.\n"
                                                  "\n"
                                                  "Name    Type   Description\n"
                                                  "------- ------ ------------------------------------\n"
                                                  "Name    string Reference vehicle antenna model name\n"
                                                  "NewName string New vehicle antenna model name";
  inline static const char* const TargetId = "";

  RenameVehicleAntennaModel() : CommandBase(CmdName, TargetId) {}

  RenameVehicleAntennaModel(const std::string& name, const std::string& newName) : CommandBase(CmdName, TargetId)
  {

    setName(name);
    setNewName(newName);
  }

  static RenameVehicleAntennaModelPtr create(const std::string& name, const std::string& newName)
  {
    return std::make_shared<RenameVehicleAntennaModel>(name, newName);
  }

  static RenameVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RenameVehicleAntennaModel>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Name"]) &&
           parse_json<std::string>::is_valid(m_values["NewName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Name", "NewName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string name() const { return parse_json<std::string>::parse(m_values["Name"]); }

  void setName(const std::string& name)
  {
    m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string newName() const { return parse_json<std::string>::parse(m_values["NewName"]); }

  void setNewName(const std::string& newName)
  {
    m_values.AddMember("NewName",
                       parse_json<std::string>::format(newName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RenameVehicleAntennaModel);
} // namespace Cmd
} // namespace Sdx
