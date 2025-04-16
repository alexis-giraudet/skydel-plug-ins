#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIssueOfDataBeiDou.
    ///
    /// Name      Type Description
    /// --------- ---- ------------------------
    /// Clock     int  Issue of data, clock
    /// Ephemeris int  Issue of data, ephemeris
    ///

    class GetIssueOfDataBeiDouResult;
    typedef std::shared_ptr<GetIssueOfDataBeiDouResult> GetIssueOfDataBeiDouResultPtr;
    
    
    class GetIssueOfDataBeiDouResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIssueOfDataBeiDouResult";
      inline static const char* const Documentation = "Result of GetIssueOfDataBeiDou.\n"      "\n"      "Name      Type Description\n"      "--------- ---- ------------------------\n"      "Clock     int  Issue of data, clock\n"      "Ephemeris int  Issue of data, ephemeris";
      inline static const char* const TargetId = "";



          GetIssueOfDataBeiDouResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIssueOfDataBeiDouResult(int clock, int ephemeris)
            : CommandResult(CmdName, TargetId)
          {

            setClock(clock);
            setEphemeris(ephemeris);
          }

          GetIssueOfDataBeiDouResult(CommandBasePtr relatedCommand, int clock, int ephemeris)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setClock(clock);
            setEphemeris(ephemeris);
          }



          static GetIssueOfDataBeiDouResultPtr create(int clock, int ephemeris)
          {
            return std::make_shared<GetIssueOfDataBeiDouResult>(clock, ephemeris);
          }

          static GetIssueOfDataBeiDouResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris)
          {
            return std::make_shared<GetIssueOfDataBeiDouResult>(relatedCommand, clock, ephemeris);
          }

      static GetIssueOfDataBeiDouResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIssueOfDataBeiDouResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Clock"])
                  && parse_json<int>::is_valid(m_values["Ephemeris"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Clock", "Ephemeris"}; 
        return names; 
      }
      


          int clock() const
          {
            return parse_json<int>::parse(m_values["Clock"]);
          }

          void setClock(int clock)
          {
            m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int ephemeris() const
          {
            return parse_json<int>::parse(m_values["Ephemeris"]);
          }

          void setEphemeris(int ephemeris)
          {
            m_values.AddMember("Ephemeris", parse_json<int>::format(ephemeris, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataBeiDouResult);
  }
}

