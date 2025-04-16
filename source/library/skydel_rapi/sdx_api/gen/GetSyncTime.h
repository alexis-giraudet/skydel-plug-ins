#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get time delay to start streaming, in order to allign PPS out Signal with RF.
    /// 2000 ms is a calibrated value.
    ///
    /// 
    ///

    class GetSyncTime;
    typedef std::shared_ptr<GetSyncTime> GetSyncTimePtr;
    
    
    class GetSyncTime : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSyncTime";
      inline static const char* const Documentation = "Get time delay to start streaming, in order to allign PPS out Signal with RF.\n"      "2000 ms is a calibrated value.";
      inline static const char* const TargetId = "";



          GetSyncTime()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetSyncTimePtr create()
          {
            return std::make_shared<GetSyncTime>();
          }

      static GetSyncTimePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSyncTime>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetSyncTime);
  }
}

