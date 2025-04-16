#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/GNSSBand.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the offset (in dB) for the antenna gain pattern of the band.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ------------------------------------------------------------------------------------
    /// Band        GNSSBand        Offset will be apply to this band.
    /// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
    ///

    class GetVehicleGainPatternOffset;
    typedef std::shared_ptr<GetVehicleGainPatternOffset> GetVehicleGainPatternOffsetPtr;
    
    
    class GetVehicleGainPatternOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetVehicleGainPatternOffset";
      inline static const char* const Documentation = "Get the offset (in dB) for the antenna gain pattern of the band.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- ------------------------------------------------------------------------------------\n"      "Band        GNSSBand        Offset will be apply to this band.\n"      "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
      inline static const char* const TargetId = "";



          GetVehicleGainPatternOffset()
            : CommandBase(CmdName, TargetId)
          {}

          GetVehicleGainPatternOffset(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName = {})
            : CommandBase(CmdName, TargetId)
          {

            setBand(band);
            setAntennaName(antennaName);
          }


          static GetVehicleGainPatternOffsetPtr create(const Sdx::GNSSBand& band, const std::optional<std::string>& antennaName = {})
          {
            return std::make_shared<GetVehicleGainPatternOffset>(band, antennaName);
          }

      static GetVehicleGainPatternOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleGainPatternOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Band", "AntennaName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          Sdx::GNSSBand band() const
          {
            return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]);
          }

          void setBand(const Sdx::GNSSBand& band)
          {
            m_values.AddMember("Band", parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetVehicleGainPatternOffset);
  }
}

