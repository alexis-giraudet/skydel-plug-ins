#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "date.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the next leap second event
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------
    /// Enabled bool If true, the future leap second event is set in the navigation message
    /// Seconds int  The future leap seconds value
    /// Date    date The event date
    ///

    class SetLeapSecondFuture;
    typedef std::shared_ptr<SetLeapSecondFuture> SetLeapSecondFuturePtr;
    
    
    class SetLeapSecondFuture : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetLeapSecondFuture";
      inline static const char* const Documentation = "Set the next leap second event\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------\n"      "Enabled bool If true, the future leap second event is set in the navigation message\n"      "Seconds int  The future leap seconds value\n"      "Date    date The event date";
      inline static const char* const TargetId = "";



          SetLeapSecondFuture()
            : CommandBase(CmdName, TargetId)
          {}

          SetLeapSecondFuture(bool enabled, int seconds, const Sdx::Date& date)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
            setSeconds(seconds);
            setDate(date);
          }


          static SetLeapSecondFuturePtr create(bool enabled, int seconds, const Sdx::Date& date)
          {
            return std::make_shared<SetLeapSecondFuture>(enabled, seconds, date);
          }

      static SetLeapSecondFuturePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetLeapSecondFuture>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<int>::is_valid(m_values["Seconds"])
                  && parse_json<Sdx::Date>::is_valid(m_values["Date"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "Seconds", "Date"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int seconds() const
          {
            return parse_json<int>::parse(m_values["Seconds"]);
          }

          void setSeconds(int seconds)
          {
            m_values.AddMember("Seconds", parse_json<int>::format(seconds, m_values.GetAllocator()), m_values.GetAllocator());
          }



          Sdx::Date date() const
          {
            return parse_json<Sdx::Date>::parse(m_values["Date"]);
          }

          void setDate(const Sdx::Date& date)
          {
            m_values.AddMember("Date", parse_json<Sdx::Date>::format(date, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetLeapSecondFuture);
  }
}

