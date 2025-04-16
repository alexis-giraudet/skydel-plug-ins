#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// This command completes the track started with BeginIntTxTrackDefinition command. If
    /// the track is accepted, the current track in the configuration is replaced with
    /// this new track. If the track is not accepted, the current track in the config
    /// remains unchanged.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class EndIntTxTrackDefinition;
    typedef std::shared_ptr<EndIntTxTrackDefinition> EndIntTxTrackDefinitionPtr;
    
    
    class EndIntTxTrackDefinition : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EndIntTxTrackDefinition";
      inline static const char* const Documentation = "This command completes the track started with BeginIntTxTrackDefinition command. If\n"      "the track is accepted, the current track in the configuration is replaced with\n"      "this new track. If the track is not accepted, the current track in the config\n"      "remains unchanged.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          EndIntTxTrackDefinition()
            : CommandBase(CmdName, TargetId)
          {}

          EndIntTxTrackDefinition(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static EndIntTxTrackDefinitionPtr create(const std::string& id)
          {
            return std::make_shared<EndIntTxTrackDefinition>(id);
          }

      static EndIntTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EndIntTxTrackDefinition>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EndIntTxTrackDefinition);
  }
}

