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
/// Set ionospheric model
///
/// Name  Type   Description
/// ----- ------ ------------------------------------------------------------------
/// Model string Ionospheric model ("None", "Klobuchar", "Spacecraft" or "NeQuick")
///

class SetIonoModel;
typedef std::shared_ptr<SetIonoModel> SetIonoModelPtr;

class SetIonoModel : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIonoModel";
  inline static const char* const Documentation =
    "Set ionospheric model\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ ------------------------------------------------------------------\n"
    "Model string Ionospheric model (\"None\", \"Klobuchar\", \"Spacecraft\" or \"NeQuick\")";
  inline static const char* const TargetId = "";

  SetIonoModel() : CommandBase(CmdName, TargetId) {}

  SetIonoModel(const std::string& model) : CommandBase(CmdName, TargetId) { setModel(model); }

  static SetIonoModelPtr create(const std::string& model) { return std::make_shared<SetIonoModel>(model); }

  static SetIonoModelPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIonoModel>(ptr); }

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
REGISTER_COMMAND_TO_FACTORY(SetIonoModel);
} // namespace Cmd
} // namespace Sdx
