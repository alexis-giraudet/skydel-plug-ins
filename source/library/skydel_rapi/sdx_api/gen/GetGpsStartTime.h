#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the simulation GPS start date and time and leap second to convert into UTC time
    ///
    /// 
    ///

    class GetGpsStartTime;
    typedef std::shared_ptr<GetGpsStartTime> GetGpsStartTimePtr;
    
    
    class GetGpsStartTime : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGpsStartTime";
      inline static const char* const Documentation = "Get the simulation GPS start date and time and leap second to convert into UTC time";
      inline static const char* const TargetId = "";



          GetGpsStartTime()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetGpsStartTimePtr create()
          {
            return std::make_shared<GetGpsStartTime>();
          }

      static GetGpsStartTimePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpsStartTime>(ptr);
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
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetGpsStartTime);
  }
}

