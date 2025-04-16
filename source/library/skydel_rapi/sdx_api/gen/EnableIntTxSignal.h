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
    /// Change whether a signal is enabled or disabled
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------------
    /// Enabled       bool   Whether the signal is enabled or not
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string CW unique identifier.
    ///

    class EnableIntTxSignal;
    typedef std::shared_ptr<EnableIntTxSignal> EnableIntTxSignalPtr;
    
    
    class EnableIntTxSignal : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableIntTxSignal";
      inline static const char* const Documentation = "Change whether a signal is enabled or disabled\n"      "\n"      "Name          Type   Description\n"      "------------- ------ ------------------------------------\n"      "Enabled       bool   Whether the signal is enabled or not\n"      "TransmitterId string Transmitter unique identifier.\n"      "SignalId      string CW unique identifier.";
      inline static const char* const TargetId = "";



          EnableIntTxSignal()
            : CommandBase(CmdName, TargetId)
          {}

          EnableIntTxSignal(bool enabled, const std::string& transmitterId, const std::string& signalId)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
            setTransmitterId(transmitterId);
            setSignalId(signalId);
          }


          static EnableIntTxSignalPtr create(bool enabled, const std::string& transmitterId, const std::string& signalId)
          {
            return std::make_shared<EnableIntTxSignal>(enabled, transmitterId, signalId);
          }

      static EnableIntTxSignalPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableIntTxSignal>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<std::string>::is_valid(m_values["TransmitterId"])
                  && parse_json<std::string>::is_valid(m_values["SignalId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "TransmitterId", "SignalId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(EnableIntTxSignal);
  }
}

