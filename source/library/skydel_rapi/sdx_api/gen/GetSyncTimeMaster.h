#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSyncTimeMaster is deprecated since 23.11. You may use GetSyncTimeMainInstance.
    /// 
    /// Get time delay to start streaming after PPS synchronization. A value of 1500
    /// means the simulation will start streaming 1.5 sec after the PPS used for
    /// synchornization.
    ///
    /// 
    ///

    class GetSyncTimeMaster;
    typedef std::shared_ptr<GetSyncTimeMaster> GetSyncTimeMasterPtr;
    
    
    class GetSyncTimeMaster : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSyncTimeMaster";
      inline static const char* const Documentation = "Please note the command GetSyncTimeMaster is deprecated since 23.11. You may use GetSyncTimeMainInstance.\n"      "\n"      "Get time delay to start streaming after PPS synchronization. A value of 1500\n"      "means the simulation will start streaming 1.5 sec after the PPS used for\n"      "synchornization.";
      inline static const char* const TargetId = "";



          GetSyncTimeMaster()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetSyncTimeMasterPtr create()
          {
            return std::make_shared<GetSyncTimeMaster>();
          }

      static GetSyncTimeMasterPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSyncTimeMaster>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetSyncTimeMaster);
  }
}

