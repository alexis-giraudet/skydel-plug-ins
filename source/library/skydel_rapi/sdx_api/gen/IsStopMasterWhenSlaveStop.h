#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.
    /// 
    /// If enabled, master and all the slaves will stop if a slave stop.
    ///
    /// 
    ///

    class IsStopMasterWhenSlaveStop;
    typedef std::shared_ptr<IsStopMasterWhenSlaveStop> IsStopMasterWhenSlaveStopPtr;
    
    
    class IsStopMasterWhenSlaveStop : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsStopMasterWhenSlaveStop";
      inline static const char* const Documentation = "Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.\n"      "\n"      "If enabled, master and all the slaves will stop if a slave stop.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command IsStopMasterWhenSlaveStop is deprecated since 23.11. You may use IsStopMainInstanceWhenWorkerInstanceStop.";



          IsStopMasterWhenSlaveStop()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsStopMasterWhenSlaveStopPtr create()
          {
            return std::make_shared<IsStopMasterWhenSlaveStop>();
          }

      static IsStopMasterWhenSlaveStopPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsStopMasterWhenSlaveStop>(ptr);
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
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(IsStopMasterWhenSlaveStop);
  }
}

