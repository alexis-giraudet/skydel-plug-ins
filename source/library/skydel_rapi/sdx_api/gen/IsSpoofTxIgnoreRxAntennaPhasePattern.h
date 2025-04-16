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
    /// Get whether a spoofer ignore the receiver's antenna phase pattern.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaPhasePattern;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaPhasePattern> IsSpoofTxIgnoreRxAntennaPhasePatternPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaPhasePattern : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSpoofTxIgnoreRxAntennaPhasePattern";
      inline static const char* const Documentation = "Get whether a spoofer ignore the receiver's antenna phase pattern.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          IsSpoofTxIgnoreRxAntennaPhasePattern()
            : CommandBase(CmdName, TargetId)
          {}

          IsSpoofTxIgnoreRxAntennaPhasePattern(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static IsSpoofTxIgnoreRxAntennaPhasePatternPtr create(const std::string& id)
          {
            return std::make_shared<IsSpoofTxIgnoreRxAntennaPhasePattern>(id);
          }

      static IsSpoofTxIgnoreRxAntennaPhasePatternPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaPhasePattern>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsSpoofTxIgnoreRxAntennaPhasePattern);
  }
}

