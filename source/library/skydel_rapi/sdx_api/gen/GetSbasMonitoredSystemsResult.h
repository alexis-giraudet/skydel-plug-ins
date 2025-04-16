#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasMonitoredSystems.
    ///
    /// Name    Type         Description
    /// ------- ------------ ------------------------------------------------------------------------------------
    /// Systems array string A list containing the name of monitored systems, only "GPS" and "SBAS" are supported
    ///

    class GetSbasMonitoredSystemsResult;
    typedef std::shared_ptr<GetSbasMonitoredSystemsResult> GetSbasMonitoredSystemsResultPtr;
    
    
    class GetSbasMonitoredSystemsResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSbasMonitoredSystemsResult";
      inline static const char* const Documentation = "Result of GetSbasMonitoredSystems.\n"      "\n"      "Name    Type         Description\n"      "------- ------------ ------------------------------------------------------------------------------------\n"      "Systems array string A list containing the name of monitored systems, only \"GPS\" and \"SBAS\" are supported";
      inline static const char* const TargetId = "";



          GetSbasMonitoredSystemsResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSbasMonitoredSystemsResult(const std::vector<std::string>& systems)
            : CommandResult(CmdName, TargetId)
          {

            setSystems(systems);
          }

          GetSbasMonitoredSystemsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& systems)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystems(systems);
          }



          static GetSbasMonitoredSystemsResultPtr create(const std::vector<std::string>& systems)
          {
            return std::make_shared<GetSbasMonitoredSystemsResult>(systems);
          }

          static GetSbasMonitoredSystemsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& systems)
          {
            return std::make_shared<GetSbasMonitoredSystemsResult>(relatedCommand, systems);
          }

      static GetSbasMonitoredSystemsResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSbasMonitoredSystemsResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["Systems"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Systems"}; 
        return names; 
      }
      


          std::vector<std::string> systems() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["Systems"]);
          }

          void setSystems(const std::vector<std::string>& systems)
          {
            m_values.AddMember("Systems", parse_json<std::vector<std::string>>::format(systems, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSbasMonitoredSystemsResult);
  }
}

