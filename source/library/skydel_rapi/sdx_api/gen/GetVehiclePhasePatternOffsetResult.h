#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVehiclePhasePatternOffset.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band.
    /// Offset      double          Phase offset (in rad)
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetVehiclePhasePatternOffsetResult;
    typedef std::shared_ptr<GetVehiclePhasePatternOffsetResult> GetVehiclePhasePatternOffsetResultPtr;
    
    
    class GetVehiclePhasePatternOffsetResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetVehiclePhasePatternOffsetResult";
      inline static const char* const Documentation = "Result of GetVehiclePhasePatternOffset.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- ------------------------------------------------------------------------------------\n"      "Band        GNSSBand        Offset will be apply to this band.\n"      "Offset      double          Phase offset (in rad)\n"      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
      inline static const char* const TargetId = "";



          GetVehiclePhasePatternOffsetResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetVehiclePhasePatternOffsetResult(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {})
            : CommandResult(CmdName, TargetId)
          {

            setBand(band);
            setOffset(offset);
            setAntennaName(antennaName);
          }

          GetVehiclePhasePatternOffsetResult(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setBand(band);
            setOffset(offset);
            setAntennaName(antennaName);
          }



          static GetVehiclePhasePatternOffsetResultPtr create(const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {})
          {
            return std::make_shared<GetVehiclePhasePatternOffsetResult>(band, offset, antennaName);
          }

          static GetVehiclePhasePatternOffsetResultPtr create(CommandBasePtr relatedCommand, const Sdx::GNSSBand& band, double offset, const std::optional<std::string>& antennaName = {})
          {
            return std::make_shared<GetVehiclePhasePatternOffsetResult>(relatedCommand, band, offset, antennaName);
          }

      static GetVehiclePhasePatternOffsetResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehiclePhasePatternOffsetResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
                  && parse_json<double>::is_valid(m_values["Offset"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Band", "Offset", "AntennaName"}; 
        return names; 
      }
      


          Sdx::GNSSBand band() const
          {
            return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
          }

          void setBand(const Sdx::GNSSBand& band)
          {
            m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double offset() const
          {
            return parse_json<double>::parse(m_values["Offset"]);
          }

          void setOffset(double offset)
          {
            m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::string> antennaName() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
          }

          void setAntennaName(const std::optional<std::string>& antennaName)
          {
            m_values.AddMember("AntennaName", parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetVehiclePhasePatternOffsetResult);
  }
}

