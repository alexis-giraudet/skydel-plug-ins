#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNtpServer.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------------------------------------------------------------------------
    /// Address string       IP Address of the NTP server.
    /// Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.
    ///

    class GetNtpServerResult;
    typedef std::shared_ptr<GetNtpServerResult> GetNtpServerResultPtr;
    
    
    class GetNtpServerResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetNtpServerResult";
      inline static const char* const Documentation = "Result of GetNtpServer.\n"      "\n"      "Name    Type         Description\n"      "------- ------------ --------------------------------------------------------------------------------------\n"      "Address string       IP Address of the NTP server.\n"      "Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.";
      inline static const char* const TargetId = "";



          GetNtpServerResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetNtpServerResult(const std::string& address, const std::optional<int>& port = {})
            : CommandResult(CmdName, TargetId)
          {

            setAddress(address);
            setPort(port);
          }

          GetNtpServerResult(CommandBasePtr relatedCommand, const std::string& address, const std::optional<int>& port = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setAddress(address);
            setPort(port);
          }



          static GetNtpServerResultPtr create(const std::string& address, const std::optional<int>& port = {})
          {
            return std::make_shared<GetNtpServerResult>(address, port);
          }

          static GetNtpServerResultPtr create(CommandBasePtr relatedCommand, const std::string& address, const std::optional<int>& port = {})
          {
            return std::make_shared<GetNtpServerResult>(relatedCommand, address, port);
          }

      static GetNtpServerResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetNtpServerResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Address"])
                  && parse_json<std::optional<int>>::is_valid(m_values["Port"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Address", "Port"}; 
        return names; 
      }
      


          std::string address() const
          {
            return parse_json<std::string>::parse(m_values["Address"]);
          }

          void setAddress(const std::string& address)
          {
            m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<int> port() const
          {
            return parse_json<std::optional<int>>::parse(m_values["Port"]);
          }

          void setPort(const std::optional<int>& port)
          {
            m_values.AddMember("Port", parse_json<std::optional<int>>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetNtpServerResult);
  }
}

