#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// EndRouteDefinition Result with created route informations.
    ///
    /// Name  Type Description
    /// ----- ---- ----------------------------------------------------------------------------------------------------
    /// Count int  Number of nodes in the route. The client can compare this value with the number of positions pushed.
    ///

    class EndRouteDefinitionResult;
    typedef std::shared_ptr<EndRouteDefinitionResult> EndRouteDefinitionResultPtr;
    
    
    class EndRouteDefinitionResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "EndRouteDefinitionResult";
      inline static const char* const Documentation = "EndRouteDefinition Result with created route informations.\n"      "\n"      "Name  Type Description\n"      "----- ---- ----------------------------------------------------------------------------------------------------\n"      "Count int  Number of nodes in the route. The client can compare this value with the number of positions pushed.";
      inline static const char* const TargetId = "";



          EndRouteDefinitionResult()
            : CommandResult(CmdName, TargetId)
          {}

          EndRouteDefinitionResult(int count)
            : CommandResult(CmdName, TargetId)
          {

            setCount(count);
          }

          EndRouteDefinitionResult(CommandBasePtr relatedCommand, int count)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setCount(count);
          }



          static EndRouteDefinitionResultPtr create(int count)
          {
            return std::make_shared<EndRouteDefinitionResult>(count);
          }

          static EndRouteDefinitionResultPtr create(CommandBasePtr relatedCommand, int count)
          {
            return std::make_shared<EndRouteDefinitionResult>(relatedCommand, count);
          }

      static EndRouteDefinitionResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EndRouteDefinitionResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Count"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Count"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(EndRouteDefinitionResult);
  }
}

