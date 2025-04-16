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
    /// Result of GetConfigPaths.
    ///
    /// Name  Type         Description
    /// ----- ------------ --------------------------------
    /// Paths array string Paths of the configuration files
    ///

    class GetConfigPathsResult;
    typedef std::shared_ptr<GetConfigPathsResult> GetConfigPathsResultPtr;
    
    
    class GetConfigPathsResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetConfigPathsResult";
      inline static const char* const Documentation = "Result of GetConfigPaths.\n"      "\n"      "Name  Type         Description\n"      "----- ------------ --------------------------------\n"      "Paths array string Paths of the configuration files";
      inline static const char* const TargetId = "";



          GetConfigPathsResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetConfigPathsResult(const std::vector<std::string>& paths)
            : CommandResult(CmdName, TargetId)
          {

            setPaths(paths);
          }

          GetConfigPathsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& paths)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setPaths(paths);
          }



          static GetConfigPathsResultPtr create(const std::vector<std::string>& paths)
          {
            return std::make_shared<GetConfigPathsResult>(paths);
          }

          static GetConfigPathsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& paths)
          {
            return std::make_shared<GetConfigPathsResult>(relatedCommand, paths);
          }

      static GetConfigPathsResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetConfigPathsResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["Paths"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Paths"}; 
        return names; 
      }
      


          std::vector<std::string> paths() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["Paths"]);
          }

          void setPaths(const std::vector<std::string>& paths)
          {
            m_values.AddMember("Paths", parse_json<std::vector<std::string>>::format(paths, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetConfigPathsResult);
  }
}

