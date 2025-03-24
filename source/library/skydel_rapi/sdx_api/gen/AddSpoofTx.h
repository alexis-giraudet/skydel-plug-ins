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
/// Set a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),
/// Skydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the
/// command will fail.
///
/// Name       Type   Description
/// ---------- ------ ------------------------------------------------
/// UsualName  string Usual name for the transmitter.
/// Enabled    bool   Enable (true) or disable (false) the transmitter
/// Address    string Remote instance IP address.
/// InstanceId int    Remote instance ID.
/// Id         string Transmitter unique identifier.
///

class AddSpoofTx;
typedef std::shared_ptr<AddSpoofTx> AddSpoofTxPtr;

class AddSpoofTx : public CommandBase
{
public:
  inline static const char* const CmdName = "AddSpoofTx";
  inline static const char* const Documentation =
    "Set a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),\n"
    "Skydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the\n"
    "command will fail.\n"
    "\n"
    "Name       Type   Description\n"
    "---------- ------ ------------------------------------------------\n"
    "UsualName  string Usual name for the transmitter.\n"
    "Enabled    bool   Enable (true) or disable (false) the transmitter\n"
    "Address    string Remote instance IP address.\n"
    "InstanceId int    Remote instance ID.\n"
    "Id         string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  AddSpoofTx() : CommandBase(CmdName, TargetId) {}

  AddSpoofTx(const std::string& usualName,
             bool enabled,
             const std::string& address,
             int instanceId,
             const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setUsualName(usualName);
    setEnabled(enabled);
    setAddress(address);
    setInstanceId(instanceId);
    setId(id);
  }

  static AddSpoofTxPtr create(const std::string& usualName,
                              bool enabled,
                              const std::string& address,
                              int instanceId,
                              const std::string& id)
  {
    return std::make_shared<AddSpoofTx>(usualName, enabled, address, instanceId, id);
  }

  static AddSpoofTxPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<AddSpoofTx>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["UsualName"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]) && parse_json<std::string>::is_valid(m_values["Address"]) &&
           parse_json<int>::is_valid(m_values["InstanceId"]) && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"UsualName", "Enabled", "Address", "InstanceId", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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

  std::string address() const { return parse_json<std::string>::parse(m_values["Address"]); }

  void setAddress(const std::string& address)
  {
    m_values.AddMember("Address",
                       parse_json<std::string>::format(address, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int instanceId() const { return parse_json<int>::parse(m_values["InstanceId"]); }

  void setInstanceId(int instanceId)
  {
    m_values.AddMember("InstanceId",
                       parse_json<int>::format(instanceId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(AddSpoofTx);
} // namespace Cmd
} // namespace Sdx
