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
    /// Result of GetPlugins.
    ///
    /// Name    Type         Description
    /// ------- ------------ ---------------------------------------------------------------------
    /// Plugins array string List of all Plug-ins present on the system (regardless of the state).
    ///

    class GetPluginsResult;
    typedef std::shared_ptr<GetPluginsResult> GetPluginsResultPtr;
    
    
    class GetPluginsResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetPluginsResult";
      inline static const char* const Documentation = "Result of GetPlugins.\n"      "\n"      "Name    Type         Description\n"      "------- ------------ ---------------------------------------------------------------------\n"      "Plugins array string List of all Plug-ins present on the system (regardless of the state).";
      inline static const char* const TargetId = "";



          GetPluginsResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetPluginsResult(const std::vector<std::string>& plugins)
            : CommandResult(CmdName, TargetId)
          {

            setPlugins(plugins);
          }

          GetPluginsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& plugins)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setPlugins(plugins);
          }



          static GetPluginsResultPtr create(const std::vector<std::string>& plugins)
          {
            return std::make_shared<GetPluginsResult>(plugins);
          }

          static GetPluginsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& plugins)
          {
            return std::make_shared<GetPluginsResult>(relatedCommand, plugins);
          }

      static GetPluginsResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPluginsResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["Plugins"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Plugins"}; 
        return names; 
      }
      


          std::vector<std::string> plugins() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["Plugins"]);
          }

          void setPlugins(const std::vector<std::string>& plugins)
          {
            m_values.AddMember("Plugins", parse_json<std::vector<std::string>>::format(plugins, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPluginsResult);
  }
}

