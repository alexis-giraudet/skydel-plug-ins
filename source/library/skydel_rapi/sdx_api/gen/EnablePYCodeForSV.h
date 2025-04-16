#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) P(Y)-Code for specified satellite.
    ///
    /// Name    Type   Description
    /// ------- ------ -----------------------------------------------
    /// Signal  string Accepted signal keys: "L1P", "L2P"
    /// SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)
    /// Enabled bool   Enable P(Y)-Code if True
    ///

    class EnablePYCodeForSV;
    typedef std::shared_ptr<EnablePYCodeForSV> EnablePYCodeForSVPtr;
    
    
    class EnablePYCodeForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnablePYCodeForSV";
      inline static const char* const Documentation = "Enable (or disable) P(Y)-Code for specified satellite.\n"      "\n"      "Name    Type   Description\n"      "------- ------ -----------------------------------------------\n"      "Signal  string Accepted signal keys: \"L1P\", \"L2P\"\n"      "SvId    int    The satellite's SV ID 1..32 (use 0 for all SVs)\n"      "Enabled bool   Enable P(Y)-Code if True";
      inline static const char* const TargetId = "";



          EnablePYCodeForSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnablePYCodeForSV(const std::string& signal, int svId, bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
            setSvId(svId);
            setEnabled(enabled);
          }


          static EnablePYCodeForSVPtr create(const std::string& signal, int svId, bool enabled)
          {
            return std::make_shared<EnablePYCodeForSV>(signal, svId, enabled);
          }

      static EnablePYCodeForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnablePYCodeForSV>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(EnablePYCodeForSV);
  }
}

