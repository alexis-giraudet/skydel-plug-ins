#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsIonoOffsetEnabled.
    ///
    /// Name      Type Description
    /// --------- ---- ---------------------------------------------
    /// IsEnabled bool True if offsets are applied on the ionosphere
    ///

    class IsIonoOffsetEnabledResult;
    typedef std::shared_ptr<IsIonoOffsetEnabledResult> IsIonoOffsetEnabledResultPtr;
    
    
    class IsIonoOffsetEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsIonoOffsetEnabledResult";
      inline static const char* const Documentation = "Result of IsIonoOffsetEnabled.\n"      "\n"      "Name      Type Description\n"      "--------- ---- ---------------------------------------------\n"      "IsEnabled bool True if offsets are applied on the ionosphere";
      inline static const char* const TargetId = "";



          IsIonoOffsetEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsIonoOffsetEnabledResult(bool isEnabled)
            : CommandResult(CmdName, TargetId)
          {

            setIsEnabled(isEnabled);
          }

          IsIonoOffsetEnabledResult(CommandBasePtr relatedCommand, bool isEnabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIsEnabled(isEnabled);
          }



          static IsIonoOffsetEnabledResultPtr create(bool isEnabled)
          {
            return std::make_shared<IsIonoOffsetEnabledResult>(isEnabled);
          }

          static IsIonoOffsetEnabledResultPtr create(CommandBasePtr relatedCommand, bool isEnabled)
          {
            return std::make_shared<IsIonoOffsetEnabledResult>(relatedCommand, isEnabled);
          }

      static IsIonoOffsetEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsIonoOffsetEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["IsEnabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"IsEnabled"}; 
        return names; 
      }
      


          bool isEnabled() const
          {
            return parse_json<bool>::parse(m_values["IsEnabled"]);
          }

          void setIsEnabled(bool isEnabled)
          {
            m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsIonoOffsetEnabledResult);
  }
}

