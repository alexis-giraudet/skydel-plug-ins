#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSpectrumVisible.
    ///
    /// Name    Type Description
    /// ------- ---- ------------------
    /// Visible bool Show spectrum flag
    ///

    class IsSpectrumVisibleResult;
    typedef std::shared_ptr<IsSpectrumVisibleResult> IsSpectrumVisibleResultPtr;
    
    
    class IsSpectrumVisibleResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsSpectrumVisibleResult";
      inline static const char* const Documentation = "Result of IsSpectrumVisible.\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------\n"      "Visible bool Show spectrum flag";
      inline static const char* const TargetId = "";



          IsSpectrumVisibleResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsSpectrumVisibleResult(bool visible)
            : CommandResult(CmdName, TargetId)
          {

            setVisible(visible);
          }

          IsSpectrumVisibleResult(CommandBasePtr relatedCommand, bool visible)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setVisible(visible);
          }



          static IsSpectrumVisibleResultPtr create(bool visible)
          {
            return std::make_shared<IsSpectrumVisibleResult>(visible);
          }

          static IsSpectrumVisibleResultPtr create(CommandBasePtr relatedCommand, bool visible)
          {
            return std::make_shared<IsSpectrumVisibleResult>(relatedCommand, visible);
          }

      static IsSpectrumVisibleResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSpectrumVisibleResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Visible"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Visible"}; 
        return names; 
      }
      


          bool visible() const
          {
            return parse_json<bool>::parse(m_values["Visible"]);
          }

          void setVisible(bool visible)
          {
            m_values.AddMember("Visible", parse_json<bool>::format(visible, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsSpectrumVisibleResult);
  }
}

