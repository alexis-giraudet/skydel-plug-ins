#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsNtpClientEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------
    /// Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.
    ///

    class IsNtpClientEnabledResult;
    typedef std::shared_ptr<IsNtpClientEnabledResult> IsNtpClientEnabledResultPtr;
    
    
    class IsNtpClientEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsNtpClientEnabledResult";
      inline static const char* const Documentation = "Result of IsNtpClientEnabled.\n"      "\n"      "Name    Type Description\n"      "------- ---- --------------------------------------------------------------------------------\n"      "Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.";
      inline static const char* const TargetId = "";



          IsNtpClientEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsNtpClientEnabledResult(bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
          }

          IsNtpClientEnabledResult(CommandBasePtr relatedCommand, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
          }



          static IsNtpClientEnabledResultPtr create(bool enabled)
          {
            return std::make_shared<IsNtpClientEnabledResult>(enabled);
          }

          static IsNtpClientEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
          {
            return std::make_shared<IsNtpClientEnabledResult>(relatedCommand, enabled);
          }

      static IsNtpClientEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsNtpClientEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(IsNtpClientEnabledResult);
  }
}

