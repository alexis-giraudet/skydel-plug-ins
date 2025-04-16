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
    /// Save configuration with new name.
    ///
    /// Name      Type   Description
    /// --------- ------ ---------------------------------------------------------------------------------------------------------
    /// Path      string Configuration path. Automatically add file suffix if missing. If folder not defined, user default folder.
    /// Overwrite bool   Overwrite existing configuration if is exists
    ///

    class SaveAs;
    typedef std::shared_ptr<SaveAs> SaveAsPtr;
    
    
    class SaveAs : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SaveAs";
      inline static const char* const Documentation = "Save configuration with new name.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ ---------------------------------------------------------------------------------------------------------\n"      "Path      string Configuration path. Automatically add file suffix if missing. If folder not defined, user default folder.\n"      "Overwrite bool   Overwrite existing configuration if is exists";
      inline static const char* const TargetId = "";



          SaveAs()
            : CommandBase(CmdName, TargetId)
          {}

          SaveAs(const std::string& path, bool overwrite)
            : CommandBase(CmdName, TargetId)
          {

            setPath(path);
            setOverwrite(overwrite);
          }


          static SaveAsPtr create(const std::string& path, bool overwrite)
          {
            return std::make_shared<SaveAs>(path, overwrite);
          }

      static SaveAsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SaveAs>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Path"])
                  && parse_json<bool>::is_valid(m_values["Overwrite"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Path", "Overwrite"}; 
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



          bool overwrite() const
          {
            return parse_json<bool>::parse(m_values["Overwrite"]);
          }

          void setOverwrite(bool overwrite)
          {
            m_values.AddMember("Overwrite", parse_json<bool>::format(overwrite, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SaveAs);
  }
}

