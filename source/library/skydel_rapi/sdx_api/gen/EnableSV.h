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
    /// Enable or disable a satellite for this constellation.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------------------------------------------------------
    /// System  string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    The satellite's SV ID (use 0 for all SVs).
    /// Enabled bool   The satellite will be present/absent from the constellation
    ///

    class EnableSV;
    typedef std::shared_ptr<EnableSV> EnableSVPtr;
    
    
    class EnableSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableSV";
      inline static const char* const Documentation = "Enable or disable a satellite for this constellation.\n"      "\n"      "Name    Type   Description\n"      "------- ------ ----------------------------------------------------------------------------------------------------------------\n"      "System  string The satellite's constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId    int    The satellite's SV ID (use 0 for all SVs).\n"      "Enabled bool   The satellite will be present/absent from the constellation";
      inline static const char* const TargetId = "";



          EnableSV()
            : CommandBase(CmdName, TargetId)
          {}

          EnableSV(const std::string& system, int svId, bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setEnabled(enabled);
          }


          static EnableSVPtr create(const std::string& system, int svId, bool enabled)
          {
            return std::make_shared<EnableSV>(system, svId, enabled);
          }

      static EnableSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Enabled"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(EnableSV);
  }
}

