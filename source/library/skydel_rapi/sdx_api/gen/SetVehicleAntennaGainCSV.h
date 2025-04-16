#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic vehicle Antenna.
    ///
    /// Name     Type               Description
    /// -------- ------------------ ----------------------------------------------------------------------------------------------------------------------
    /// FilePath string             File path of the CSV (see user manual for CSV file format details). For Default and None types, leave this field empty
    /// Type     AntennaPatternType Pattern type
    /// Band     GNSSBand           Frequency band
    /// Name     optional string    Vehicle antenna name
    ///

    class SetVehicleAntennaGainCSV;
    typedef std::shared_ptr<SetVehicleAntennaGainCSV> SetVehicleAntennaGainCSVPtr;
    
    
    class SetVehicleAntennaGainCSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetVehicleAntennaGainCSV";
      inline static const char* const Documentation = "Set vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic vehicle Antenna.\n"      "\n"      "Name     Type               Description\n"      "-------- ------------------ ----------------------------------------------------------------------------------------------------------------------\n"      "FilePath string             File path of the CSV (see user manual for CSV file format details). For Default and None types, leave this field empty\n"      "Type     AntennaPatternType Pattern type\n"      "Band     GNSSBand           Frequency band\n"      "Name     optional string    Vehicle antenna name";
      inline static const char* const TargetId = "";



          SetVehicleAntennaGainCSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetVehicleAntennaGainCSV(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
            : CommandBase(CmdName, TargetId)
          {

            setFilePath(filePath);
            setType(type);
            setBand(band);
            setName(name);
          }


          static SetVehicleAntennaGainCSVPtr create(const std::string& filePath, const Sdx::AntennaPatternType& type, const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
          {
            return std::make_shared<SetVehicleAntennaGainCSV>(filePath, type, band, name);
          }

      static SetVehicleAntennaGainCSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetVehicleAntennaGainCSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["FilePath"])
                  && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
                  && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"FilePath", "Type", "Band", "Name"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string filePath() const
          {
            return parse_json<std::string>::parse(m_values["FilePath"]);
          }

          void setFilePath(const std::string& filePath)
          {
            m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetVehicleAntennaGainCSV);
  }
}

