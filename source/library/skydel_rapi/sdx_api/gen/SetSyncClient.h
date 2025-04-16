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
/// Set host and port to connect to sync time server.
///
/// Name Type   Description
/// ---- ------ ----------------
/// Host string Host address
/// Port int    Host port number
///

class SetSyncClient;
typedef std::shared_ptr<SetSyncClient> SetSyncClientPtr;

class SetSyncClient : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSyncClient";
  inline static const char* const Documentation = "Set host and port to connect to sync time server.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ----------------\n"
                                                  "Host string Host address\n"
                                                  "Port int    Host port number";
  inline static const char* const TargetId = "";

  SetSyncClient() : CommandBase(CmdName, TargetId) {}

  SetSyncClient(const std::string& host, int port) : CommandBase(CmdName, TargetId)
  {

    setHost(host);
    setPort(port);
  }

  static SetSyncClientPtr create(const std::string& host, int port)
  {
    return std::make_shared<SetSyncClient>(host, port);
  }

  static SetSyncClientPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetSyncClient>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Host"]) &&
           parse_json<int>::is_valid(m_values["Port"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Host", "Port"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  std::string host() const { return parse_json<std::string>::parse(m_values["Host"]); }

  void setHost(const std::string& host)
  {
    m_values.AddMember("Host", parse_json<std::string>::format(host, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int port() const { return parse_json<int>::parse(m_values["Port"]); }

  void setPort(int port)
  {
    m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSyncClient);
} // namespace Cmd
} // namespace Sdx
