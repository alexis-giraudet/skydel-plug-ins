#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns the status log in a GetStatusLogResult and clears it
    ///
    /// 
    ///

    class GetStatusLog;
    typedef std::shared_ptr<GetStatusLog> GetStatusLogPtr;
    
    
    class GetStatusLog : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetStatusLog";
      inline static const char* const Documentation = "Returns the status log in a GetStatusLogResult and clears it";
      inline static const char* const TargetId = "";



          GetStatusLog()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetStatusLogPtr create()
          {
            return std::make_shared<GetStatusLog>();
          }

      static GetStatusLogPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetStatusLog>(ptr);
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
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetStatusLog);
  }
}

