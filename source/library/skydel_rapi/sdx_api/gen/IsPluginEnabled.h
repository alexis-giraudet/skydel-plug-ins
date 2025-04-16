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
/// Get whether a plug-in is enabled for the whole system.
///
/// Name Type   Description
/// ---- ------ -----------
/// Id   string Plug-in ID.
///

class IsPluginEnabled;
typedef std::shared_ptr<IsPluginEnabled> IsPluginEnabledPtr;

class IsPluginEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsPluginEnabled";
  inline static const char* const Documentation = "Get whether a plug-in is enabled for the whole system.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ -----------\n"
                                                  "Id   string Plug-in ID.";
  inline static const char* const TargetId = "";

  IsPluginEnabled() : CommandBase(CmdName, TargetId) {}

  IsPluginEnabled(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static IsPluginEnabledPtr create(const std::string& id) { return std::make_shared<IsPluginEnabled>(id); }

  static IsPluginEnabledPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<IsPluginEnabled>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsPluginEnabled);
} // namespace Cmd
} // namespace Sdx
