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
    /// Result of IsPYCodeEnabledForSV.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------
    /// Signal  string Accepted signal keys: "L1P", "L2P"
    /// SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)
    /// Enabled bool   Enable P(Y)-Code if True
    ///

    class IsPYCodeEnabledForSVResult;
    typedef std::shared_ptr<IsPYCodeEnabledForSVResult> IsPYCodeEnabledForSVResultPtr;
    
    
    class IsPYCodeEnabledForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsPYCodeEnabledForSVResult";
      inline static const char* const Documentation = "Result of IsPYCodeEnabledForSV.\n"      "\n"      "Name    Type   Description\n"      "------- ------ -----------------------------------------------\n"      "Signal  string Accepted signal keys: \"L1P\", \"L2P\"\n"      "SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)\n"      "Enabled bool   Enable P(Y)-Code if True";
      inline static const char* const TargetId = "";



          IsPYCodeEnabledForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsPYCodeEnabledForSVResult(const std::string& signal, int svId, bool enabled)
            : CommandResult(CmdName, TargetId)
          {

            setSignal(signal);
            setSvId(svId);
            setEnabled(enabled);
          }

          IsPYCodeEnabledForSVResult(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSignal(signal);
            setSvId(svId);
            setEnabled(enabled);
          }



          static IsPYCodeEnabledForSVResultPtr create(const std::string& signal, int svId, bool enabled)
          {
            return std::make_shared<IsPYCodeEnabledForSVResult>(signal, svId, enabled);
          }

          static IsPYCodeEnabledForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int svId, bool enabled)
          {
            return std::make_shared<IsPYCodeEnabledForSVResult>(relatedCommand, signal, svId, enabled);
          }

      static IsPYCodeEnabledForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsPYCodeEnabledForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "SvId", "Enabled"}; 
        return names; 
      }
      


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(IsPYCodeEnabledForSVResult);
  }
}

