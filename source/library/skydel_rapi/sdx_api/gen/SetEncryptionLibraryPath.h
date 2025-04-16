#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/EncryptionSignalType.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the specific encryption signal library path.
    ///
    /// Name Type                 Description
    /// ---- -------------------- -------------------------
    /// Type EncryptionSignalType Encryption signal type.
    /// Path string               Path to the library file.
    ///

    class SetEncryptionLibraryPath;
    typedef std::shared_ptr<SetEncryptionLibraryPath> SetEncryptionLibraryPathPtr;
    
    
    class SetEncryptionLibraryPath : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetEncryptionLibraryPath";
      inline static const char* const Documentation = "Set the specific encryption signal library path.\n"      "\n"      "Name Type                 Description\n"      "---- -------------------- -------------------------\n"      "Type EncryptionSignalType Encryption signal type.\n"      "Path string               Path to the library file.";
      inline static const char* const TargetId = "";



          SetEncryptionLibraryPath()
            : CommandBase(CmdName, TargetId)
          {}

          SetEncryptionLibraryPath(const Sdx::EncryptionSignalType& type, const std::string& path)
            : CommandBase(CmdName, TargetId)
          {

            setType(type);
            setPath(path);
          }


          static SetEncryptionLibraryPathPtr create(const Sdx::EncryptionSignalType& type, const std::string& path)
          {
            return std::make_shared<SetEncryptionLibraryPath>(type, path);
          }

      static SetEncryptionLibraryPathPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetEncryptionLibraryPath>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::EncryptionSignalType>::is_valid(m_values["Type"])
                  && parse_json<std::string>::is_valid(m_values["Path"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Type", "Path"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
          }


          Sdx::EncryptionSignalType type() const
          {
            return parse_json<Sdx::EncryptionSignalType>::parse(m_values["Type"]);
          }

          void setType(const Sdx::EncryptionSignalType& type)
          {
            m_values.AddMember("Type", parse_json<Sdx::EncryptionSignalType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetEncryptionLibraryPath);
  }
}

