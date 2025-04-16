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
    /// Result of GetIssueOfDataNavIC.
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -------------------------------------------------------
    /// EphemerisAndClock int           Issue of data, ephemeris and clock
    /// OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True
    ///

    class GetIssueOfDataNavICResult;
    typedef std::shared_ptr<GetIssueOfDataNavICResult> GetIssueOfDataNavICResultPtr;
    
    
    class GetIssueOfDataNavICResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIssueOfDataNavICResult";
      inline static const char* const Documentation = "Result of GetIssueOfDataNavIC.\n"      "\n"      "Name              Type          Description\n"      "----------------- ------------- -------------------------------------------------------\n"      "EphemerisAndClock int           Issue of data, ephemeris and clock\n"      "OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True";
      inline static const char* const TargetId = "";



          GetIssueOfDataNavICResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIssueOfDataNavICResult(int ephemerisAndClock, const std::optional<bool>& overrideRinex = {})
            : CommandResult(CmdName, TargetId)
          {

            setEphemerisAndClock(ephemerisAndClock);
            setOverrideRinex(overrideRinex);
          }

          GetIssueOfDataNavICResult(CommandBasePtr relatedCommand, int ephemerisAndClock, const std::optional<bool>& overrideRinex = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEphemerisAndClock(ephemerisAndClock);
            setOverrideRinex(overrideRinex);
          }



          static GetIssueOfDataNavICResultPtr create(int ephemerisAndClock, const std::optional<bool>& overrideRinex = {})
          {
            return std::make_shared<GetIssueOfDataNavICResult>(ephemerisAndClock, overrideRinex);
          }

          static GetIssueOfDataNavICResultPtr create(CommandBasePtr relatedCommand, int ephemerisAndClock, const std::optional<bool>& overrideRinex = {})
          {
            return std::make_shared<GetIssueOfDataNavICResult>(relatedCommand, ephemerisAndClock, overrideRinex);
          }

      static GetIssueOfDataNavICResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIssueOfDataNavICResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["EphemerisAndClock"])
                  && parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"EphemerisAndClock", "OverrideRinex"}; 
        return names; 
      }
      


          int ephemerisAndClock() const
          {
            return parse_json<int>::parse(m_values["EphemerisAndClock"]);
          }

          void setEphemerisAndClock(int ephemerisAndClock)
          {
            m_values.AddMember("EphemerisAndClock", parse_json<int>::format(ephemerisAndClock, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataNavICResult);
  }
}

