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
    /// Import all the CCIR data files from the specified directory.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------
    /// Path string Directory path.
    ///

    class ImportCCIRFilesFromDirectory;
    typedef std::shared_ptr<ImportCCIRFilesFromDirectory> ImportCCIRFilesFromDirectoryPtr;
    
    
    class ImportCCIRFilesFromDirectory : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ImportCCIRFilesFromDirectory";
      inline static const char* const Documentation = "Import all the CCIR data files from the specified directory.\n"      "\n"      "Name Type   Description\n"      "---- ------ ---------------\n"      "Path string Directory path.";
      inline static const char* const TargetId = "";



          ImportCCIRFilesFromDirectory()
            : CommandBase(CmdName, TargetId)
          {}

          ImportCCIRFilesFromDirectory(const std::string& path)
            : CommandBase(CmdName, TargetId)
          {

            setPath(path);
          }


          static ImportCCIRFilesFromDirectoryPtr create(const std::string& path)
          {
            return std::make_shared<ImportCCIRFilesFromDirectory>(path);
          }

      static ImportCCIRFilesFromDirectoryPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ImportCCIRFilesFromDirectory>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Path"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Path"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string path() const
          {
            return parse_json<std::string>::parse(m_values["Path"]);
          }

          void setPath(const std::string& path)
          {
            m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ImportCCIRFilesFromDirectory);
  }
}

