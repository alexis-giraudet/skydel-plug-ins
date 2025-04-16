#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) OSNMA for specified Galileo's satellite.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).
    /// Enabled bool OSNMA is enabled when value is True.
    ///

    class EnableOsnmaForSV;
    typedef std::shared_ptr<EnableOsnmaForSV> EnableOsnmaForSVPtr;
    
    
    class EnableOsnmaForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableOsnmaForSV";
      inline static const char* const Documentation = "Enable (or disable) OSNMA for specified Galileo's satellite.\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------------------------------------------------\n"      "SvId    int  The satellite's SV ID (use 0 for all Galileo's satellites).\n"      "Enabled bool OSNMA is enabled when value is True.";
      inline static const char* const TargetId = "";



          EnableOsnmaForSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnableOsnmaForSV(int svId, bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setEnabled(enabled);
          }


          static EnableOsnmaForSVPtr create(int svId, bool enabled)
          {
            return std::make_shared<EnableOsnmaForSV>(svId, enabled);
          }

      static EnableOsnmaForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableOsnmaForSV>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(EnableOsnmaForSV);
  }
}

