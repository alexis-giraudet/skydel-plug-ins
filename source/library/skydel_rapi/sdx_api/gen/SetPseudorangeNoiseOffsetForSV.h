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
    /// Set the satellite pseudorange noise constant offset.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    Satellite SV ID.
    /// Enabled bool   If true, the offset is enabled (applied)
    /// Offset  double The constant offset in metters
    ///

    class SetPseudorangeNoiseOffsetForSV;
    typedef std::shared_ptr<SetPseudorangeNoiseOffsetForSV> SetPseudorangeNoiseOffsetForSVPtr;
    
    
    class SetPseudorangeNoiseOffsetForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetPseudorangeNoiseOffsetForSV";
      inline static const char* const Documentation = "Set the satellite pseudorange noise constant offset.\n"      "\n"      "Name    Type   Description\n"      "------- ------ --------------------------------------------------------------------------\n"      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId    int    Satellite SV ID.\n"      "Enabled bool   If true, the offset is enabled (applied)\n"      "Offset  double The constant offset in metters";
      inline static const char* const TargetId = "";



          SetPseudorangeNoiseOffsetForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetPseudorangeNoiseOffsetForSV(const std::string& system, int svId, bool enabled, double offset)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setEnabled(enabled);
            setOffset(offset);
          }


          static SetPseudorangeNoiseOffsetForSVPtr create(const std::string& system, int svId, bool enabled, double offset)
          {
            return std::make_shared<SetPseudorangeNoiseOffsetForSV>(system, svId, enabled, offset);
          }

      static SetPseudorangeNoiseOffsetForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetPseudorangeNoiseOffsetForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<double>::is_valid(m_values["Offset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Enabled", "Offset"}; 
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



          double offset() const
          {
            return parse_json<double>::parse(m_values["Offset"]);
          }

          void setOffset(double offset)
          {
            m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetPseudorangeNoiseOffsetForSV);
  }
}

