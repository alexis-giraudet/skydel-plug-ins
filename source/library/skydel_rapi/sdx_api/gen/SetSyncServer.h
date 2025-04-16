#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set listening port for sync time server.
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// Port int  Listening port number
    ///

    class SetSyncServer;
    typedef std::shared_ptr<SetSyncServer> SetSyncServerPtr;
    
    
    class SetSyncServer : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSyncServer";
      inline static const char* const Documentation = "Set listening port for sync time server.\n"      "\n"      "Name Type Description\n"      "---- ---- ---------------------\n"      "Port int  Listening port number";
      inline static const char* const TargetId = "";



          SetSyncServer()
            : CommandBase(CmdName, TargetId)
          {}

          SetSyncServer(int port)
            : CommandBase(CmdName, TargetId)
          {

            setPort(port);
          }


          static SetSyncServerPtr create(int port)
          {
            return std::make_shared<SetSyncServer>(port);
          }

      static SetSyncServerPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSyncServer>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Port"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Port"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
          }


          int port() const
          {
            return parse_json<int>::parse(m_values["Port"]);
          }

          void setPort(int port)
          {
            m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetSyncServer);
  }
}

