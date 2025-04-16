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
    /// Rename a transmitter.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------
    /// UsualName string Usual name for the transmitter.
    /// Id        string Transmitter unique identifier.
    ///

    class RenameIntTx;
    typedef std::shared_ptr<RenameIntTx> RenameIntTxPtr;
    
    
    class RenameIntTx : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RenameIntTx";
      inline static const char* const Documentation = "Rename a transmitter.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ -------------------------------\n"      "UsualName string Usual name for the transmitter.\n"      "Id        string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          RenameIntTx()
            : CommandBase(CmdName, TargetId)
          {}

          RenameIntTx(const std::string& usualName, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setUsualName(usualName);
            setId(id);
          }


          static RenameIntTxPtr create(const std::string& usualName, const std::string& id)
          {
            return std::make_shared<RenameIntTx>(usualName, id);
          }

      static RenameIntTxPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RenameIntTx>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["UsualName"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"UsualName", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::string usualName() const
          {
            return parse_json<std::string>::parse(m_values["UsualName"]);
          }

          void setUsualName(const std::string& usualName)
          {
            m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(RenameIntTx);
  }
}

