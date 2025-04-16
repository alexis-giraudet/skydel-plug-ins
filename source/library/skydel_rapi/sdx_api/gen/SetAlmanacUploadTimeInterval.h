#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set almanac upload interval in seconds. After the initial upload set with command 
    /// SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.
    ///
    /// Name     Type   Description
    /// -------- ------ ----------------------------------------------------------
    /// System   string Must be "GPS"
    /// Interval int    Interval duration in sec. Accepted range is [3600..259200]
    ///

    class SetAlmanacUploadTimeInterval;
    typedef std::shared_ptr<SetAlmanacUploadTimeInterval> SetAlmanacUploadTimeIntervalPtr;
    
    
    class SetAlmanacUploadTimeInterval : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetAlmanacUploadTimeInterval";
      inline static const char* const Documentation = "Set almanac upload interval in seconds. After the initial upload set with command \n"      "SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ ----------------------------------------------------------\n"      "System   string Must be \"GPS\"\n"      "Interval int    Interval duration in sec. Accepted range is [3600..259200]";
      inline static const char* const TargetId = "";



          SetAlmanacUploadTimeInterval()
            : CommandBase(CmdName, TargetId)
          {}

          SetAlmanacUploadTimeInterval(const std::string& system, int interval)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setInterval(interval);
          }


          static SetAlmanacUploadTimeIntervalPtr create(const std::string& system, int interval)
          {
            return std::make_shared<SetAlmanacUploadTimeInterval>(system, interval);
          }

      static SetAlmanacUploadTimeIntervalPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetAlmanacUploadTimeInterval>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["Interval"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "Interval"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int interval() const
          {
            return parse_json<int>::parse(m_values["Interval"]);
          }

          void setInterval(int interval)
          {
            m_values.AddMember("Interval", parse_json<int>::format(interval, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetAlmanacUploadTimeInterval);
  }
}

