#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Ask the main instance to broadcast its configuration to all worker instances.
///
///
///

class BroadcastConfig;
typedef std::shared_ptr<BroadcastConfig> BroadcastConfigPtr;

class BroadcastConfig : public CommandBase
{
public:
  inline static const char* const CmdName = "BroadcastConfig";
  inline static const char* const Documentation =
    "Ask the main instance to broadcast its configuration to all worker instances.";
  inline static const char* const TargetId = "";

  BroadcastConfig() : CommandBase(CmdName, TargetId) {}

  static BroadcastConfigPtr create() { return std::make_shared<BroadcastConfig>(); }

  static BroadcastConfigPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<BroadcastConfig>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(BroadcastConfig);
} // namespace Cmd
} // namespace Sdx
