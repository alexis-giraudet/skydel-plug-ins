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
    /// Result of GetSVAntennaModelForSV.
    ///
    /// Name             Type   Description
    /// ---------------- ------ ---------------------------------------------------------------------------
    /// System           string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId             int    The satellite's SV ID.
    /// AntennaModelName string SV antenna model name.
    ///

    class GetSVAntennaModelForSVResult;
    typedef std::shared_ptr<GetSVAntennaModelForSVResult> GetSVAntennaModelForSVResultPtr;
    
    
    class GetSVAntennaModelForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSVAntennaModelForSVResult";
      inline static const char* const Documentation = "Result of GetSVAntennaModelForSV.\n"      "\n"      "Name             Type   Description\n"      "---------------- ------ ---------------------------------------------------------------------------\n"      "System           string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "SvId             int    The satellite's SV ID.\n"      "AntennaModelName string SV antenna model name.";
      inline static const char* const TargetId = "";



          GetSVAntennaModelForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSVAntennaModelForSVResult(const std::string& system, int svId, const std::string& antennaModelName)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setAntennaModelName(antennaModelName);
          }

          GetSVAntennaModelForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& antennaModelName)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setAntennaModelName(antennaModelName);
          }



          static GetSVAntennaModelForSVResultPtr create(const std::string& system, int svId, const std::string& antennaModelName)
          {
            return std::make_shared<GetSVAntennaModelForSVResult>(system, svId, antennaModelName);
          }

          static GetSVAntennaModelForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& antennaModelName)
          {
            return std::make_shared<GetSVAntennaModelForSVResult>(relatedCommand, system, svId, antennaModelName);
          }

      static GetSVAntennaModelForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSVAntennaModelForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["AntennaModelName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "AntennaModelName"}; 
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



          std::string antennaModelName() const
          {
            return parse_json<std::string>::parse(m_values["AntennaModelName"]);
          }

          void setAntennaModelName(const std::string& antennaModelName)
          {
            m_values.AddMember("AntennaModelName", parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSVAntennaModelForSVResult);
  }
}

