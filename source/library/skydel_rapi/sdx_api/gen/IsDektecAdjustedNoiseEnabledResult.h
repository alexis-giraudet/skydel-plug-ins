#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsDektecAdjustedNoiseEnabled.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------------
    /// Enable bool True to enable Advance Jammer noise adjustment on Dektec output.
    ///

    class IsDektecAdjustedNoiseEnabledResult;
    typedef std::shared_ptr<IsDektecAdjustedNoiseEnabledResult> IsDektecAdjustedNoiseEnabledResultPtr;
    
    
    class IsDektecAdjustedNoiseEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsDektecAdjustedNoiseEnabledResult";
      inline static const char* const Documentation = "Result of IsDektecAdjustedNoiseEnabled.\n"      "\n"      "Name   Type Description\n"      "------ ---- ----------------------------------------------------------------\n"      "Enable bool True to enable Advance Jammer noise adjustment on Dektec output.";
      inline static const char* const TargetId = "";



          IsDektecAdjustedNoiseEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsDektecAdjustedNoiseEnabledResult(bool enable)
            : CommandResult(CmdName, TargetId)
          {

            setEnable(enable);
          }

          IsDektecAdjustedNoiseEnabledResult(CommandBasePtr relatedCommand, bool enable)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnable(enable);
          }



          static IsDektecAdjustedNoiseEnabledResultPtr create(bool enable)
          {
            return std::make_shared<IsDektecAdjustedNoiseEnabledResult>(enable);
          }

          static IsDektecAdjustedNoiseEnabledResultPtr create(CommandBasePtr relatedCommand, bool enable)
          {
            return std::make_shared<IsDektecAdjustedNoiseEnabledResult>(relatedCommand, enable);
          }

      static IsDektecAdjustedNoiseEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsDektecAdjustedNoiseEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enable"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enable"}; 
        return names; 
      }
      


          bool enable() const
          {
            return parse_json<bool>::parse(m_values["Enable"]);
          }

          void setEnable(bool enable)
          {
            m_values.AddMember("Enable", parse_json<bool>::format(enable, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsDektecAdjustedNoiseEnabledResult);
  }
}

