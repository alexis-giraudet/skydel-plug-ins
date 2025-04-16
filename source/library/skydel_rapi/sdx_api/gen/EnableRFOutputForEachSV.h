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
    /// Enable (or disable) RF output for each satellite individually.
    ///
    /// Name    Type       Description
    /// ------- ---------- -------------------------------------------------------------------------------------------------
    /// System  string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool RF is enabled when value is True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc).
    ///

    class EnableRFOutputForEachSV;
    typedef std::shared_ptr<EnableRFOutputForEachSV> EnableRFOutputForEachSVPtr;
    
    
    class EnableRFOutputForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableRFOutputForEachSV";
      inline static const char* const Documentation = "Enable (or disable) RF output for each satellite individually.\n"      "\n"      "Name    Type       Description\n"      "------- ---------- -------------------------------------------------------------------------------------------------\n"      "System  string     \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Enabled array bool RF is enabled when value is True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc).";
      inline static const char* const TargetId = "";



          EnableRFOutputForEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnableRFOutputForEachSV(const std::string& system, const std::vector<bool>& enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setEnabled(enabled);
          }


          static EnableRFOutputForEachSVPtr create(const std::string& system, const std::vector<bool>& enabled)
          {
            return std::make_shared<EnableRFOutputForEachSV>(system, enabled);
          }

      static EnableRFOutputForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableRFOutputForEachSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "Enabled"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<bool> enabled() const
          {
            return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
          }

          void setEnabled(const std::vector<bool>& enabled)
          {
            m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnableRFOutputForEachSV);
  }
}

