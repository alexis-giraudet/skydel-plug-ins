#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the simulation start date and time
    ///
    /// Name  Type     Description
    /// ----- -------- --------------------------------------------------------------
    /// Start datetime GPS date and time (it is the GPS time expressed in UTC format)
    ///

    class SetGpsStartTime;
    typedef std::shared_ptr<SetGpsStartTime> SetGpsStartTimePtr;
    
    
    class SetGpsStartTime : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetGpsStartTime";
      inline static const char* const Documentation = "Set the simulation start date and time\n"      "\n"      "Name  Type     Description\n"      "----- -------- --------------------------------------------------------------\n"      "Start datetime GPS date and time (it is the GPS time expressed in UTC format)";
      inline static const char* const TargetId = "";



          SetGpsStartTime()
            : CommandBase(CmdName, TargetId)
          {}

          SetGpsStartTime(const Sdx::DateTime& start)
            : CommandBase(CmdName, TargetId)
          {

            setStart(start);
          }


          static SetGpsStartTimePtr create(const Sdx::DateTime& start)
          {
            return std::make_shared<SetGpsStartTime>(start);
          }

      static SetGpsStartTimePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetGpsStartTime>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::DateTime>::is_valid(m_values["Start"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Start"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          Sdx::DateTime start() const
          {
            return parse_json<Sdx::DateTime>::parse(m_values["Start"]);
          }

          void setStart(const Sdx::DateTime& start)
          {
            m_values.AddMember("Start", parse_json<Sdx::DateTime>::format(start, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetGpsStartTime);
  }
}

