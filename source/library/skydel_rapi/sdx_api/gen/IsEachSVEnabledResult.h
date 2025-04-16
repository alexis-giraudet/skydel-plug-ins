#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsEachSVEnabled.
    ///
    /// Name    Type       Description
    /// ------- ---------- ----------------------------------------------------------------------------------------------------------------
    /// System  string     The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool Array of present/absent flags for the constellation
    ///

    class IsEachSVEnabledResult;
    typedef std::shared_ptr<IsEachSVEnabledResult> IsEachSVEnabledResultPtr;
    
    
    class IsEachSVEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsEachSVEnabledResult";
      inline static const char* const Documentation = "Result of IsEachSVEnabled.\n"      "\n"      "Name    Type       Description\n"      "------- ---------- ----------------------------------------------------------------------------------------------------------------\n"      "System  string     The satellites' constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Enabled array bool Array of present/absent flags for the constellation";
      inline static const char* const TargetId = "";



          IsEachSVEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsEachSVEnabledResult(const std::string& system, const std::vector<bool>& enabled)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setEnabled(enabled);
          }

          IsEachSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setEnabled(enabled);
          }



          static IsEachSVEnabledResultPtr create(const std::string& system, const std::vector<bool>& enabled)
          {
            return std::make_shared<IsEachSVEnabledResult>(system, enabled);
          }

          static IsEachSVEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled)
          {
            return std::make_shared<IsEachSVEnabledResult>(relatedCommand, system, enabled);
          }

      static IsEachSVEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsEachSVEnabledResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsEachSVEnabledResult);
  }
}

