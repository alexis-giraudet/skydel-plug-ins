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
/// Enable a plug-in for the whole system.
///
/// Name    Type   Description
/// ------- ------ --------------------------------------------------------------------------
/// Id      string Plug-in ID.
/// Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).
///

class EnablePlugin;
typedef std::shared_ptr<EnablePlugin> EnablePluginPtr;

class EnablePlugin : public CommandBase
{
public:
  inline static const char* const CmdName = "EnablePlugin";
  inline static const char* const Documentation =
    "Enable a plug-in for the whole system.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------\n"
    "Id      string Plug-in ID.\n"
    "Enabled bool   Whether the plug-in is enabled for the whole system (true) or not (false).";
  inline static const char* const TargetId = "";

  EnablePlugin() : CommandBase(CmdName, TargetId) {}

  EnablePlugin(const std::string& id, bool enabled) : CommandBase(CmdName, TargetId)
  {

    setId(id);
    setEnabled(enabled);
  }

  static EnablePluginPtr create(const std::string& id, bool enabled)
  {
    return std::make_shared<EnablePlugin>(id, enabled);
  }

  static EnablePluginPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<EnablePlugin>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id", "Enabled"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnablePlugin);
} // namespace Cmd
} // namespace Sdx
