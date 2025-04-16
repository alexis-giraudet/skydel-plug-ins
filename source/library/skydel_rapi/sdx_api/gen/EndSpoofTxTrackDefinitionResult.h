#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// EndSpoofTxTrackDefinition Result with created track informations.
    ///
    /// Name  Type   Description
    /// ----- ------ ----------------------------------------------------------------------------------------------------
    /// Count int    Number of nodes in the track. The client can compare this value with the number of positions pushed.
    /// Id    string Transmitter unique identifier.
    ///

    class EndSpoofTxTrackDefinitionResult;
    typedef std::shared_ptr<EndSpoofTxTrackDefinitionResult> EndSpoofTxTrackDefinitionResultPtr;
    
    
    class EndSpoofTxTrackDefinitionResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "EndSpoofTxTrackDefinitionResult";
      inline static const char* const Documentation = "EndSpoofTxTrackDefinition Result with created track informations.\n"      "\n"      "Name  Type   Description\n"      "----- ------ ----------------------------------------------------------------------------------------------------\n"      "Count int    Number of nodes in the track. The client can compare this value with the number of positions pushed.\n"      "Id    string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          EndSpoofTxTrackDefinitionResult()
            : CommandResult(CmdName, TargetId)
          {}

          EndSpoofTxTrackDefinitionResult(int count, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setCount(count);
            setId(id);
          }

          EndSpoofTxTrackDefinitionResult(CommandBasePtr relatedCommand, int count, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setCount(count);
            setId(id);
          }



          static EndSpoofTxTrackDefinitionResultPtr create(int count, const std::string& id)
          {
            return std::make_shared<EndSpoofTxTrackDefinitionResult>(count, id);
          }

          static EndSpoofTxTrackDefinitionResultPtr create(CommandBasePtr relatedCommand, int count, const std::string& id)
          {
            return std::make_shared<EndSpoofTxTrackDefinitionResult>(relatedCommand, count, id);
          }

      static EndSpoofTxTrackDefinitionResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EndSpoofTxTrackDefinitionResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Count"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Count", "Id"}; 
        return names; 
      }
      


          int count() const
          {
            return parse_json<int>::parse(m_values["Count"]);
          }

          void setCount(int count)
          {
            m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(EndSpoofTxTrackDefinitionResult);
  }
}

