#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set time delay to start streaming, in order to allign PPS out Signal with RF.
    /// 2000 ms is a calibrated value.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------
    /// Time double Time delay in msec (minimum is 500 msec)
    ///

    class SetSyncTime;
    typedef std::shared_ptr<SetSyncTime> SetSyncTimePtr;
    
    
    class SetSyncTime : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSyncTime";
      inline static const char* const Documentation = "Set time delay to start streaming, in order to allign PPS out Signal with RF.\n"      "2000 ms is a calibrated value.\n"      "\n"      "Name Type   Description\n"      "---- ------ ----------------------------------------\n"      "Time double Time delay in msec (minimum is 500 msec)";
      inline static const char* const TargetId = "";



          SetSyncTime()
            : CommandBase(CmdName, TargetId)
          {}

          SetSyncTime(double time)
            : CommandBase(CmdName, TargetId)
          {

            setTime(time);
          }


          static SetSyncTimePtr create(double time)
          {
            return std::make_shared<SetSyncTime>(time);
          }

      static SetSyncTimePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSyncTime>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(SetSyncTime);
  }
}

