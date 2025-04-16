#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Disconnects the connected receiver. Does nothing if no receiver is connected.
///
///
///

class DisconnectSerialPortReceiver;
typedef std::shared_ptr<DisconnectSerialPortReceiver> DisconnectSerialPortReceiverPtr;

class DisconnectSerialPortReceiver : public CommandBase
{
public:
  inline static const char* const CmdName = "DisconnectSerialPortReceiver";
  inline static const char* const Documentation =
    "Disconnects the connected receiver. Does nothing if no receiver is connected.";
  inline static const char* const TargetId = "";

  DisconnectSerialPortReceiver() : CommandBase(CmdName, TargetId) {}

  static DisconnectSerialPortReceiverPtr create() { return std::make_shared<DisconnectSerialPortReceiver>(); }

  static DisconnectSerialPortReceiverPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<DisconnectSerialPortReceiver>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(DisconnectSerialPortReceiver);
} // namespace Cmd
} // namespace Sdx
