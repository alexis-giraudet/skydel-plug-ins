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
/// Result of GetSlaveStatus.
///
/// Name        Type   Description
/// ----------- ------ ---------------------------------------
/// IsSlave     bool   True if Skydel is in slave mode
/// IsConnected bool   True if Skydel is connected to a master
/// HostName    string The host name, empty if not a slave
/// HostPort    int    The host port, 0 if not a slave
///

class GetSlaveStatusResult;
typedef std::shared_ptr<GetSlaveStatusResult> GetSlaveStatusResultPtr;

class GetSlaveStatusResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSlaveStatusResult";
  inline static const char* const Documentation = "Result of GetSlaveStatus.\n"
                                                  "\n"
                                                  "Name        Type   Description\n"
                                                  "----------- ------ ---------------------------------------\n"
                                                  "IsSlave     bool   True if Skydel is in slave mode\n"
                                                  "IsConnected bool   True if Skydel is connected to a master\n"
                                                  "HostName    string The host name, empty if not a slave\n"
                                                  "HostPort    int    The host port, 0 if not a slave";
  inline static const char* const TargetId = "";

  GetSlaveStatusResult() : CommandResult(CmdName, TargetId) {}

  GetSlaveStatusResult(bool isSlave, bool isConnected, const std::string& hostName, int hostPort) :
    CommandResult(CmdName, TargetId)
  {

    setIsSlave(isSlave);
    setIsConnected(isConnected);
    setHostName(hostName);
    setHostPort(hostPort);
  }

  GetSlaveStatusResult(CommandBasePtr relatedCommand,
                       bool isSlave,
                       bool isConnected,
                       const std::string& hostName,
                       int hostPort) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIsSlave(isSlave);
    setIsConnected(isConnected);
    setHostName(hostName);
    setHostPort(hostPort);
  }

  static GetSlaveStatusResultPtr create(bool isSlave, bool isConnected, const std::string& hostName, int hostPort)
  {
    return std::make_shared<GetSlaveStatusResult>(isSlave, isConnected, hostName, hostPort);
  }

  static GetSlaveStatusResultPtr create(CommandBasePtr relatedCommand,
                                        bool isSlave,
                                        bool isConnected,
                                        const std::string& hostName,
                                        int hostPort)
  {
    return std::make_shared<GetSlaveStatusResult>(relatedCommand, isSlave, isConnected, hostName, hostPort);
  }

  static GetSlaveStatusResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSlaveStatusResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["IsSlave"]) &&
           parse_json<bool>::is_valid(m_values["IsConnected"]) &&
           parse_json<std::string>::is_valid(m_values["HostName"]) && parse_json<int>::is_valid(m_values["HostPort"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IsSlave", "IsConnected", "HostName", "HostPort"};
    return names;
  }

  bool isSlave() const { return parse_json<bool>::parse(m_values["IsSlave"]); }

  void setIsSlave(bool isSlave)
  {
    m_values.AddMember("IsSlave", parse_json<bool>::format(isSlave, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool isConnected() const { return parse_json<bool>::parse(m_values["IsConnected"]); }

  void setIsConnected(bool isConnected)
  {
    m_values.AddMember("IsConnected",
                       parse_json<bool>::format(isConnected, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string hostName() const { return parse_json<std::string>::parse(m_values["HostName"]); }

  void setHostName(const std::string& hostName)
  {
    m_values.AddMember("HostName",
                       parse_json<std::string>::format(hostName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int hostPort() const { return parse_json<int>::parse(m_values["HostPort"]); }

  void setHostPort(int hostPort)
  {
    m_values.AddMember("HostPort", parse_json<int>::format(hostPort, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSlaveStatusResult);
} // namespace Cmd
} // namespace Sdx
