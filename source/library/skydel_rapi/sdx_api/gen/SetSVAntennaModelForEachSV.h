#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the antenna model for all satellites.
    ///
    /// Name              Type         Description
    /// ----------------- ------------ -----------------------------------------------------------------------------------------------------
    /// System            string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetSVAntennaModelForEachSV;
    typedef std::shared_ptr<SetSVAntennaModelForEachSV> SetSVAntennaModelForEachSVPtr;
    
    
    class SetSVAntennaModelForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSVAntennaModelForEachSV";
      inline static const char* const Documentation = "Set the antenna model for all satellites.\n"      "\n"      "Name              Type         Description\n"      "----------------- ------------ -----------------------------------------------------------------------------------------------------\n"      "System            string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
      inline static const char* const TargetId = "";



          SetSVAntennaModelForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetSVAntennaModelForEachSV(const std::string& system, const std::vector<std::string>& antennaModelNames)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setAntennaModelNames(antennaModelNames);
          }


          static SetSVAntennaModelForEachSVPtr create(const std::string& system, const std::vector<std::string>& antennaModelNames)
          {
            return std::make_shared<SetSVAntennaModelForEachSV>(system, antennaModelNames);
          }

      static SetSVAntennaModelForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSVAntennaModelForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaModelNames"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "AntennaModelNames"}; 
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



          std::vector<std::string> antennaModelNames() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["AntennaModelNames"]);
          }

          void setAntennaModelNames(const std::vector<std::string>& antennaModelNames)
          {
            m_values.AddMember("AntennaModelNames", parse_json<std::vector<std::string>>::format(antennaModelNames, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetSVAntennaModelForEachSV);
  }
}

