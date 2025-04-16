#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSimulationStopAtTrajectoryEndEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------------
    /// Enabled bool If true, simulation will stop when the vehicle will reach trajectory end
    ///

    class IsSimulationStopAtTrajectoryEndEnabledResult;
    typedef std::shared_ptr<IsSimulationStopAtTrajectoryEndEnabledResult> IsSimulationStopAtTrajectoryEndEnabledResultPtr;
    
    
    class IsSimulationStopAtTrajectoryEndEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsSimulationStopAtTrajectoryEndEnabledResult";
      inline static const char* const Documentation = "Result of IsSimulationStopAtTrajectoryEndEnabled.\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------------------------------------------------------------\n"      "Enabled bool If true, simulation will stop when the vehicle will reach trajectory end";
      inline static const char* const TargetId = "";



          IsSimulationStopAtTrajectoryEndEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsSimulationStopAtTrajectoryEndEnabledResult(bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
          }

          IsSimulationStopAtTrajectoryEndEnabledResult(CommandBasePtr relatedCommand, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
          }



          static IsSimulationStopAtTrajectoryEndEnabledResultPtr create(bool enabled)
          {
            return std::make_shared<IsSimulationStopAtTrajectoryEndEnabledResult>(enabled);
          }

          static IsSimulationStopAtTrajectoryEndEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
          {
            return std::make_shared<IsSimulationStopAtTrajectoryEndEnabledResult>(relatedCommand, enabled);
          }

      static IsSimulationStopAtTrajectoryEndEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSimulationStopAtTrajectoryEndEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled"}; 
        return names; 
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
    REGISTER_COMMAND_TO_FACTORY(IsSimulationStopAtTrajectoryEndEnabledResult);
  }
}

