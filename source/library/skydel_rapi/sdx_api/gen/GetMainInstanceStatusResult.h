#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMainInstanceStatus.
    ///
    /// Name                    Type Description
    /// ----------------------- ---- --------------------------------------------
    /// IsMainInstance          bool True if Skydel is in main instance mode
    /// WorkerInstanceConnected int  The number of connected worker instances
    /// Port                    int  The listening port, 0 if not a main instance
    ///

    class GetMainInstanceStatusResult;
    typedef std::shared_ptr<GetMainInstanceStatusResult> GetMainInstanceStatusResultPtr;
    
    
    class GetMainInstanceStatusResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetMainInstanceStatusResult";
      inline static const char* const Documentation = "Result of GetMainInstanceStatus.\n"      "\n"      "Name                    Type Description\n"      "----------------------- ---- --------------------------------------------\n"      "IsMainInstance          bool True if Skydel is in main instance mode\n"      "WorkerInstanceConnected int  The number of connected worker instances\n"      "Port                    int  The listening port, 0 if not a main instance";
      inline static const char* const TargetId = "";



          GetMainInstanceStatusResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetMainInstanceStatusResult(bool isMainInstance, int workerInstanceConnected, int port)
            : CommandResult(CmdName, TargetId)
          {

            setIsMainInstance(isMainInstance);
            setWorkerInstanceConnected(workerInstanceConnected);
            setPort(port);
          }

          GetMainInstanceStatusResult(CommandBasePtr relatedCommand, bool isMainInstance, int workerInstanceConnected, int port)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIsMainInstance(isMainInstance);
            setWorkerInstanceConnected(workerInstanceConnected);
            setPort(port);
          }



          static GetMainInstanceStatusResultPtr create(bool isMainInstance, int workerInstanceConnected, int port)
          {
            return std::make_shared<GetMainInstanceStatusResult>(isMainInstance, workerInstanceConnected, port);
          }

          static GetMainInstanceStatusResultPtr create(CommandBasePtr relatedCommand, bool isMainInstance, int workerInstanceConnected, int port)
          {
            return std::make_shared<GetMainInstanceStatusResult>(relatedCommand, isMainInstance, workerInstanceConnected, port);
          }

      static GetMainInstanceStatusResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetMainInstanceStatusResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["IsMainInstance"])
                  && parse_json<int>::is_valid(m_values["WorkerInstanceConnected"])
                  && parse_json<int>::is_valid(m_values["Port"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"IsMainInstance", "WorkerInstanceConnected", "Port"}; 
        return names; 
      }
      


          bool isMainInstance() const
          {
            return parse_json<bool>::parse(m_values["IsMainInstance"]);
          }

          void setIsMainInstance(bool isMainInstance)
          {
            m_values.AddMember("IsMainInstance", parse_json<bool>::format(isMainInstance, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int workerInstanceConnected() const
          {
            return parse_json<int>::parse(m_values["WorkerInstanceConnected"]);
          }

          void setWorkerInstanceConnected(int workerInstanceConnected)
          {
            m_values.AddMember("WorkerInstanceConnected", parse_json<int>::format(workerInstanceConnected, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int port() const
          {
            return parse_json<int>::parse(m_values["Port"]);
          }

          void setPort(int port)
          {
            m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetMainInstanceStatusResult);
  }
}

