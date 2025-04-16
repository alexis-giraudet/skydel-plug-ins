#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEnabledSignalsForSV.
    ///
    /// Name        Type         Description
    /// ----------- ------------ ----------------------------------------------------------------------------------------------
    /// System      string       The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId        int          The satellite SV ID.
    /// SignalArray array string The list of enabled signals.
    ///

    class GetEnabledSignalsForSVResult;
    typedef std::shared_ptr<GetEnabledSignalsForSVResult> GetEnabledSignalsForSVResultPtr;
    
    
    class GetEnabledSignalsForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetEnabledSignalsForSVResult";
      inline static const char* const Documentation = "Result of GetEnabledSignalsForSV.\n"      "\n"      "Name        Type         Description\n"      "----------- ------------ ----------------------------------------------------------------------------------------------\n"      "System      string       The system, can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "SvId        int          The satellite SV ID.\n"      "SignalArray array string The list of enabled signals.";
      inline static const char* const TargetId = "";



          GetEnabledSignalsForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetEnabledSignalsForSVResult(const std::string& system, int svId, const std::vector<std::string>& signalArray)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setSignalArray(signalArray);
          }

          GetEnabledSignalsForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& signalArray)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setSignalArray(signalArray);
          }



          static GetEnabledSignalsForSVResultPtr create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
          {
            return std::make_shared<GetEnabledSignalsForSVResult>(system, svId, signalArray);
          }

          static GetEnabledSignalsForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& signalArray)
          {
            return std::make_shared<GetEnabledSignalsForSVResult>(relatedCommand, system, svId, signalArray);
          }

      static GetEnabledSignalsForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetEnabledSignalsForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "SignalArray"}; 
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



          std::vector<std::string> signalArray() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
          }

          void setSignalArray(const std::vector<std::string>& signalArray)
          {
            m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetEnabledSignalsForSVResult);
  }
}

