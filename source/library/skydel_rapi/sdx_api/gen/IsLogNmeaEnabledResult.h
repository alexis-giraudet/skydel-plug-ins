#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogNmeaEnabled.
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -----------------------------------------------------------------------------
    /// Enabled           bool          If true, file(s) will be created during simulation
    /// SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.
    ///

    class IsLogNmeaEnabledResult;
    typedef std::shared_ptr<IsLogNmeaEnabledResult> IsLogNmeaEnabledResultPtr;
    
    
    class IsLogNmeaEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsLogNmeaEnabledResult";
      inline static const char* const Documentation = "Result of IsLogNmeaEnabled.\n"      "\n"      "Name              Type          Description\n"      "----------------- ------------- -----------------------------------------------------------------------------\n"      "Enabled           bool          If true, file(s) will be created during simulation\n"      "SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.";
      inline static const char* const TargetId = "";



          IsLogNmeaEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsLogNmeaEnabledResult(bool enabled, const std::optional<bool>& serialPortEnabled = {})
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
            setSerialPortEnabled(serialPortEnabled);
          }

          IsLogNmeaEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::optional<bool>& serialPortEnabled = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
            setSerialPortEnabled(serialPortEnabled);
          }



          static IsLogNmeaEnabledResultPtr create(bool enabled, const std::optional<bool>& serialPortEnabled = {})
          {
            return std::make_shared<IsLogNmeaEnabledResult>(enabled, serialPortEnabled);
          }

          static IsLogNmeaEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled, const std::optional<bool>& serialPortEnabled = {})
          {
            return std::make_shared<IsLogNmeaEnabledResult>(relatedCommand, enabled, serialPortEnabled);
          }

      static IsLogNmeaEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsLogNmeaEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<std::optional<bool>>::is_valid(m_values["SerialPortEnabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "SerialPortEnabled"}; 
        return names; 
      }
      


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<bool> serialPortEnabled() const
          {
            return parse_json<std::optional<bool>>::parse(m_values["SerialPortEnabled"]);
          }

          void setSerialPortEnabled(const std::optional<bool>& serialPortEnabled)
          {
            m_values.AddMember("SerialPortEnabled", parse_json<std::optional<bool>>::format(serialPortEnabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsLogNmeaEnabledResult);
  }
}

