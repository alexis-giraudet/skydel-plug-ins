#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command StopMasterWhenSlaveStop is deprecated since 23.11. You may use StopMainInstanceWhenWorkerInstanceStop.
    /// 
    /// If enabled, master and all the slaves will stop if a slave stop.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Enabled bool Enable master stop when slave fail flag
    ///

    class StopMasterWhenSlaveStop;
    typedef std::shared_ptr<StopMasterWhenSlaveStop> StopMasterWhenSlaveStopPtr;
    
    
    class StopMasterWhenSlaveStop : public CommandBase
    {
    public:
      inline static const char* const CmdName = "StopMasterWhenSlaveStop";
      inline static const char* const Documentation = "Please note the command StopMasterWhenSlaveStop is deprecated since 23.11. You may use StopMainInstanceWhenWorkerInstanceStop.\n"      "\n"      "If enabled, master and all the slaves will stop if a slave stop.\n"      "\n"      "Name    Type Description\n"      "------- ---- ---------------------------------------\n"      "Enabled bool Enable master stop when slave fail flag";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command StopMasterWhenSlaveStop is deprecated since 23.11. You may use StopMainInstanceWhenWorkerInstanceStop.";



          StopMasterWhenSlaveStop()
            : CommandBase(CmdName, TargetId)
          {}

          StopMasterWhenSlaveStop(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static StopMasterWhenSlaveStopPtr create(bool enabled)
          {
            return std::make_shared<StopMasterWhenSlaveStop>(enabled);
          }

      static StopMasterWhenSlaveStopPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<StopMasterWhenSlaveStop>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled"}; 
        return names; 
      }
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(StopMasterWhenSlaveStop);
  }
}

