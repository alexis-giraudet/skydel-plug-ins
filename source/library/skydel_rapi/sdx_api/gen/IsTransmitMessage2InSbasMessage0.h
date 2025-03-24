#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get whether SBAS should transmit message 2 instead of message 0.
///
///
///

class IsTransmitMessage2InSbasMessage0;
typedef std::shared_ptr<IsTransmitMessage2InSbasMessage0> IsTransmitMessage2InSbasMessage0Ptr;

class IsTransmitMessage2InSbasMessage0 : public CommandBase
{
public:
  inline static const char* const CmdName = "IsTransmitMessage2InSbasMessage0";
  inline static const char* const Documentation = "Get whether SBAS should transmit message 2 instead of message 0.";
  inline static const char* const TargetId = "";

  IsTransmitMessage2InSbasMessage0() : CommandBase(CmdName, TargetId) {}

  static IsTransmitMessage2InSbasMessage0Ptr create() { return std::make_shared<IsTransmitMessage2InSbasMessage0>(); }

  static IsTransmitMessage2InSbasMessage0Ptr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsTransmitMessage2InSbasMessage0>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsTransmitMessage2InSbasMessage0);
} // namespace Cmd
} // namespace Sdx
