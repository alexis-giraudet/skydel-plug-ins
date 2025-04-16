#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLogNmeaRate.
    ///
    /// Name Type Description
    /// ---- ---- ------------------------------
    /// Rate int  Accepted rates are 1 and 10 Hz
    ///

    class LogNmeaRateResult;
    typedef std::shared_ptr<LogNmeaRateResult> LogNmeaRateResultPtr;
    
    
    class LogNmeaRateResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "LogNmeaRateResult";
      inline static const char* const Documentation = "Result of GetLogNmeaRate.\n"      "\n"      "Name Type Description\n"      "---- ---- ------------------------------\n"      "Rate int  Accepted rates are 1 and 10 Hz";
      inline static const char* const TargetId = "";



          LogNmeaRateResult()
            : CommandResult(CmdName, TargetId)
          {}

          LogNmeaRateResult(int rate)
            : CommandResult(CmdName, TargetId)
          {

            setRate(rate);
          }

          LogNmeaRateResult(CommandBasePtr relatedCommand, int rate)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setRate(rate);
          }



          static LogNmeaRateResultPtr create(int rate)
          {
            return std::make_shared<LogNmeaRateResult>(rate);
          }

          static LogNmeaRateResultPtr create(CommandBasePtr relatedCommand, int rate)
          {
            return std::make_shared<LogNmeaRateResult>(relatedCommand, rate);
          }

      static LogNmeaRateResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<LogNmeaRateResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Rate"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Rate"}; 
        return names; 
      }
      


          int rate() const
          {
            return parse_json<int>::parse(m_values["Rate"]);
          }

          void setRate(int rate)
          {
            m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(LogNmeaRateResult);
  }
}

