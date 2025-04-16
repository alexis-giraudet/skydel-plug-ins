#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Logging of NMEA for the simulated position enable/disable.
    /// If a receiver is connected, that NMEA is saved as well.
    ///
    /// Name              Type          Description
    /// ----------------- ------------- -----------------------------------------------------------------------------
    /// Enabled           bool          If true, file(s) will be created during simulation
    /// SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.
    ///

    class EnableLogNmea;
    typedef std::shared_ptr<EnableLogNmea> EnableLogNmeaPtr;
    
    
    class EnableLogNmea : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableLogNmea";
      inline static const char* const Documentation = "Set Logging of NMEA for the simulated position enable/disable.\n"      "If a receiver is connected, that NMEA is saved as well.\n"      "\n"      "Name              Type          Description\n"      "----------------- ------------- -----------------------------------------------------------------------------\n"      "Enabled           bool          If true, file(s) will be created during simulation\n"      "SerialPortEnabled optional bool If true, the log is streamed to the serial port specified in the Preferences.";
      inline static const char* const TargetId = "";



          EnableLogNmea()
            : CommandBase(CmdName, TargetId)
          {}

          EnableLogNmea(bool enabled, const std::optional<bool>& serialPortEnabled = {})
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
            setSerialPortEnabled(serialPortEnabled);
          }


          static EnableLogNmeaPtr create(bool enabled, const std::optional<bool>& serialPortEnabled = {})
          {
            return std::make_shared<EnableLogNmea>(enabled, serialPortEnabled);
          }

      static EnableLogNmeaPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableLogNmea>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(EnableLogNmea);
  }
}

