#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/ConfigFilter.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetConfigBroadcastFilter.
    ///
    /// Name   Type               Description
    /// ------ ------------------ ------------------------------------------------------------------------------
    /// Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.
    ///

    class GetConfigBroadcastFilterResult;
    typedef std::shared_ptr<GetConfigBroadcastFilterResult> GetConfigBroadcastFilterResultPtr;
    
    
    class GetConfigBroadcastFilterResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetConfigBroadcastFilterResult";
      inline static const char* const Documentation = "Result of GetConfigBroadcastFilter.\n"      "\n"      "Name   Type               Description\n"      "------ ------------------ ------------------------------------------------------------------------------\n"      "Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.";
      inline static const char* const TargetId = "";



          GetConfigBroadcastFilterResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetConfigBroadcastFilterResult(const std::vector<Sdx::ConfigFilter>& filter)
            : CommandResult(CmdName, TargetId)
          {

            setFilter(filter);
          }

          GetConfigBroadcastFilterResult(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setFilter(filter);
          }



          static GetConfigBroadcastFilterResultPtr create(const std::vector<Sdx::ConfigFilter>& filter)
          {
            return std::make_shared<GetConfigBroadcastFilterResult>(filter);
          }

          static GetConfigBroadcastFilterResultPtr create(CommandBasePtr relatedCommand, const std::vector<Sdx::ConfigFilter>& filter)
          {
            return std::make_shared<GetConfigBroadcastFilterResult>(relatedCommand, filter);
          }

      static GetConfigBroadcastFilterResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetConfigBroadcastFilterResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<Sdx::ConfigFilter>>::is_valid(m_values["Filter"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Filter"}; 
        return names; 
      }
      


          std::vector<Sdx::ConfigFilter> filter() const
          {
            return parse_json<std::vector<Sdx::ConfigFilter>>::parse(m_values["Filter"]);
          }

          void setFilter(const std::vector<Sdx::ConfigFilter>& filter)
          {
            m_values.AddMember("Filter", parse_json<std::vector<Sdx::ConfigFilter>>::format(filter, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetConfigBroadcastFilterResult);
  }
}

