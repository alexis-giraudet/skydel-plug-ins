#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// This command completes the route started with BeginRouteDefinition command. If
/// the route is accepted, the current route in the configuration is replaced with
/// this new route. If the route is not accepted, the current route in the config
/// remains unchanged.
///
///
///

class EndRouteDefinition;
typedef std::shared_ptr<EndRouteDefinition> EndRouteDefinitionPtr;

class EndRouteDefinition : public CommandBase
{
public:
  inline static const char* const CmdName = "EndRouteDefinition";
  inline static const char* const Documentation =
    "This command completes the route started with BeginRouteDefinition command. If\n"
    "the route is accepted, the current route in the configuration is replaced with\n"
    "this new route. If the route is not accepted, the current route in the config\n"
    "remains unchanged.";
  inline static const char* const TargetId = "";

  EndRouteDefinition() : CommandBase(CmdName, TargetId) {}

  static EndRouteDefinitionPtr create() { return std::make_shared<EndRouteDefinition>(); }

  static EndRouteDefinitionPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EndRouteDefinition>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(EndRouteDefinition);
} // namespace Cmd
} // namespace Sdx
