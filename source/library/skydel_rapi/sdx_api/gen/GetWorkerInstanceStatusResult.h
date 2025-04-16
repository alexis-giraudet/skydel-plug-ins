#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWorkerInstanceStatus.
    ///
    /// Name             Type   Description
    /// ---------------- ------ ----------------------------------------------
    /// IsWorkerInstance bool   True if Skydel is in worker instance mode
    /// IsConnected      bool   True if Skydel is connected to a main instance
    /// HostName         string The host name, empty if not a worker instance
    /// HostPort         int    The host port, 0 if not a worker instance
    ///

    class GetWorkerInstanceStatusResult;
    typedef std::shared_ptr<GetWorkerInstanceStatusResult> GetWorkerInstanceStatusResultPtr;
    
    
    class GetWorkerInstanceStatusResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetWorkerInstanceStatusResult";
      inline static const char* const Documentation = "Result of GetWorkerInstanceStatus.\n"      "\n"      "Name             Type   Description\n"      "---------------- ------ ----------------------------------------------\n"      "IsWorkerInstance bool   True if Skydel is in worker instance mode\n"      "IsConnected      bool   True if Skydel is connected to a main instance\n"      "HostName         string The host name, empty if not a worker instance\n"      "HostPort         int    The host port, 0 if not a worker instance";
      inline static const char* const TargetId = "";



          GetWorkerInstanceStatusResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetWorkerInstanceStatusResult(bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
            : CommandResult(CmdName, TargetId)
          {

            setIsWorkerInstance(isWorkerInstance);
            setIsConnected(isConnected);
            setHostName(hostName);
            setHostPort(hostPort);
          }

          GetWorkerInstanceStatusResult(CommandBasePtr relatedCommand, bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIsWorkerInstance(isWorkerInstance);
            setIsConnected(isConnected);
            setHostName(hostName);
            setHostPort(hostPort);
          }



          static GetWorkerInstanceStatusResultPtr create(bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
          {
            return std::make_shared<GetWorkerInstanceStatusResult>(isWorkerInstance, isConnected, hostName, hostPort);
          }

          static GetWorkerInstanceStatusResultPtr create(CommandBasePtr relatedCommand, bool isWorkerInstance, bool isConnected, const std::string& hostName, int hostPort)
          {
            return std::make_shared<GetWorkerInstanceStatusResult>(relatedCommand, isWorkerInstance, isConnected, hostName, hostPort);
          }

      static GetWorkerInstanceStatusResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetWorkerInstanceStatusResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["IsWorkerInstance"])
                  && parse_json<bool>::is_valid(m_values["IsConnected"])
                  && parse_json<std::string>::is_valid(m_values["HostName"])
                  && parse_json<int>::is_valid(m_values["HostPort"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"IsWorkerInstance", "IsConnected", "HostName", "HostPort"}; 
        return names; 
      }
      


          bool isWorkerInstance() const
          {
            return parse_json<bool>::parse(m_values["IsWorkerInstance"]);
          }

          void setIsWorkerInstance(bool isWorkerInstance)
          {
            m_values.AddMember("IsWorkerInstance", parse_json<bool>::format(isWorkerInstance, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool isConnected() const
          {
            return parse_json<bool>::parse(m_values["IsConnected"]);
          }

          void setIsConnected(bool isConnected)
          {
            m_values.AddMember("IsConnected", parse_json<bool>::format(isConnected, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string hostName() const
          {
            return parse_json<std::string>::parse(m_values["HostName"]);
          }

          void setHostName(const std::string& hostName)
          {
            m_values.AddMember("HostName", parse_json<std::string>::format(hostName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int hostPort() const
          {
            return parse_json<int>::parse(m_values["HostPort"]);
          }

          void setHostPort(int hostPort)
          {
            m_values.AddMember("HostPort", parse_json<int>::format(hostPort, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetWorkerInstanceStatusResult);
  }
}

