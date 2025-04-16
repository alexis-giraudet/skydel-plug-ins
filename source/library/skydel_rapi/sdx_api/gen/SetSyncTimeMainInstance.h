#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set time delay to start streaming after PPS synchronization. A value of 1500
    /// means the simulation will start streaming 1.5 sec after the PPS used for
    /// synchornization.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class SetSyncTimeMainInstance;
    typedef std::shared_ptr<SetSyncTimeMainInstance> SetSyncTimeMainInstancePtr;
    
    
    class SetSyncTimeMainInstance : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSyncTimeMainInstance";
      inline static const char* const Documentation = "Set time delay to start streaming after PPS synchronization. A value of 1500\n"      "means the simulation will start streaming 1.5 sec after the PPS used for\n"      "synchornization.\n"      "\n"      "Name Type   Description\n"      "---- ------ ----------------------------------------\n"      "Time double Time delay in msec (minimum is 500 msec)";
      inline static const char* const TargetId = "";



          SetSyncTimeMainInstance()
            : CommandBase(CmdName, TargetId)
          {}

          SetSyncTimeMainInstance(double time)
            : CommandBase(CmdName, TargetId)
          {

            setTime(time);
          }


          static SetSyncTimeMainInstancePtr create(double time)
          {
            return std::make_shared<SetSyncTimeMainInstance>(time);
          }

      static SetSyncTimeMainInstancePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSyncTimeMainInstance>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["Time"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Time"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          double time() const
          {
            return parse_json<double>::parse(m_values["Time"]);
          }

          void setTime(double time)
          {
            m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetSyncTimeMainInstance);
  }
}

