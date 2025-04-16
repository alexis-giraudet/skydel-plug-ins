#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsElevationMaskBelowEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------
    /// Enabled bool If true, mask satellites with elevation angle below masking angle.
    ///

    class IsElevationMaskBelowEnabledResult;
    typedef std::shared_ptr<IsElevationMaskBelowEnabledResult> IsElevationMaskBelowEnabledResultPtr;
    
    
    class IsElevationMaskBelowEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsElevationMaskBelowEnabledResult";
      inline static const char* const Documentation = "Result of IsElevationMaskBelowEnabled.\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------------------------------------------------------\n"      "Enabled bool If true, mask satellites with elevation angle below masking angle.";
      inline static const char* const TargetId = "";



          IsElevationMaskBelowEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsElevationMaskBelowEnabledResult(bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
          }

          IsElevationMaskBelowEnabledResult(CommandBasePtr relatedCommand, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
          }



          static IsElevationMaskBelowEnabledResultPtr create(bool enabled)
          {
            return std::make_shared<IsElevationMaskBelowEnabledResult>(enabled);
          }

          static IsElevationMaskBelowEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
          {
            return std::make_shared<IsElevationMaskBelowEnabledResult>(relatedCommand, enabled);
          }

      static IsElevationMaskBelowEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsElevationMaskBelowEnabledResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsElevationMaskBelowEnabledResult);
  }
}

