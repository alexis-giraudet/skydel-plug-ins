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
/// Set an interference transmitter. If the transmitter ID parameter is not set (empty string),
/// Skydel will assign a unique ID to the transmitter. If the ID is set and already used by Skydel, the
/// command will fail.
///
/// Name      Type   Description
/// --------- ------ ----------------------------------------------------------------------------------------
/// UsualName string Usual name for the transmitter.
/// Enabled   bool   Enable (true) or disable (false) the transmitter
/// Group     int    Interference group number [1..16]
/// Dynamic   bool   Set to true for a dynamic transmitter (propagation loss and doppler shift are simulated)
/// Power     double Set the transmitter reference power
/// Id        string Transmitter unique identifier.
///

class AddIntTx;
typedef std::shared_ptr<AddIntTx> AddIntTxPtr;

class AddIntTx : public CommandBase
{
public:
  inline static const char* const CmdName = "AddIntTx";
  inline static const char* const Documentation =
    "Set an interference transmitter. If the transmitter ID parameter is not set (empty string),\n"
    "Skydel will assign a unique ID to the transmitter. If the ID is set and already used by Skydel, the\n"
    "command will fail.\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ ----------------------------------------------------------------------------------------\n"
    "UsualName string Usual name for the transmitter.\n"
    "Enabled   bool   Enable (true) or disable (false) the transmitter\n"
    "Group     int    Interference group number [1..16]\n"
    "Dynamic   bool   Set to true for a dynamic transmitter (propagation loss and doppler shift are simulated)\n"
    "Power     double Set the transmitter reference power\n"
    "Id        string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  AddIntTx() : CommandBase(CmdName, TargetId) {}

  AddIntTx(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setUsualName(usualName);
    setEnabled(enabled);
    setGroup(group);
    setDynamic(dynamic);
    setPower(power);
    setId(id);
  }

  static AddIntTxPtr create(const std::string& usualName,
                            bool enabled,
                            int group,
                            bool dynamic,
                            double power,
                            const std::string& id)
  {
    return std::make_shared<AddIntTx>(usualName, enabled, group, dynamic, power, id);
  }

  static AddIntTxPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<AddIntTx>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["UsualName"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]) && parse_json<int>::is_valid(m_values["Group"]) &&
           parse_json<bool>::is_valid(m_values["Dynamic"]) && parse_json<double>::is_valid(m_values["Power"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"UsualName", "Enabled", "Group", "Dynamic", "Power", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::string usualName() const { return parse_json<std::string>::parse(m_values["UsualName"]); }

  void setUsualName(const std::string& usualName)
  {
    m_values.AddMember("UsualName",
                       parse_json<std::string>::format(usualName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int group() const { return parse_json<int>::parse(m_values["Group"]); }

  void setGroup(int group)
  {
    m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool dynamic() const { return parse_json<bool>::parse(m_values["Dynamic"]); }

  void setDynamic(bool dynamic)
  {
    m_values.AddMember("Dynamic", parse_json<bool>::format(dynamic, m_values.GetAllocator()), m_values.GetAllocator());
  }

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
REGISTER_COMMAND_TO_FACTORY(AddIntTx);
} // namespace Cmd
} // namespace Sdx
