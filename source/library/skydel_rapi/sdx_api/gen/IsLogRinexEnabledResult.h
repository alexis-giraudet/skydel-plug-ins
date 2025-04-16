#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsLogRinexEnabled.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------
    /// Enabled bool If true, files will be created during simulation
    ///

    class IsLogRinexEnabledResult;
    typedef std::shared_ptr<IsLogRinexEnabledResult> IsLogRinexEnabledResultPtr;
    
    
    class IsLogRinexEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsLogRinexEnabledResult";
      inline static const char* const Documentation = "Result of IsLogRinexEnabled.\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------------------------------------\n"      "Enabled bool If true, files will be created during simulation";
      inline static const char* const TargetId = "";



          IsLogRinexEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsLogRinexEnabledResult(bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
          }

          IsLogRinexEnabledResult(CommandBasePtr relatedCommand, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
          }



          static IsLogRinexEnabledResultPtr create(bool enabled)
          {
            return std::make_shared<IsLogRinexEnabledResult>(enabled);
          }

          static IsLogRinexEnabledResultPtr create(CommandBasePtr relatedCommand, bool enabled)
          {
            return std::make_shared<IsLogRinexEnabledResult>(relatedCommand, enabled);
          }

      static IsLogRinexEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsLogRinexEnabledResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsLogRinexEnabledResult);
  }
}

