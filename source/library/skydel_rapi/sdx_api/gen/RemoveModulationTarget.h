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
    /// Remove a modulation target.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------
    /// Id   string Target identifier
    ///

    class RemoveModulationTarget;
    typedef std::shared_ptr<RemoveModulationTarget> RemoveModulationTargetPtr;
    
    
    class RemoveModulationTarget : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveModulationTarget";
      inline static const char* const Documentation = "Remove a modulation target.\n"      "\n"      "Name Type   Description\n"      "---- ------ -----------------\n"      "Id   string Target identifier";
      inline static const char* const TargetId = "";



          RemoveModulationTarget()
            : CommandBase(CmdName, TargetId)
          {}

          RemoveModulationTarget(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static RemoveModulationTargetPtr create(const std::string& id)
          {
            return std::make_shared<RemoveModulationTarget>(id);
          }

      static RemoveModulationTargetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveModulationTarget>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(RemoveModulationTarget);
  }
}

