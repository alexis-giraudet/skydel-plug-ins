#pragma once

#include <memory>
#include "command_result.h"
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
    /// Result of GetVehicleAntennaGain.
    ///
    /// Name Type               Description
    /// ---- ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type AntennaPatternType Pattern type
    /// Band GNSSBand           Frequency band
    /// Name optional string    Vehicle antenna name
    ///

    class GetVehicleAntennaGainResult;
    typedef std::shared_ptr<GetVehicleAntennaGainResult> GetVehicleAntennaGainResultPtr;
    
    
    class GetVehicleAntennaGainResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetVehicleAntennaGainResult";
      inline static const char* const Documentation = "Result of GetVehicleAntennaGain.\n"      "\n"      "Name Type               Description\n"      "---- ------------------ -------------------------------------------------------------------------------------------------------------------------\n"      "Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"      "Type AntennaPatternType Pattern type\n"      "Band GNSSBand           Frequency band\n"      "Name optional string    Vehicle antenna name";
      inline static const char* const TargetId = "";



          GetVehicleAntennaGainResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetVehicleAntennaGainResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
            : CommandResult(CmdName, TargetId)
          {

            setGain(gain);
            setType(type);
            setBand(band);
            setName(name);
          }

          GetVehicleAntennaGainResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setGain(gain);
            setType(type);
            setBand(band);
            setName(name);
          }



          static GetVehicleAntennaGainResultPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
          {
            return std::make_shared<GetVehicleAntennaGainResult>(gain, type, band, name);
          }

          static GetVehicleAntennaGainResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
          {
            return std::make_shared<GetVehicleAntennaGainResult>(relatedCommand, gain, type, band, name);
          }

      static GetVehicleAntennaGainResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleAntennaGainResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
                  && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
                  && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Gain", "Type", "Band", "Name"}; 
        return names; 
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



          std::optional<std::string> name() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
          }

          void setName(const std::optional<std::string>& name)
          {
            m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaGainResult);
  }
}

