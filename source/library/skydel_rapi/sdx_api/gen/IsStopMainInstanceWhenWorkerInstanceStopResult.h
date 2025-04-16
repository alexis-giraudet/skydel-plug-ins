#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsStopMainInstanceWhenWorkerInstanceStop.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------
    /// Enabled bool Enable main instance stop when worker instance stops flag
    ///

    class IsStopMainInstanceWhenWorkerInstanceStopResult;
    typedef std::shared_ptr<IsStopMainInstanceWhenWorkerInstanceStopResult> IsStopMainInstanceWhenWorkerInstanceStopResultPtr;
    
    
    class IsStopMainInstanceWhenWorkerInstanceStopResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsStopMainInstanceWhenWorkerInstanceStopResult";
      inline static const char* const Documentation = "Result of IsStopMainInstanceWhenWorkerInstanceStop.\n"      "\n"      "Name    Type Description\n"      "------- ---- ---------------------------------------------------------\n"      "Enabled bool Enable main instance stop when worker instance stops flag";
      inline static const char* const TargetId = "";



          IsStopMainInstanceWhenWorkerInstanceStopResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsStopMainInstanceWhenWorkerInstanceStopResult(bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
          }

          IsStopMainInstanceWhenWorkerInstanceStopResult(CommandBasePtr relatedCommand, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
          }



          static IsStopMainInstanceWhenWorkerInstanceStopResultPtr create(bool enabled)
          {
            return std::make_shared<IsStopMainInstanceWhenWorkerInstanceStopResult>(enabled);
          }

          static IsStopMainInstanceWhenWorkerInstanceStopResultPtr create(CommandBasePtr relatedCommand, bool enabled)
          {
            return std::make_shared<IsStopMainInstanceWhenWorkerInstanceStopResult>(relatedCommand, enabled);
          }

      static IsStopMainInstanceWhenWorkerInstanceStopResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsStopMainInstanceWhenWorkerInstanceStopResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsStopMainInstanceWhenWorkerInstanceStopResult);
  }
}

