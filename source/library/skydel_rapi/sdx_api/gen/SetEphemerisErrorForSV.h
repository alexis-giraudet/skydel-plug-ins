#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/RIC.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the satellite ephemeris error.
    ///
    /// Name     Type   Description
    /// -------- ------ -----------------------------------------------------------------------------------
    /// System   string "GPS", "Galileo", "GLONASS", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId     int    Satellite SV ID.
    /// Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.
    /// DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.
    /// DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.
    ///

    class SetEphemerisErrorForSV;
    typedef std::shared_ptr<SetEphemerisErrorForSV> SetEphemerisErrorForSVPtr;
    
    
    class SetEphemerisErrorForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetEphemerisErrorForSV";
      inline static const char* const Documentation = "Set the satellite ephemeris error.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ -----------------------------------------------------------------------------------\n"      "System   string \"GPS\", \"Galileo\", \"GLONASS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId     int    Satellite SV ID.\n"      "Orbit    RIC    The orbit error, in relative orbit frame. In-track error not available for GLONASS.\n"      "DeltaAf0 double The clock bias error, in second. DeltaTaun for GLONASS.\n"      "DeltaAf1 double The clock drift error, in second/second. Not available for GLONASS.";
      inline static const char* const TargetId = "";



          SetEphemerisErrorForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetEphemerisErrorForSV(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setOrbit(orbit);
            setDeltaAf0(deltaAf0);
            setDeltaAf1(deltaAf1);
          }


          static SetEphemerisErrorForSVPtr create(const std::string& system, int svId, const Sdx::RIC& orbit, double deltaAf0, double deltaAf1)
          {
            return std::make_shared<SetEphemerisErrorForSV>(system, svId, orbit, deltaAf0, deltaAf1);
          }

      static SetEphemerisErrorForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetEphemerisErrorForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<Sdx::RIC>::is_valid(m_values["Orbit"])
                  && parse_json<double>::is_valid(m_values["DeltaAf0"])
                  && parse_json<double>::is_valid(m_values["DeltaAf1"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Orbit", "DeltaAf0", "DeltaAf1"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          Sdx::RIC orbit() const
          {
            return parse_json<Sdx::RIC>::parse(m_values["Orbit"]);
          }

          void setOrbit(const Sdx::RIC& orbit)
          {
            m_values.AddMember("Orbit", parse_json<Sdx::RIC>::format(orbit, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double deltaAf0() const
          {
            return parse_json<double>::parse(m_values["DeltaAf0"]);
          }

          void setDeltaAf0(double deltaAf0)
          {
            m_values.AddMember("DeltaAf0", parse_json<double>::format(deltaAf0, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double deltaAf1() const
          {
            return parse_json<double>::parse(m_values["DeltaAf1"]);
          }

          void setDeltaAf1(double deltaAf1)
          {
            m_values.AddMember("DeltaAf1", parse_json<double>::format(deltaAf1, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetEphemerisErrorForSV);
  }
}

