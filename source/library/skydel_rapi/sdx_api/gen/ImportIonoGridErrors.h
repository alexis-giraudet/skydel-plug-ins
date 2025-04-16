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
    /// Import ionospheric grid errors.
    ///
    /// Name        Type   Description
    /// ----------- ------ ------------------------------------
    /// Overwriting bool   Overwrite the previous grid if true.
    /// Path        string Grid file path
    ///

    class ImportIonoGridErrors;
    typedef std::shared_ptr<ImportIonoGridErrors> ImportIonoGridErrorsPtr;
    
    
    class ImportIonoGridErrors : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ImportIonoGridErrors";
      inline static const char* const Documentation = "Import ionospheric grid errors.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ ------------------------------------\n"      "Overwriting bool   Overwrite the previous grid if true.\n"      "Path        string Grid file path";
      inline static const char* const TargetId = "";



          ImportIonoGridErrors()
            : CommandBase(CmdName, TargetId)
          {}

          ImportIonoGridErrors(bool overwriting, const std::string& path)
            : CommandBase(CmdName, TargetId)
          {

            setOverwriting(overwriting);
            setPath(path);
          }


          static ImportIonoGridErrorsPtr create(bool overwriting, const std::string& path)
          {
            return std::make_shared<ImportIonoGridErrors>(overwriting, path);
          }

      static ImportIonoGridErrorsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ImportIonoGridErrors>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Overwriting"])
                  && parse_json<std::string>::is_valid(m_values["Path"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Overwriting", "Path"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          bool overwriting() const
          {
            return parse_json<bool>::parse(m_values["Overwriting"]);
          }

          void setOverwriting(bool overwriting)
          {
            m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(ImportIonoGridErrors);
  }
}

