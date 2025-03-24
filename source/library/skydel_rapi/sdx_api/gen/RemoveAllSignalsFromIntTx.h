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
/// Removes all signals from the interference transmitter.
///
/// Name          Type   Description
/// ------------- ------ ------------------------------
/// TransmitterId string Transmitter unique identifier.
///

class RemoveAllSignalsFromIntTx;
typedef std::shared_ptr<RemoveAllSignalsFromIntTx> RemoveAllSignalsFromIntTxPtr;

class RemoveAllSignalsFromIntTx : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveAllSignalsFromIntTx";
  inline static const char* const Documentation = "Removes all signals from the interference transmitter.\n"
                                                  "\n"
                                                  "Name          Type   Description\n"
                                                  "------------- ------ ------------------------------\n"
                                                  "TransmitterId string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  RemoveAllSignalsFromIntTx() : CommandBase(CmdName, TargetId) {}

  RemoveAllSignalsFromIntTx(const std::string& transmitterId) : CommandBase(CmdName, TargetId)
  {

    setTransmitterId(transmitterId);
  }

  static RemoveAllSignalsFromIntTxPtr create(const std::string& transmitterId)
  {
    return std::make_shared<RemoveAllSignalsFromIntTx>(transmitterId);
  }

  static RemoveAllSignalsFromIntTxPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveAllSignalsFromIntTx>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["TransmitterId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"TransmitterId"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::string transmitterId() const { return parse_json<std::string>::parse(m_values["TransmitterId"]); }

  void setTransmitterId(const std::string& transmitterId)
  {
    m_values.AddMember("TransmitterId",
                       parse_json<std::string>::format(transmitterId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RemoveAllSignalsFromIntTx);
} // namespace Cmd
} // namespace Sdx
