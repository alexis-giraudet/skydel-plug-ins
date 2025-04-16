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
    /// Result of GetPseudorangeNoiseOffsetForSV.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    Satellite SV ID.
    /// Enabled bool   If true, the offset is enabled (applied)
    /// Offset  double The constant offset in metters
    ///

    class GetPseudorangeNoiseOffsetForSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseOffsetForSVResult> GetPseudorangeNoiseOffsetForSVResultPtr;
    
    
    class GetPseudorangeNoiseOffsetForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetPseudorangeNoiseOffsetForSVResult";
      inline static const char* const Documentation = "Result of GetPseudorangeNoiseOffsetForSV.\n"      "\n"      "Name    Type   Description\n"      "------- ------ --------------------------------------------------------------------------\n"      "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId    int    Satellite SV ID.\n"      "Enabled bool   If true, the offset is enabled (applied)\n"      "Offset  double The constant offset in metters";
      inline static const char* const TargetId = "";



          GetPseudorangeNoiseOffsetForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetPseudorangeNoiseOffsetForSVResult(const std::string& system, int svId, bool enabled, double offset)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setEnabled(enabled);
            setOffset(offset);
          }

          GetPseudorangeNoiseOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled, double offset)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setEnabled(enabled);
            setOffset(offset);
          }



          static GetPseudorangeNoiseOffsetForSVResultPtr create(const std::string& system, int svId, bool enabled, double offset)
          {
            return std::make_shared<GetPseudorangeNoiseOffsetForSVResult>(system, svId, enabled, offset);
          }

          static GetPseudorangeNoiseOffsetForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled, double offset)
          {
            return std::make_shared<GetPseudorangeNoiseOffsetForSVResult>(relatedCommand, system, svId, enabled, offset);
          }

      static GetPseudorangeNoiseOffsetForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPseudorangeNoiseOffsetForSVResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetPseudorangeNoiseOffsetForSVResult);
  }
}

