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
    /// Get the address of the spoofer instance that will
    /// generate the signal for this spoofer transmitter.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxRemoteAddress;
    typedef std::shared_ptr<GetSpoofTxRemoteAddress> GetSpoofTxRemoteAddressPtr;
    
    
    class GetSpoofTxRemoteAddress : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSpoofTxRemoteAddress";
      inline static const char* const Documentation = "Get the address of the spoofer instance that will\n"      "generate the signal for this spoofer transmitter.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetSpoofTxRemoteAddress()
            : CommandBase(CmdName, TargetId)
          {}

          GetSpoofTxRemoteAddress(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static GetSpoofTxRemoteAddressPtr create(const std::string& id)
          {
            return std::make_shared<GetSpoofTxRemoteAddress>(id);
          }

      static GetSpoofTxRemoteAddressPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSpoofTxRemoteAddress>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetSpoofTxRemoteAddress);
  }
}

