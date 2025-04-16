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
    /// Result of GetLastLeapSecondDate.
    ///
    /// Name Type Description
    /// ---- ---- ----------------
    /// Date date Leap second date
    ///

    class GetLastLeapSecondDateResult;
    typedef std::shared_ptr<GetLastLeapSecondDateResult> GetLastLeapSecondDateResultPtr;
    
    
    class GetLastLeapSecondDateResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetLastLeapSecondDateResult";
      inline static const char* const Documentation = "Result of GetLastLeapSecondDate.\n"      "\n"      "Name Type Description\n"      "---- ---- ----------------\n"      "Date date Leap second date";
      inline static const char* const TargetId = "";



          GetLastLeapSecondDateResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetLastLeapSecondDateResult(const Sdx::Date& date)
            : CommandResult(CmdName, TargetId)
          {

            setDate(date);
          }

          GetLastLeapSecondDateResult(CommandBasePtr relatedCommand, const Sdx::Date& date)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setDate(date);
          }



          static GetLastLeapSecondDateResultPtr create(const Sdx::Date& date)
          {
            return std::make_shared<GetLastLeapSecondDateResult>(date);
          }

          static GetLastLeapSecondDateResultPtr create(CommandBasePtr relatedCommand, const Sdx::Date& date)
          {
            return std::make_shared<GetLastLeapSecondDateResult>(relatedCommand, date);
          }

      static GetLastLeapSecondDateResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetLastLeapSecondDateResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::Date>::is_valid(m_values["Date"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Date"}; 
        return names; 
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
    REGISTER_COMMAND_TO_FACTORY(GetLastLeapSecondDateResult);
  }
}

