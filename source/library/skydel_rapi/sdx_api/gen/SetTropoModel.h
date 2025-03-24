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
/// Set tropospheric model
///
/// Name  Type   Description
/// ----- ------ -----------------------------------------------------------------
/// Model string Tropospheric model ("None", "Saastamoinen", "Stanag" or "DO-229")
///

class SetTropoModel;
typedef std::shared_ptr<SetTropoModel> SetTropoModelPtr;

class SetTropoModel : public CommandBase
{
public:
  inline static const char* const CmdName = "SetTropoModel";
  inline static const char* const Documentation =
    "Set tropospheric model\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ -----------------------------------------------------------------\n"
    "Model string Tropospheric model (\"None\", \"Saastamoinen\", \"Stanag\" or \"DO-229\")";
  inline static const char* const TargetId = "";

  SetTropoModel() : CommandBase(CmdName, TargetId) {}

  SetTropoModel(const std::string& model) : CommandBase(CmdName, TargetId) { setModel(model); }

  static SetTropoModelPtr create(const std::string& model) { return std::make_shared<SetTropoModel>(model); }

  static SetTropoModelPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetTropoModel>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Model"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Model"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string model() const { return parse_json<std::string>::parse(m_values["Model"]); }

  void setModel(const std::string& model)
  {
    m_values.AddMember("Model",
                       parse_json<std::string>::format(model, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetTropoModel);
} // namespace Cmd
} // namespace Sdx
