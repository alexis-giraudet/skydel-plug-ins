#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the connection parameters for the NTP Server from which the simulator will get the simulation start time.
    ///
    /// 
    ///

    class GetNtpServer;
    typedef std::shared_ptr<GetNtpServer> GetNtpServerPtr;
    
    
    class GetNtpServer : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetNtpServer";
      inline static const char* const Documentation = "Get the connection parameters for the NTP Server from which the simulator will get the simulation start time.";
      inline static const char* const TargetId = "";



          GetNtpServer()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetNtpServerPtr create()
          {
            return std::make_shared<GetNtpServer>();
          }

      static GetNtpServerPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetNtpServer>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetNtpServer);
  }
}

