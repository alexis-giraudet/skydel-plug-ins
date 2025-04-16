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
    /// Enable or disable each satellite for this constellation.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------------------------------
    /// System  string     The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool Array of present/absent flags for the constellation
    ///

    class EnableEachSV;
    typedef std::shared_ptr<EnableEachSV> EnableEachSVPtr;
    
    
    class EnableEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableEachSV";
      inline static const char* const Documentation = "Enable or disable each satellite for this constellation.\n"      "\n"      "Name    Type       Description\n"      "------- ---------- ----------------------------------------------------------------------------------------------------------------\n"      "System  string     The satellites' constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Enabled array bool Array of present/absent flags for the constellation";
      inline static const char* const TargetId = "";



          EnableEachSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnableEachSV(const std::string& system, const std::vector<bool>& enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setEnabled(enabled);
          }


          static EnableEachSVPtr create(const std::string& system, const std::vector<bool>& enabled)
          {
            return std::make_shared<EnableEachSV>(system, enabled);
          }

      static EnableEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableEachSV>(ptr);
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



          std::vector<bool> enabled() const
          {
            return parse_json<std::vector<bool>>::parse(m_values["Enabled"]);
          }

          void setEnabled(const std::vector<bool>& enabled)
          {
            m_values.AddMember("Enabled", parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnableEachSV);
  }
}

