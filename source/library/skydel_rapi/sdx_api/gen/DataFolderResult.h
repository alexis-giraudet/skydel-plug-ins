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
    /// Result of GetDataFolder.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------
    /// Folder string Skydel Data Folder
    ///

    class DataFolderResult;
    typedef std::shared_ptr<DataFolderResult> DataFolderResultPtr;
    
    
    class DataFolderResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "DataFolderResult";
      inline static const char* const Documentation = "Result of GetDataFolder.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ------------------\n"      "Folder string Skydel Data Folder";
      inline static const char* const TargetId = "";



          DataFolderResult()
            : CommandResult(CmdName, TargetId)
          {}

          DataFolderResult(const std::string& folder)
            : CommandResult(CmdName, TargetId)
          {

            setFolder(folder);
          }

          DataFolderResult(CommandBasePtr relatedCommand, const std::string& folder)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setFolder(folder);
          }



          static DataFolderResultPtr create(const std::string& folder)
          {
            return std::make_shared<DataFolderResult>(folder);
          }

          static DataFolderResultPtr create(CommandBasePtr relatedCommand, const std::string& folder)
          {
            return std::make_shared<DataFolderResult>(relatedCommand, folder);
          }

      static DataFolderResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<DataFolderResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Folder"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Folder"}; 
        return names; 
      }
      


          std::string folder() const
          {
            return parse_json<std::string>::parse(m_values["Folder"]);
          }

          void setFolder(const std::string& folder)
          {
            m_values.AddMember("Folder", parse_json<std::string>::format(folder, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(DataFolderResult);
  }
}

