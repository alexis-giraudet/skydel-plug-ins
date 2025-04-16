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
/// Set the address of the spoofer instance that will
/// generate the signal for this spoofer transmitter.
///
/// Name       Type   Description
/// ---------- ------ ------------------------------
/// Address    string Remote instance IP address.
/// InstanceId int    Remote instance ID.
/// Id         string Transmitter unique identifier.
///

class SetSpoofTxRemoteAddress;
typedef std::shared_ptr<SetSpoofTxRemoteAddress> SetSpoofTxRemoteAddressPtr;

class SetSpoofTxRemoteAddress : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpoofTxRemoteAddress";
  inline static const char* const Documentation = "Set the address of the spoofer instance that will\n"
                                                  "generate the signal for this spoofer transmitter.\n"
                                                  "\n"
                                                  "Name       Type   Description\n"
                                                  "---------- ------ ------------------------------\n"
                                                  "Address    string Remote instance IP address.\n"
                                                  "InstanceId int    Remote instance ID.\n"
                                                  "Id         string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetSpoofTxRemoteAddress() : CommandBase(CmdName, TargetId) {}

  SetSpoofTxRemoteAddress(const std::string& address, int instanceId, const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setAddress(address);
    setInstanceId(instanceId);
    setId(id);
  }

  static SetSpoofTxRemoteAddressPtr create(const std::string& address, int instanceId, const std::string& id)
  {
    return std::make_shared<SetSpoofTxRemoteAddress>(address, instanceId, id);
  }

  static SetSpoofTxRemoteAddressPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpoofTxRemoteAddress>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Address"]) &&
           parse_json<int>::is_valid(m_values["InstanceId"]) && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Address", "InstanceId", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(SetSpoofTxRemoteAddress);
} // namespace Cmd
} // namespace Sdx
