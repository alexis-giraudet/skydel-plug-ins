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
    /// Get spoofer transmitter static position and orientation
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTxFix;
    typedef std::shared_ptr<GetSpoofTxFix> GetSpoofTxFixPtr;
    
    
    class GetSpoofTxFix : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSpoofTxFix";
      inline static const char* const Documentation = "Get spoofer transmitter static position and orientation\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetSpoofTxFix()
            : CommandBase(CmdName, TargetId)
          {}

          GetSpoofTxFix(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static GetSpoofTxFixPtr create(const std::string& id)
          {
            return std::make_shared<GetSpoofTxFix>(id);
          }

      static GetSpoofTxFixPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSpoofTxFix>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetSpoofTxFix);
  }
}

