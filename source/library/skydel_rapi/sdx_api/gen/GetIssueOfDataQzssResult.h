#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIssueOfDataQzss.
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------
    /// Clock         int           Issue of data, clock
    /// Ephemeris     int           Issue of data, ephemeris
    /// OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True
    ///

    class GetIssueOfDataQzssResult;
    typedef std::shared_ptr<GetIssueOfDataQzssResult> GetIssueOfDataQzssResultPtr;
    
    
    class GetIssueOfDataQzssResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIssueOfDataQzssResult";
      inline static const char* const Documentation = "Result of GetIssueOfDataQzss.\n"      "\n"      "Name          Type          Description\n"      "------------- ------------- ---------------------------------------------------\n"      "Clock         int           Issue of data, clock\n"      "Ephemeris     int           Issue of data, ephemeris\n"      "OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True";
      inline static const char* const TargetId = "";



          GetIssueOfDataQzssResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIssueOfDataQzssResult(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {})
            : CommandResult(CmdName, TargetId)
          {

            setClock(clock);
            setEphemeris(ephemeris);
            setOverrideRinex(overrideRinex);
          }

          GetIssueOfDataQzssResult(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setClock(clock);
            setEphemeris(ephemeris);
            setOverrideRinex(overrideRinex);
          }



          static GetIssueOfDataQzssResultPtr create(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {})
          {
            return std::make_shared<GetIssueOfDataQzssResult>(clock, ephemeris, overrideRinex);
          }

          static GetIssueOfDataQzssResultPtr create(CommandBasePtr relatedCommand, int clock, int ephemeris, const std::optional<bool>& overrideRinex = {})
          {
            return std::make_shared<GetIssueOfDataQzssResult>(relatedCommand, clock, ephemeris, overrideRinex);
          }

      static GetIssueOfDataQzssResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIssueOfDataQzssResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Clock"])
                  && parse_json<int>::is_valid(m_values["Ephemeris"])
                  && parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Clock", "Ephemeris", "OverrideRinex"}; 
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



          std::optional<bool> overrideRinex() const
          {
            return parse_json<std::optional<bool>>::parse(m_values["OverrideRinex"]);
          }

          void setOverrideRinex(const std::optional<bool>& overrideRinex)
          {
            m_values.AddMember("OverrideRinex", parse_json<std::optional<bool>>::format(overrideRinex, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataQzssResult);
  }
}

