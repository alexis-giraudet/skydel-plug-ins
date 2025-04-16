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
/// Set the spoofing transmitter reference power.
///
/// Name  Type   Description
/// ----- ------ ------------------------------
/// Power double Reference Power (dBm)
/// Id    string Transmitter unique identifier.
///

class SetSpoofTxRefPower;
typedef std::shared_ptr<SetSpoofTxRefPower> SetSpoofTxRefPowerPtr;

class SetSpoofTxRefPower : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpoofTxRefPower";
  inline static const char* const Documentation = "Set the spoofing transmitter reference power.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------------\n"
                                                  "Power double Reference Power (dBm)\n"
                                                  "Id    string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetSpoofTxRefPower() : CommandBase(CmdName, TargetId) {}

  SetSpoofTxRefPower(double power, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setPower(power);
    setId(id);
  }

  static SetSpoofTxRefPowerPtr create(double power, const std::string& id)
  {
    return std::make_shared<SetSpoofTxRefPower>(power, id);
  }

  static SetSpoofTxRefPowerPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpoofTxRefPower>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Power"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Power", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  double power() const { return parse_json<double>::parse(m_values["Power"]); }

  void setPower(double power)
  {
    m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSpoofTxRefPower);
} // namespace Cmd
} // namespace Sdx
