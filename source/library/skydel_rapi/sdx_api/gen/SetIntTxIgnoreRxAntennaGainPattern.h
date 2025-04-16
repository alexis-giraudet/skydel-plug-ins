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
    /// Set whether a dynamic transmitter should ignore the receiver's antenna gain pattern.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetIntTxIgnoreRxAntennaGainPattern;
    typedef std::shared_ptr<SetIntTxIgnoreRxAntennaGainPattern> SetIntTxIgnoreRxAntennaGainPatternPtr;
    
    
    class SetIntTxIgnoreRxAntennaGainPattern : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxIgnoreRxAntennaGainPattern";
      inline static const char* const Documentation = "Set whether a dynamic transmitter should ignore the receiver's antenna gain pattern.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------\n"      "Ignore bool   If true, the receiver's antenna gain pattern will be ignored.\n"      "Id     string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxIgnoreRxAntennaGainPattern()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxIgnoreRxAntennaGainPattern(bool ignore, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setIgnore(ignore);
            setId(id);
          }


          static SetIntTxIgnoreRxAntennaGainPatternPtr create(bool ignore, const std::string& id)
          {
            return std::make_shared<SetIntTxIgnoreRxAntennaGainPattern>(ignore, id);
          }

      static SetIntTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxIgnoreRxAntennaGainPattern>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Ignore"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Ignore", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          bool ignore() const
          {
            return parse_json<bool>::parse(m_values["Ignore"]);
          }

          void setIgnore(bool ignore)
          {
            m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxIgnoreRxAntennaGainPattern);
  }
}

