#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetStartTimeMode.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------------------------------
    /// Mode string Accepted Modes ("Custom", "Computer", "GPS", "NTP")
    ///

    class GetStartTimeModeResult;
    typedef std::shared_ptr<GetStartTimeModeResult> GetStartTimeModeResultPtr;
    
    
    class GetStartTimeModeResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetStartTimeModeResult";
      inline static const char* const Documentation = "Result of GetStartTimeMode.\n"      "\n"      "Name Type   Description\n"      "---- ------ ---------------------------------------------------\n"      "Mode string Accepted Modes (\"Custom\", \"Computer\", \"GPS\", \"NTP\")";
      inline static const char* const TargetId = "";



          GetStartTimeModeResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetStartTimeModeResult(const std::string& mode)
            : CommandResult(CmdName, TargetId)
          {

            setMode(mode);
          }

          GetStartTimeModeResult(CommandBasePtr relatedCommand, const std::string& mode)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setMode(mode);
          }



          static GetStartTimeModeResultPtr create(const std::string& mode)
          {
            return std::make_shared<GetStartTimeModeResult>(mode);
          }

          static GetStartTimeModeResultPtr create(CommandBasePtr relatedCommand, const std::string& mode)
          {
            return std::make_shared<GetStartTimeModeResult>(relatedCommand, mode);
          }

      static GetStartTimeModeResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetStartTimeModeResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Mode"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Mode"}; 
        return names; 
      }
      


          std::string mode() const
          {
            return parse_json<std::string>::parse(m_values["Mode"]);
          }

          void setMode(const std::string& mode)
          {
            m_values.AddMember("Mode", parse_json<std::string>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetStartTimeModeResult);
  }
}

