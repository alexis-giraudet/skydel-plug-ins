#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Begins a new track definition. Actual track remains unchanged until
    /// EndTrackDefinition command is sent and successful. After this command, the
    /// client must push time and position pairs to form a complete track. Once all the
    /// positions are sent, the client must send the command EndTrackDefinition.
    ///
    /// 
    ///

    class BeginTrackDefinition;
    typedef std::shared_ptr<BeginTrackDefinition> BeginTrackDefinitionPtr;
    
    
    class BeginTrackDefinition : public CommandBase
    {
    public:
      inline static const char* const CmdName = "BeginTrackDefinition";
      inline static const char* const Documentation = "Begins a new track definition. Actual track remains unchanged until\n"      "EndTrackDefinition command is sent and successful. After this command, the\n"      "client must push time and position pairs to form a complete track. Once all the\n"      "positions are sent, the client must send the command EndTrackDefinition.";
      inline static const char* const TargetId = "";



          BeginTrackDefinition()
            : CommandBase(CmdName, TargetId)
          {

          }


          static BeginTrackDefinitionPtr create()
          {
            return std::make_shared<BeginTrackDefinition>();
          }

      static BeginTrackDefinitionPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<BeginTrackDefinition>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(BeginTrackDefinition);
  }
}

