#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetMasterStatus.
///
/// Name           Type Description
/// -------------- ---- -------------------------------------
/// IsMaster       bool True if Skydel is in master mode
/// SlaveConnected int  The number of connected slaves
/// Port           int  The listening port, 0 if not a master
///

class GetMasterStatusResult;
typedef std::shared_ptr<GetMasterStatusResult> GetMasterStatusResultPtr;

class GetMasterStatusResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetMasterStatusResult";
  inline static const char* const Documentation = "Result of GetMasterStatus.\n"
                                                  "\n"
                                                  "Name           Type Description\n"
                                                  "-------------- ---- -------------------------------------\n"
                                                  "IsMaster       bool True if Skydel is in master mode\n"
                                                  "SlaveConnected int  The number of connected slaves\n"
                                                  "Port           int  The listening port, 0 if not a master";
  inline static const char* const TargetId = "";

  GetMasterStatusResult() : CommandResult(CmdName, TargetId) {}

  GetMasterStatusResult(bool isMaster, int slaveConnected, int port) : CommandResult(CmdName, TargetId)
  {

    setIsMaster(isMaster);
    setSlaveConnected(slaveConnected);
    setPort(port);
  }

  GetMasterStatusResult(CommandBasePtr relatedCommand, bool isMaster, int slaveConnected, int port) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIsMaster(isMaster);
    setSlaveConnected(slaveConnected);
    setPort(port);
  }

  static GetMasterStatusResultPtr create(bool isMaster, int slaveConnected, int port)
  {
    return std::make_shared<GetMasterStatusResult>(isMaster, slaveConnected, port);
  }

  static GetMasterStatusResultPtr create(CommandBasePtr relatedCommand, bool isMaster, int slaveConnected, int port)
  {
    return std::make_shared<GetMasterStatusResult>(relatedCommand, isMaster, slaveConnected, port);
  }

  static GetMasterStatusResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMasterStatusResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["IsMaster"]) &&
           parse_json<int>::is_valid(m_values["SlaveConnected"]) && parse_json<int>::is_valid(m_values["Port"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IsMaster", "SlaveConnected", "Port"};
    return names;
  }

  bool isMaster() const { return parse_json<bool>::parse(m_values["IsMaster"]); }

  void setIsMaster(bool isMaster)
  {
    m_values.AddMember("IsMaster",
                       parse_json<bool>::format(isMaster, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int slaveConnected() const { return parse_json<int>::parse(m_values["SlaveConnected"]); }

  void setSlaveConnected(int slaveConnected)
  {
    m_values.AddMember("SlaveConnected",
                       parse_json<int>::format(slaveConnected, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int port() const { return parse_json<int>::parse(m_values["Port"]); }

  void setPort(int port)
  {
    m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMasterStatusResult);
} // namespace Cmd
} // namespace Sdx
