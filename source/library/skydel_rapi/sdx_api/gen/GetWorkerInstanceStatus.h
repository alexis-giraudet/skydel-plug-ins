#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Request for the worker instance status, returns a GetWorkerInstanceStatusResult
    ///
    /// 
    ///

    class GetWorkerInstanceStatus;
    typedef std::shared_ptr<GetWorkerInstanceStatus> GetWorkerInstanceStatusPtr;
    
    
    class GetWorkerInstanceStatus : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetWorkerInstanceStatus";
      inline static const char* const Documentation = "Request for the worker instance status, returns a GetWorkerInstanceStatusResult";
      inline static const char* const TargetId = "";



          GetWorkerInstanceStatus()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetWorkerInstanceStatusPtr create()
          {
            return std::make_shared<GetWorkerInstanceStatus>();
          }

      static GetWorkerInstanceStatusPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetWorkerInstanceStatus>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetWorkerInstanceStatus);
  }
}

