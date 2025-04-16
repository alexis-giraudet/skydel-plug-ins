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
    /// Set whether a dynamic transmitter should only use user-provided propagation loss values. Propagation loss will not update automatically if set. This state is not preserved after simulation end.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Manual bool   If true, propagation loss will be 1000 dB until set manually.
    /// Id     string Interference transmitter unique identifier.
    ///

    class SetIntTxUseManualPropagationLoss;
    typedef std::shared_ptr<SetIntTxUseManualPropagationLoss> SetIntTxUseManualPropagationLossPtr;
    
    
    class SetIntTxUseManualPropagationLoss : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxUseManualPropagationLoss";
      inline static const char* const Documentation = "Set whether a dynamic transmitter should only use user-provided propagation loss values. Propagation loss will not update automatically if set. This state is not preserved after simulation end.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------\n"      "Manual bool   If true, propagation loss will be 1000 dB until set manually.\n"      "Id     string Interference transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxUseManualPropagationLoss()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxUseManualPropagationLoss(bool manual, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setManual(manual);
            setId(id);
          }


          static SetIntTxUseManualPropagationLossPtr create(bool manual, const std::string& id)
          {
            return std::make_shared<SetIntTxUseManualPropagationLoss>(manual, id);
          }

      static SetIntTxUseManualPropagationLossPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxUseManualPropagationLoss>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Manual"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Manual", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          bool manual() const
          {
            return parse_json<bool>::parse(m_values["Manual"]);
          }

          void setManual(bool manual)
          {
            m_values.AddMember("Manual", parse_json<bool>::format(manual, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxUseManualPropagationLoss);
  }
}

