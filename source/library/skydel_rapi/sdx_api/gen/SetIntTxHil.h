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
    /// Set interference transmitter HIL trajectory
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class SetIntTxHil;
    typedef std::shared_ptr<SetIntTxHil> SetIntTxHilPtr;
    
    
    class SetIntTxHil : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxHil";
      inline static const char* const Documentation = "Set interference transmitter HIL trajectory\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxHil()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxHil(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static SetIntTxHilPtr create(const std::string& id)
          {
            return std::make_shared<SetIntTxHil>(id);
          }

      static SetIntTxHilPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxHil>(ptr);
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
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxHil);
  }
}

