#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begins a new route definition. Actual route remains unchanged until
    /// EndRouteDefinition command is sent and successful. After this command, the
    /// client must push time and position pairs to form a complete route. Once all the
    /// positions are sent, the client must send the command EndRouteDefinition.
    ///
    /// 
    ///

    class BeginRouteDefinition;
    typedef std::shared_ptr<BeginRouteDefinition> BeginRouteDefinitionPtr;
    
    
    class BeginRouteDefinition : public CommandBase
    {
    public:
      inline static const char* const CmdName = "BeginRouteDefinition";
      inline static const char* const Documentation = "Begins a new route definition. Actual route remains unchanged until\n"      "EndRouteDefinition command is sent and successful. After this command, the\n"      "client must push time and position pairs to form a complete route. Once all the\n"      "positions are sent, the client must send the command EndRouteDefinition.";
      inline static const char* const TargetId = "";



          BeginRouteDefinition()
            : CommandBase(CmdName, TargetId)
          {

          }


          static BeginRouteDefinitionPtr create()
          {
            return std::make_shared<BeginRouteDefinition>();
          }

      static BeginRouteDefinitionPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<BeginRouteDefinition>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(BeginRouteDefinition);
  }
}

