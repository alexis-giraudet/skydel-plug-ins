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
/// Set whether a spoofer should only use user-provided propagation loss values. Propagation loss will not update
/// automatically if set. This state is not preserved after simulation end.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------------
/// Manual bool   If true, propagation loss will be 1000 dB until set manually.
/// Id     string Spoofing transmitter unique identifier.
///

class SetSpoofTxUseManualPropagationLoss;
typedef std::shared_ptr<SetSpoofTxUseManualPropagationLoss> SetSpoofTxUseManualPropagationLossPtr;

class SetSpoofTxUseManualPropagationLoss : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpoofTxUseManualPropagationLoss";
  inline static const char* const Documentation =
    "Set whether a spoofer should only use user-provided propagation loss values. Propagation loss will not update automatically if set. This state is not preserved after simulation end.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------\n"
    "Manual bool   If true, propagation loss will be 1000 dB until set manually.\n"
    "Id     string Spoofing transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetSpoofTxUseManualPropagationLoss() : CommandBase(CmdName, TargetId) {}

  SetSpoofTxUseManualPropagationLoss(bool manual, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setManual(manual);
    setId(id);
  }

  static SetSpoofTxUseManualPropagationLossPtr create(bool manual, const std::string& id)
  {
    return std::make_shared<SetSpoofTxUseManualPropagationLoss>(manual, id);
  }

  static SetSpoofTxUseManualPropagationLossPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpoofTxUseManualPropagationLoss>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Manual"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Manual", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  bool manual() const { return parse_json<bool>::parse(m_values["Manual"]); }

  void setManual(bool manual)
  {
    m_values.AddMember("Manual", parse_json<bool>::format(manual, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSpoofTxUseManualPropagationLoss);
} // namespace Cmd
} // namespace Sdx
