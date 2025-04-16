#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/ElevationAzimuth.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetElevationAzimuthForEachSV.
    ///
    /// Name              Type                            Description
    /// ----------------- ------------------------------- ---------------------------------------------------------------------------
    /// System            string                          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// ElevationAzimuths array optional ElevationAzimuth Elevation and Azimuth position angles of the satellites.
    ///

    class GetElevationAzimuthForEachSVResult;
    typedef std::shared_ptr<GetElevationAzimuthForEachSVResult> GetElevationAzimuthForEachSVResultPtr;
    
    
    class GetElevationAzimuthForEachSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetElevationAzimuthForEachSVResult";
      inline static const char* const Documentation = "Result of GetElevationAzimuthForEachSV.\n"      "\n"      "Name              Type                            Description\n"      "----------------- ------------------------------- ---------------------------------------------------------------------------\n"      "System            string                          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "ElevationAzimuths array optional ElevationAzimuth Elevation and Azimuth position angles of the satellites.";
      inline static const char* const TargetId = "";



          GetElevationAzimuthForEachSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetElevationAzimuthForEachSVResult(const std::string& system, const std::vector<std::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setElevationAzimuths(elevationAzimuths);
          }

          GetElevationAzimuthForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setElevationAzimuths(elevationAzimuths);
          }



          static GetElevationAzimuthForEachSVResultPtr create(const std::string& system, const std::vector<std::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
          {
            return std::make_shared<GetElevationAzimuthForEachSVResult>(system, elevationAzimuths);
          }

          static GetElevationAzimuthForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
          {
            return std::make_shared<GetElevationAzimuthForEachSVResult>(relatedCommand, system, elevationAzimuths);
          }

      static GetElevationAzimuthForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetElevationAzimuthForEachSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::vector<std::optional<Sdx::ElevationAzimuth>>>::is_valid(m_values["ElevationAzimuths"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "ElevationAzimuths"}; 
        return names; 
      }
      


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<std::optional<Sdx::ElevationAzimuth>> elevationAzimuths() const
          {
            return parse_json<std::vector<std::optional<Sdx::ElevationAzimuth>>>::parse(m_values["ElevationAzimuths"]);
          }

          void setElevationAzimuths(const std::vector<std::optional<Sdx::ElevationAzimuth>>& elevationAzimuths)
          {
            m_values.AddMember("ElevationAzimuths", parse_json<std::vector<std::optional<Sdx::ElevationAzimuth>>>::format(elevationAzimuths, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetElevationAzimuthForEachSVResult);
  }
}

