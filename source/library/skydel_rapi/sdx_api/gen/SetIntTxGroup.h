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
    /// Set the interference transmitter group (which links to a specific RF output target).
    ///
    /// Name  Type   Description
    /// ----- ------ ---------------------------------
    /// Group int    Interference group number [1..16]
    /// Id    string Transmitter unique identifier.
    ///

    class SetIntTxGroup;
    typedef std::shared_ptr<SetIntTxGroup> SetIntTxGroupPtr;
    
    
    class SetIntTxGroup : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxGroup";
      inline static const char* const Documentation = "Set the interference transmitter group (which links to a specific RF output target).\n"      "\n"      "Name  Type   Description\n"      "----- ------ ---------------------------------\n"      "Group int    Interference group number [1..16]\n"      "Id    string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxGroup()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxGroup(int group, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setGroup(group);
            setId(id);
          }


          static SetIntTxGroupPtr create(int group, const std::string& id)
          {
            return std::make_shared<SetIntTxGroup>(group, id);
          }

      static SetIntTxGroupPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxGroup>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Group"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Group", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          int group() const
          {
            return parse_json<int>::parse(m_values["Group"]);
          }

          void setGroup(int group)
          {
            m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxGroup);
  }
}

