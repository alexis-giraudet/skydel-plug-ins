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
    /// Change the modulation target name. The name is only used for display purpose.
    ///
    /// Name       Type   Description
    /// ---------- ------ -----------------
    /// TargetName string New target name
    /// Id         string Target identifier
    ///

    class ChangeModulationTargetName;
    typedef std::shared_ptr<ChangeModulationTargetName> ChangeModulationTargetNamePtr;
    
    
    class ChangeModulationTargetName : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ChangeModulationTargetName";
      inline static const char* const Documentation = "Change the modulation target name. The name is only used for display purpose.\n"      "\n"      "Name       Type   Description\n"      "---------- ------ -----------------\n"      "TargetName string New target name\n"      "Id         string Target identifier";
      inline static const char* const TargetId = "";



          ChangeModulationTargetName()
            : CommandBase(CmdName, TargetId)
          {}

          ChangeModulationTargetName(const std::string& targetName, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setTargetName(targetName);
            setId(id);
          }


          static ChangeModulationTargetNamePtr create(const std::string& targetName, const std::string& id)
          {
            return std::make_shared<ChangeModulationTargetName>(targetName, id);
          }

      static ChangeModulationTargetNamePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ChangeModulationTargetName>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["TargetName"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"TargetName", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string targetName() const
          {
            return parse_json<std::string>::parse(m_values["TargetName"]);
          }

          void setTargetName(const std::string& targetName)
          {
            m_values.AddMember("TargetName", parse_json<std::string>::format(targetName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ChangeModulationTargetName);
  }
}

