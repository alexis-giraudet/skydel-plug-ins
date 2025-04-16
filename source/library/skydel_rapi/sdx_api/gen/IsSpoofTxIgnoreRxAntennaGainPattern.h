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
    /// Get whether a spoofer ignore the receiver's antenna gain pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaGainPattern;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaGainPattern> IsSpoofTxIgnoreRxAntennaGainPatternPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaGainPattern : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSpoofTxIgnoreRxAntennaGainPattern";
      inline static const char* const Documentation = "Get whether a spoofer ignore the receiver's antenna gain pattern.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          IsSpoofTxIgnoreRxAntennaGainPattern()
            : CommandBase(CmdName, TargetId)
          {}

          IsSpoofTxIgnoreRxAntennaGainPattern(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static IsSpoofTxIgnoreRxAntennaGainPatternPtr create(const std::string& id)
          {
            return std::make_shared<IsSpoofTxIgnoreRxAntennaGainPattern>(id);
          }

      static IsSpoofTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaGainPattern>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsSpoofTxIgnoreRxAntennaGainPattern);
  }
}

