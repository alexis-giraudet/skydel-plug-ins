#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Ask Skydel to reset its PPS counter.
///
///
///

class WaitAndResetPPS;
typedef std::shared_ptr<WaitAndResetPPS> WaitAndResetPPSPtr;

class WaitAndResetPPS : public CommandBase
{
public:
  inline static const char* const CmdName = "WaitAndResetPPS";
  inline static const char* const Documentation = "Ask Skydel to reset its PPS counter.";
  inline static const char* const TargetId = "";

  WaitAndResetPPS() : CommandBase(CmdName, TargetId) {}

  static WaitAndResetPPSPtr create() { return std::make_shared<WaitAndResetPPS>(); }

  static WaitAndResetPPSPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<WaitAndResetPPS>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(WaitAndResetPPS);
} // namespace Cmd
} // namespace Sdx
