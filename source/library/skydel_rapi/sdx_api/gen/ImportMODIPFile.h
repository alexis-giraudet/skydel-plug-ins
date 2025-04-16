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
    /// Import MODIP data file.
    ///
    /// Name Type   Description
    /// ---- ------ -----------
    /// Path string File path.
    ///

    class ImportMODIPFile;
    typedef std::shared_ptr<ImportMODIPFile> ImportMODIPFilePtr;
    
    
    class ImportMODIPFile : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ImportMODIPFile";
      inline static const char* const Documentation = "Import MODIP data file.\n"      "\n"      "Name Type   Description\n"      "---- ------ -----------\n"      "Path string File path.";
      inline static const char* const TargetId = "";



          ImportMODIPFile()
            : CommandBase(CmdName, TargetId)
          {}

          ImportMODIPFile(const std::string& path)
            : CommandBase(CmdName, TargetId)
          {

            setPath(path);
          }


          static ImportMODIPFilePtr create(const std::string& path)
          {
            return std::make_shared<ImportMODIPFile>(path);
          }

      static ImportMODIPFilePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ImportMODIPFile>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(ImportMODIPFile);
  }
}

