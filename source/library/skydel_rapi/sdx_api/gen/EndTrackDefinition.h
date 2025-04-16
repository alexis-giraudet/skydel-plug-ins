#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// This command completes the track started with BeginTrackDefinition command. If
    /// the track is accepted, the current track in the configuration is replaced with
    /// this new track. If the track is not accepted, the current track in the config
    /// remains unchanged.
    ///
    /// 
    ///

    class EndTrackDefinition;
    typedef std::shared_ptr<EndTrackDefinition> EndTrackDefinitionPtr;
    
    
    class EndTrackDefinition : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EndTrackDefinition";
      inline static const char* const Documentation = "This command completes the track started with BeginTrackDefinition command. If\n"      "the track is accepted, the current track in the configuration is replaced with\n"      "this new track. If the track is not accepted, the current track in the config\n"      "remains unchanged.";
      inline static const char* const TargetId = "";



          EndTrackDefinition()
            : CommandBase(CmdName, TargetId)
          {

          }


          static EndTrackDefinitionPtr create()
          {
            return std::make_shared<EndTrackDefinition>();
          }

      static EndTrackDefinitionPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EndTrackDefinition>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EndTrackDefinition);
  }
}

