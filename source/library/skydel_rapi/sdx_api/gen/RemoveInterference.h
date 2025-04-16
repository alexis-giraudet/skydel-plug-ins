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
    /// Removes a specific interference signal.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------------------------
    /// Id   string Unique identifier of the interference signal to remove.
    ///

    class RemoveInterference;
    typedef std::shared_ptr<RemoveInterference> RemoveInterferencePtr;
    
    
    class RemoveInterference : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveInterference";
      inline static const char* const Documentation = "Removes a specific interference signal.\n"      "\n"      "Name Type   Description\n"      "---- ------ -------------------------------------------------------\n"      "Id   string Unique identifier of the interference signal to remove.";
      inline static const char* const TargetId = "";



          RemoveInterference()
            : CommandBase(CmdName, TargetId)
          {}

          RemoveInterference(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static RemoveInterferencePtr create(const std::string& id)
          {
            return std::make_shared<RemoveInterference>(id);
          }

      static RemoveInterferencePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveInterference>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(RemoveInterference);
  }
}

