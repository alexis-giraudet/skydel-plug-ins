#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Cancel the current configuration broadcast if any.
///
///
///

class CancelBroadcastConfig;
typedef std::shared_ptr<CancelBroadcastConfig> CancelBroadcastConfigPtr;

class CancelBroadcastConfig : public CommandBase
{
public:
  inline static const char* const CmdName = "CancelBroadcastConfig";
  inline static const char* const Documentation = "Cancel the current configuration broadcast if any.";
  inline static const char* const TargetId = "";

  CancelBroadcastConfig() : CommandBase(CmdName, TargetId) {}

  static CancelBroadcastConfigPtr create() { return std::make_shared<CancelBroadcastConfig>(); }

  static CancelBroadcastConfigPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<CancelBroadcastConfig>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(CancelBroadcastConfig);
} // namespace Cmd
} // namespace Sdx
