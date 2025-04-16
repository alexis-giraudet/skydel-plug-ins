#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSignalStrengthModelEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// Enabled bool If true, signal strengh model is enabled for all satellites
    ///

    class IsSignalStrengthModelEnabledResult;
    typedef std::shared_ptr<IsSignalStrengthModelEnabledResult> IsSignalStrengthModelEnabledResultPtr;
    
    
    class IsSignalStrengthModelEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsSignalStrengthModelEnabledResult";
      inline static const char* const Documentation = "Result of IsSignalStrengthModelEnabled.\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------------------------------------------------\n"      "Enabled bool If true, signal strengh model is enabled for all satellites";
      inline static const char* const TargetId = "";



          IsSignalStrengthModelEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsSignalStrengthModelEnabledResult(bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
          }

          IsSignalStrengthModelEnabledResult(CommandBasePtr relatedCommand, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
          }



          static IsSignalStrengthModelEnabledResultPtr create(bool enabled)
          {
            return std::make_shared<IsSignalStrengthModelEnabledResult>(enabled);
          }

          static IsSignalStrengthModelEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
          {
            return std::make_shared<IsSignalStrengthModelEnabledResult>(relatedCommand, enabled);
          }

      static IsSignalStrengthModelEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSignalStrengthModelEnabledResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsSignalStrengthModelEnabledResult);
  }
}

