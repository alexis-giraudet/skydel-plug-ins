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
    /// Set the manual propagation loss for the given interference signal. Value is used only if SetIntTxUseManualPropagationLoss has been set on the corresponding transmitter. This value is not preserved after simulation end.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------------------------------------------------------------------------------------------
    /// PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.
    /// TransmitterId   string Transmitter unique identifier.
    /// SignalId        string Signal unique identifier.
    ///

    class SetIntTxSignalManualPropagationLoss;
    typedef std::shared_ptr<SetIntTxSignalManualPropagationLoss> SetIntTxSignalManualPropagationLossPtr;
    
    
    class SetIntTxSignalManualPropagationLoss : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxSignalManualPropagationLoss";
      inline static const char* const Documentation = "Set the manual propagation loss for the given interference signal. Value is used only if SetIntTxUseManualPropagationLoss has been set on the corresponding transmitter. This value is not preserved after simulation end.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ --------------------------------------------------------------------------------------------------------\n"      "PropagationLoss double The propagation loss in dB to use until the next call of this command, or until manual mode is disabled.\n"      "TransmitterId   string Transmitter unique identifier.\n"      "SignalId        string Signal unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxSignalManualPropagationLoss()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxSignalManualPropagationLoss(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
            : CommandBase(CmdName, TargetId)
          {

            setPropagationLoss(propagationLoss);
            setTransmitterId(transmitterId);
            setSignalId(signalId);
          }


          static SetIntTxSignalManualPropagationLossPtr create(double propagationLoss, const std::string& transmitterId, const std::string& signalId)
          {
            return std::make_shared<SetIntTxSignalManualPropagationLoss>(propagationLoss, transmitterId, signalId);
          }

      static SetIntTxSignalManualPropagationLossPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxSignalManualPropagationLoss>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["PropagationLoss"])
                  && parse_json<std::string>::is_valid(m_values["TransmitterId"])
                  && parse_json<std::string>::is_valid(m_values["SignalId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"PropagationLoss", "TransmitterId", "SignalId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          double propagationLoss() const
          {
            return parse_json<double>::parse(m_values["PropagationLoss"]);
          }

          void setPropagationLoss(double propagationLoss)
          {
            m_values.AddMember("PropagationLoss", parse_json<double>::format(propagationLoss, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string transmitterId() const
          {
            return parse_json<std::string>::parse(m_values["TransmitterId"]);
          }

          void setTransmitterId(const std::string& transmitterId)
          {
            m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string signalId() const
          {
            return parse_json<std::string>::parse(m_values["SignalId"]);
          }

          void setSignalId(const std::string& signalId)
          {
            m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetIntTxSignalManualPropagationLoss);
  }
}

