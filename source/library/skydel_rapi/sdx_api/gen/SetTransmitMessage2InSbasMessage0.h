#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set whether SBAS should transmit message 2 instead of message 0.
///
/// Name             Type Description
/// ---------------- ---- ---------------------------------------------------------
/// TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.
///

class SetTransmitMessage2InSbasMessage0;
typedef std::shared_ptr<SetTransmitMessage2InSbasMessage0> SetTransmitMessage2InSbasMessage0Ptr;

class SetTransmitMessage2InSbasMessage0 : public CommandBase
{
public:
  inline static const char* const CmdName = "SetTransmitMessage2InSbasMessage0";
  inline static const char* const Documentation =
    "Set whether SBAS should transmit message 2 instead of message 0.\n"
    "\n"
    "Name             Type Description\n"
    "---------------- ---- ---------------------------------------------------------\n"
    "TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.";
  inline static const char* const TargetId = "";

  SetTransmitMessage2InSbasMessage0() : CommandBase(CmdName, TargetId) {}

  SetTransmitMessage2InSbasMessage0(bool transmitMessage2) : CommandBase(CmdName, TargetId)
  {

    setTransmitMessage2(transmitMessage2);
  }

  static SetTransmitMessage2InSbasMessage0Ptr create(bool transmitMessage2)
  {
    return std::make_shared<SetTransmitMessage2InSbasMessage0>(transmitMessage2);
  }

  static SetTransmitMessage2InSbasMessage0Ptr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetTransmitMessage2InSbasMessage0>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["TransmitMessage2"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"TransmitMessage2"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  bool transmitMessage2() const { return parse_json<bool>::parse(m_values["TransmitMessage2"]); }

  void setTransmitMessage2(bool transmitMessage2)
  {
    m_values.AddMember("TransmitMessage2",
                       parse_json<bool>::format(transmitMessage2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetTransmitMessage2InSbasMessage0);
} // namespace Cmd
} // namespace Sdx
