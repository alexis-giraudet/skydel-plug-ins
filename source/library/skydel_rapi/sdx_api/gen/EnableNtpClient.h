#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) connections to an NTP server.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------
    /// Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.
    ///

    class EnableNtpClient;
    typedef std::shared_ptr<EnableNtpClient> EnableNtpClientPtr;
    
    
    class EnableNtpClient : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableNtpClient";
      inline static const char* const Documentation = "Enable (or disable) connections to an NTP server.\n"      "\n"      "Name    Type Description\n"      "------- ---- --------------------------------------------------------------------------------\n"      "Enabled bool If enabled, the NTP client will attempt to connect to the configured NTP server.";
      inline static const char* const TargetId = "";



          EnableNtpClient()
            : CommandBase(CmdName, TargetId)
          {}

          EnableNtpClient(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableNtpClientPtr create(bool enabled)
          {
            return std::make_shared<EnableNtpClient>(enabled);
          }

      static EnableNtpClientPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableNtpClient>(ptr);
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

    };
    REGISTER_COMMAND_TO_FACTORY(EnableNtpClient);
  }
}

