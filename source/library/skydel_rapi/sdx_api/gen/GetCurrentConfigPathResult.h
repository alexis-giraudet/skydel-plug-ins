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
    /// Result of GetCurrentConfigPath.
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------------
    /// ConfigPath string The config file path currently used by Skydel.
    ///

    class GetCurrentConfigPathResult;
    typedef std::shared_ptr<GetCurrentConfigPathResult> GetCurrentConfigPathResultPtr;
    
    
    class GetCurrentConfigPathResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetCurrentConfigPathResult";
      inline static const char* const Documentation = "Result of GetCurrentConfigPath.\n"      "\n"      "Name       Type   Description\n"      "---------- ------ ----------------------------------------------\n"      "ConfigPath string The config file path currently used by Skydel.";
      inline static const char* const TargetId = "";



          GetCurrentConfigPathResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetCurrentConfigPathResult(const std::string& configPath)
            : CommandResult(CmdName, TargetId)
          {

            setConfigPath(configPath);
          }

          GetCurrentConfigPathResult(CommandBasePtr relatedCommand, const std::string& configPath)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setConfigPath(configPath);
          }



          static GetCurrentConfigPathResultPtr create(const std::string& configPath)
          {
            return std::make_shared<GetCurrentConfigPathResult>(configPath);
          }

          static GetCurrentConfigPathResultPtr create(CommandBasePtr relatedCommand, const std::string& configPath)
          {
            return std::make_shared<GetCurrentConfigPathResult>(relatedCommand, configPath);
          }

      static GetCurrentConfigPathResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCurrentConfigPathResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ConfigPath"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ConfigPath"}; 
        return names; 
      }
      


          std::string configPath() const
          {
            return parse_json<std::string>::parse(m_values["ConfigPath"]);
          }

          void setConfigPath(const std::string& configPath)
          {
            m_values.AddMember("ConfigPath", parse_json<std::string>::format(configPath, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetCurrentConfigPathResult);
  }
}

