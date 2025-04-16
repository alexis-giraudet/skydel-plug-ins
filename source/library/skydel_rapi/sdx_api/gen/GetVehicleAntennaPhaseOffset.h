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
    /// Get Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.
    ///
    /// Name Type            Description
    /// ---- --------------- --------------------
    /// Band GNSSBand        Frequency band
    /// Name optional string Vehicle antenna name
    ///

    class GetVehicleAntennaPhaseOffset;
    typedef std::shared_ptr<GetVehicleAntennaPhaseOffset> GetVehicleAntennaPhaseOffsetPtr;
    
    
    class GetVehicleAntennaPhaseOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetVehicleAntennaPhaseOffset";
      inline static const char* const Documentation = "Get Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.\n"      "\n"      "Name Type            Description\n"      "---- --------------- --------------------\n"      "Band GNSSBand        Frequency band\n"      "Name optional string Vehicle antenna name";
      inline static const char* const TargetId = "";



          GetVehicleAntennaPhaseOffset()
            : CommandBase(CmdName, TargetId)
          {}

          GetVehicleAntennaPhaseOffset(const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
            : CommandBase(CmdName, TargetId)
          {

            setBand(band);
            setName(name);
          }


          static GetVehicleAntennaPhaseOffsetPtr create(const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
          {
            return std::make_shared<GetVehicleAntennaPhaseOffset>(band, name);
          }

      static GetVehicleAntennaPhaseOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleAntennaPhaseOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["Name"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Band", "Name"}; 
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



          std::optional<std::string> name() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["Name"]);
          }

          void setName(const std::optional<std::string>& name)
          {
            m_values.AddMember("Name", parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaPhaseOffset);
  }
}

