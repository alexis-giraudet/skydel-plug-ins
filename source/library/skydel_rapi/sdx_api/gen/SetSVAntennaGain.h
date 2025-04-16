#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.
    ///
    /// Name   Type               Description
    /// ------ ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain   array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type   AntennaPatternType Pattern type
    /// Band   GNSSBand           Frequency band
    /// System string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Name   optional string    SV antenna name
    ///

    class SetSVAntennaGain;
    typedef std::shared_ptr<SetSVAntennaGain> SetSVAntennaGainPtr;
    
    
    class SetSVAntennaGain : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSVAntennaGain";
      inline static const char* const Documentation = "Set space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.\n"      "\n"      "Name   Type               Description\n"      "------ ------------------ -------------------------------------------------------------------------------------------------------------------------\n"      "Gain   array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"      "Type   AntennaPatternType Pattern type\n"      "Band   GNSSBand           Frequency band\n"      "System string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Name   optional string    SV antenna name";
      inline static const char* const TargetId = "";



          SetSVAntennaGain()
            : CommandBase(CmdName, TargetId)
          {}

          SetSVAntennaGain(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& name = {})
            : CommandBase(CmdName, TargetId)
          {

            setGain(gain);
            setType(type);
            setBand(band);
            setSystem(system);
            setName(name);
          }


          static SetSVAntennaGainPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& name = {})
          {
            return std::make_shared<SetSVAntennaGain>(gain, type, band, system, name);
          }

      static SetSVAntennaGainPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSVAntennaGain>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
                  && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
                  && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Gain", "Type", "Band", "System", "Name"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::vector<std::vector<double>> gain() const
          {
            return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
          }

          void setGain(const std::vector<std::vector<double>>& gain)
          {
            m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
          }



          Sdx::AntennaPatternType type() const
          {
            return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
          }

          void setType(const Sdx::AntennaPatternType& type)
          {
            m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
          }



          Sdx::GNSSBand band() const
          {
            return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
          }

          void setBand(const Sdx::GNSSBand& band)
          {
            m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::string> name() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
          }

          void setName(const std::optional<std::string>& name)
          {
            m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetSVAntennaGain);
  }
}

