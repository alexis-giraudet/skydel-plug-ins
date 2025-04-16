#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsOsnmaEnabledForSV.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).
    /// Enabled bool OSNMA is enabled when value is True.
    ///

    class IsOsnmaEnabledForSVResult;
    typedef std::shared_ptr<IsOsnmaEnabledForSVResult> IsOsnmaEnabledForSVResultPtr;
    
    
    class IsOsnmaEnabledForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsOsnmaEnabledForSVResult";
      inline static const char* const Documentation = "Result of IsOsnmaEnabledForSV.\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------------------------------------------------\n"      "SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).\n"      "Enabled bool OSNMA is enabled when value is True.";
      inline static const char* const TargetId = "";



          IsOsnmaEnabledForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsOsnmaEnabledForSVResult(int svId, bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setEnabled(enabled);
          }

          IsOsnmaEnabledForSVResult(CommandBasePtr relatedCommand, int svId, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setEnabled(enabled);
          }



          static IsOsnmaEnabledForSVResultPtr create(int svId, bool enabled)
          {
            return std::make_shared<IsOsnmaEnabledForSVResult>(svId, enabled);
          }

          static IsOsnmaEnabledForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool enabled)
          {
            return std::make_shared<IsOsnmaEnabledForSVResult>(relatedCommand, svId, enabled);
          }

      static IsOsnmaEnabledForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsOsnmaEnabledForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Enabled"}; 
        return names; 
      }
      


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(IsOsnmaEnabledForSVResult);
  }
}

