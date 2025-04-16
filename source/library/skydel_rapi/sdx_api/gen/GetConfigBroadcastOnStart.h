#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the main instance should send its configuration to every worker instance when simulation start.
    ///
    /// 
    ///

    class GetConfigBroadcastOnStart;
    typedef std::shared_ptr<GetConfigBroadcastOnStart> GetConfigBroadcastOnStartPtr;
    
    
    class GetConfigBroadcastOnStart : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetConfigBroadcastOnStart";
      inline static const char* const Documentation = "Get whether the main instance should send its configuration to every worker instance when simulation start.";
      inline static const char* const TargetId = "";



          GetConfigBroadcastOnStart()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetConfigBroadcastOnStartPtr create()
          {
            return std::make_shared<GetConfigBroadcastOnStart>();
          }

      static GetConfigBroadcastOnStartPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetConfigBroadcastOnStart>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetConfigBroadcastOnStart);
  }
}

