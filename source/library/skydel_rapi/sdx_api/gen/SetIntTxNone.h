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
    /// Set an undefined trajectory to a transmitter, thus preventing it to be modulated (default value).
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class SetIntTxNone;
    typedef std::shared_ptr<SetIntTxNone> SetIntTxNonePtr;
    
    
    class SetIntTxNone : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxNone";
      inline static const char* const Documentation = "Set an undefined trajectory to a transmitter, thus preventing it to be modulated (default value).\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxNone()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxNone(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static SetIntTxNonePtr create(const std::string& id)
          {
            return std::make_shared<SetIntTxNone>(id);
          }

      static SetIntTxNonePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxNone>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxNone);
  }
}

