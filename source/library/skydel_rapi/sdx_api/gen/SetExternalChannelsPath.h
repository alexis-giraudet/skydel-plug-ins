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
    /// Set external channels path.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------
    /// Path string Path to the sdxpand directory
    ///

    class SetExternalChannelsPath;
    typedef std::shared_ptr<SetExternalChannelsPath> SetExternalChannelsPathPtr;
    
    
    class SetExternalChannelsPath : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetExternalChannelsPath";
      inline static const char* const Documentation = "Set external channels path.\n"      "\n"      "Name Type   Description\n"      "---- ------ -----------------------------\n"      "Path string Path to the sdxpand directory";
      inline static const char* const TargetId = "";



          SetExternalChannelsPath()
            : CommandBase(CmdName, TargetId)
          {}

          SetExternalChannelsPath(const std::string& path)
            : CommandBase(CmdName, TargetId)
          {

            setPath(path);
          }


          static SetExternalChannelsPathPtr create(const std::string& path)
          {
            return std::make_shared<SetExternalChannelsPath>(path);
          }

      static SetExternalChannelsPathPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetExternalChannelsPath>(ptr);
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
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetExternalChannelsPath);
  }
}

