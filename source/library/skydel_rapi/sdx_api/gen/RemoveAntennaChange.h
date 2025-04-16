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
    /// Removes an antenna change.
    ///
    /// Name Type   Description
    /// ---- ------ -------------------------------------
    /// Id   string Unique identifier (see AntennaChange)
    ///

    class RemoveAntennaChange;
    typedef std::shared_ptr<RemoveAntennaChange> RemoveAntennaChangePtr;
    
    
    class RemoveAntennaChange : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveAntennaChange";
      inline static const char* const Documentation = "Removes an antenna change.\n"      "\n"      "Name Type   Description\n"      "---- ------ -------------------------------------\n"      "Id   string Unique identifier (see AntennaChange)";
      inline static const char* const TargetId = "";



          RemoveAntennaChange()
            : CommandBase(CmdName, TargetId)
          {}

          RemoveAntennaChange(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static RemoveAntennaChangePtr create(const std::string& id)
          {
            return std::make_shared<RemoveAntennaChange>(id);
          }

      static RemoveAntennaChangePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveAntennaChange>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(RemoveAntennaChange);
  }
}

