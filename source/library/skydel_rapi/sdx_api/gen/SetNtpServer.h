#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the connection parameters for the NTP Server from which the simulator will get the simulation start time.
///
/// Name    Type         Description
/// ------- ------------ --------------------------------------------------------------------------------------
/// Address string       IP Address of the NTP server.
/// Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.
///

class SetNtpServer;
typedef std::shared_ptr<SetNtpServer> SetNtpServerPtr;

class SetNtpServer : public CommandBase
{
public:
  inline static const char* const CmdName = "SetNtpServer";
  inline static const char* const Documentation =
    "Set the connection parameters for the NTP Server from which the simulator will get the simulation start time.\n"
    "\n"
    "Name    Type         Description\n"
    "------- ------------ --------------------------------------------------------------------------------------\n"
    "Address string       IP Address of the NTP server.\n"
    "Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.";
  inline static const char* const TargetId = "";

  SetNtpServer() : CommandBase(CmdName, TargetId) {}

  SetNtpServer(const std::string& address, const std::optional<int>& port = {}) : CommandBase(CmdName, TargetId)
  {

    setAddress(address);
    setPort(port);
  }

  static SetNtpServerPtr create(const std::string& address, const std::optional<int>& port = {})
  {
    return std::make_shared<SetNtpServer>(address, port);
  }

  static SetNtpServerPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetNtpServer>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Address"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["Port"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Address", "Port"};
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

  std::optional<int> port() const { return parse_json<std::optional<int>>::parse(m_values["Port"]); }

  void setPort(const std::optional<int>& port)
  {
    m_values.AddMember("Port",
                       parse_json<std::optional<int>>::format(port, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetNtpServer);
} // namespace Cmd
} // namespace Sdx
