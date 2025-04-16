#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Request for the main instance status, returns a GetMainInstanceStatusResult
    ///
    /// 
    ///

    class GetMainInstanceStatus;
    typedef std::shared_ptr<GetMainInstanceStatus> GetMainInstanceStatusPtr;
    
    
    class GetMainInstanceStatus : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetMainInstanceStatus";
      inline static const char* const Documentation = "Request for the main instance status, returns a GetMainInstanceStatusResult";
      inline static const char* const TargetId = "";



          GetMainInstanceStatus()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetMainInstanceStatusPtr create()
          {
            return std::make_shared<GetMainInstanceStatus>();
          }

      static GetMainInstanceStatusPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetMainInstanceStatus>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetMainInstanceStatus);
  }
}

