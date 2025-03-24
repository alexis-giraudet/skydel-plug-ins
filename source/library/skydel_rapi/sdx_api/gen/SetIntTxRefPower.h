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
/// Set the interference transmitter reference power.
///
/// Name  Type   Description
/// ----- ------ ------------------------------
/// Power double Reference Power (dBm)
/// Id    string Transmitter unique identifier.
///

class SetIntTxRefPower;
typedef std::shared_ptr<SetIntTxRefPower> SetIntTxRefPowerPtr;

class SetIntTxRefPower : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIntTxRefPower";
  inline static const char* const Documentation = "Set the interference transmitter reference power.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------------\n"
                                                  "Power double Reference Power (dBm)\n"
                                                  "Id    string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetIntTxRefPower() : CommandBase(CmdName, TargetId) {}

  SetIntTxRefPower(double power, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setPower(power);
    setId(id);
  }

  static SetIntTxRefPowerPtr create(double power, const std::string& id)
  {
    return std::make_shared<SetIntTxRefPower>(power, id);
  }

  static SetIntTxRefPowerPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIntTxRefPower>(ptr);
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

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(SetIntTxRefPower);
} // namespace Cmd
} // namespace Sdx
