#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsPropagationDelayEnabled.
    ///
    /// Name    Type   Description
    /// ------- ------ -------------------------------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.
    ///

    class IsPropagationDelayEnabledResult;
    typedef std::shared_ptr<IsPropagationDelayEnabledResult> IsPropagationDelayEnabledResultPtr;
    
    
    class IsPropagationDelayEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsPropagationDelayEnabledResult";
      inline static const char* const Documentation = "Result of IsPropagationDelayEnabled.\n"      "\n"      "Name    Type   Description\n"      "------- ------ -------------------------------------------------------------------------------------------------\n"      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Enabled bool   If false, the propagation delay between the GPS satellite and the receiver is forced to 0 second.";
      inline static const char* const TargetId = "";



          IsPropagationDelayEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsPropagationDelayEnabledResult(const std::string& system, bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setEnabled(enabled);
          }

          IsPropagationDelayEnabledResult(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setEnabled(enabled);
          }



          static IsPropagationDelayEnabledResultPtr create(const std::string& system, bool enabled)
          {
            return std::make_shared<IsPropagationDelayEnabledResult>(system, enabled);
          }

          static IsPropagationDelayEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool enabled)
          {
            return std::make_shared<IsPropagationDelayEnabledResult>(relatedCommand, system, enabled);
          }

      static IsPropagationDelayEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsPropagationDelayEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
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



          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsPropagationDelayEnabledResult);
  }
}

