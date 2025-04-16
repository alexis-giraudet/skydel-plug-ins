#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsTransmitMessage2InSbasMessage0.
///
/// Name             Type Description
/// ---------------- ---- ---------------------------------------------------------
/// TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.
///

class IsTransmitMessage2InSbasMessage0Result;
typedef std::shared_ptr<IsTransmitMessage2InSbasMessage0Result> IsTransmitMessage2InSbasMessage0ResultPtr;

class IsTransmitMessage2InSbasMessage0Result : public CommandResult
{
public:
  inline static const char* const CmdName = "IsTransmitMessage2InSbasMessage0Result";
  inline static const char* const Documentation =
    "Result of IsTransmitMessage2InSbasMessage0.\n"
    "\n"
    "Name             Type Description\n"
    "---------------- ---- ---------------------------------------------------------\n"
    "TransmitMessage2 bool Whether SBAS should transmit message type 2 instead of 0.";
  inline static const char* const TargetId = "";

  IsTransmitMessage2InSbasMessage0Result() : CommandResult(CmdName, TargetId) {}

  IsTransmitMessage2InSbasMessage0Result(bool transmitMessage2) : CommandResult(CmdName, TargetId)
  {

    setTransmitMessage2(transmitMessage2);
  }

  IsTransmitMessage2InSbasMessage0Result(CommandBasePtr relatedCommand, bool transmitMessage2) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setTransmitMessage2(transmitMessage2);
  }

  static IsTransmitMessage2InSbasMessage0ResultPtr create(bool transmitMessage2)
  {
    return std::make_shared<IsTransmitMessage2InSbasMessage0Result>(transmitMessage2);
  }

  static IsTransmitMessage2InSbasMessage0ResultPtr create(CommandBasePtr relatedCommand, bool transmitMessage2)
  {
    return std::make_shared<IsTransmitMessage2InSbasMessage0Result>(relatedCommand, transmitMessage2);
  }

  static IsTransmitMessage2InSbasMessage0ResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsTransmitMessage2InSbasMessage0Result>(ptr);
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

  bool transmitMessage2() const { return parse_json<bool>::parse(m_values["TransmitMessage2"]); }

  void setTransmitMessage2(bool transmitMessage2)
  {
    m_values.AddMember("TransmitMessage2",
                       parse_json<bool>::format(transmitMessage2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsTransmitMessage2InSbasMessage0Result);
} // namespace Cmd
} // namespace Sdx
