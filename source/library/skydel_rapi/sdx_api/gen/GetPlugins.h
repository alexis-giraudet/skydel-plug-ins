#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get all Plug-ins present on the system (regardless of state).
///
///
///

class GetPlugins;
typedef std::shared_ptr<GetPlugins> GetPluginsPtr;

class GetPlugins : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPlugins";
  inline static const char* const Documentation = "Get all Plug-ins present on the system (regardless of state).";
  inline static const char* const TargetId = "";

  GetPlugins() : CommandBase(CmdName, TargetId) {}

  static GetPluginsPtr create() { return std::make_shared<GetPlugins>(); }

  static GetPluginsPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetPlugins>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetPlugins);
} // namespace Cmd
} // namespace Sdx
