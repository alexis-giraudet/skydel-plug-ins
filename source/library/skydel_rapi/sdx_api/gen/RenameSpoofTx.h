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
    /// Rename a spoofer.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------
    /// UsualName string Usual name for the transmitter.
    /// Id        string Transmitter unique identifier.
    ///

    class RenameSpoofTx;
    typedef std::shared_ptr<RenameSpoofTx> RenameSpoofTxPtr;
    
    
    class RenameSpoofTx : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RenameSpoofTx";
      inline static const char* const Documentation = "Rename a spoofer.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ -------------------------------\n"      "UsualName string Usual name for the transmitter.\n"      "Id        string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          RenameSpoofTx()
            : CommandBase(CmdName, TargetId)
          {}

          RenameSpoofTx(const std::string& usualName, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setUsualName(usualName);
            setId(id);
          }


          static RenameSpoofTxPtr create(const std::string& usualName, const std::string& id)
          {
            return std::make_shared<RenameSpoofTx>(usualName, id);
          }

      static RenameSpoofTxPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RenameSpoofTx>(ptr);
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
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(RenameSpoofTx);
  }
}

