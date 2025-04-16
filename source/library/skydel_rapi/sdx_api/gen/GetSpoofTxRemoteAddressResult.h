#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSpoofTxRemoteAddress.
///
/// Name       Type   Description
/// ---------- ------ ------------------------------
/// Address    string Remote instance IP address.
/// InstanceId int    Remote instance ID.
/// Id         string Transmitter unique identifier.
///

class GetSpoofTxRemoteAddressResult;
typedef std::shared_ptr<GetSpoofTxRemoteAddressResult> GetSpoofTxRemoteAddressResultPtr;

class GetSpoofTxRemoteAddressResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSpoofTxRemoteAddressResult";
  inline static const char* const Documentation = "Result of GetSpoofTxRemoteAddress.\n"
                                                  "\n"
                                                  "Name       Type   Description\n"
                                                  "---------- ------ ------------------------------\n"
                                                  "Address    string Remote instance IP address.\n"
                                                  "InstanceId int    Remote instance ID.\n"
                                                  "Id         string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetSpoofTxRemoteAddressResult() : CommandResult(CmdName, TargetId) {}

  GetSpoofTxRemoteAddressResult(const std::string& address, int instanceId, const std::string& id) :
    CommandResult(CmdName, TargetId)
  {

    setAddress(address);
    setInstanceId(instanceId);
    setId(id);
  }

  GetSpoofTxRemoteAddressResult(CommandBasePtr relatedCommand,
                                const std::string& address,
                                int instanceId,
                                const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setAddress(address);
    setInstanceId(instanceId);
    setId(id);
  }

  static GetSpoofTxRemoteAddressResultPtr create(const std::string& address, int instanceId, const std::string& id)
  {
    return std::make_shared<GetSpoofTxRemoteAddressResult>(address, instanceId, id);
  }

  static GetSpoofTxRemoteAddressResultPtr create(CommandBasePtr relatedCommand,
                                                 const std::string& address,
                                                 int instanceId,
                                                 const std::string& id)
  {
    return std::make_shared<GetSpoofTxRemoteAddressResult>(relatedCommand, address, instanceId, id);
  }

  static GetSpoofTxRemoteAddressResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSpoofTxRemoteAddressResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSpoofTxRemoteAddressResult);
} // namespace Cmd
} // namespace Sdx
