#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "date.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLeapSecondFuture.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------
    /// Enabled bool If true, the future leap second event is set in the navigation message
    /// Seconds int  The future leap seconds value
    /// Date    date The event date
    ///

    class GetLeapSecondFutureResult;
    typedef std::shared_ptr<GetLeapSecondFutureResult> GetLeapSecondFutureResultPtr;
    
    
    class GetLeapSecondFutureResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetLeapSecondFutureResult";
      inline static const char* const Documentation = "Result of GetLeapSecondFuture.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------\n"      "Enabled bool If true, the future leap second event is set in the navigation message\n"      "Seconds int  The future leap seconds value\n"      "Date    date The event date";
      inline static const char* const TargetId = "";



          GetLeapSecondFutureResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetLeapSecondFutureResult(bool enabled, int seconds, const Sdx::Date& date)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
            setSeconds(seconds);
            setDate(date);
          }

          GetLeapSecondFutureResult(CommandBasePtr relatedCommand, bool enabled, int seconds, const Sdx::Date& date)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
            setSeconds(seconds);
            setDate(date);
          }



          static GetLeapSecondFutureResultPtr create(bool enabled, int seconds, const Sdx::Date& date)
          {
            return std::make_shared<GetLeapSecondFutureResult>(enabled, seconds, date);
          }

          static GetLeapSecondFutureResultPtr create(CommandBasePtr relatedCommand, bool enabled, int seconds, const Sdx::Date& date)
          {
            return std::make_shared<GetLeapSecondFutureResult>(relatedCommand, enabled, seconds, date);
          }

      static GetLeapSecondFutureResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetLeapSecondFutureResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetLeapSecondFutureResult);
  }
}

