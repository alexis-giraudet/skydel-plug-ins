#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetManualPowerOffsetForSV.
    ///
    /// Name                  Type               Description
    /// --------------------- ------------------ -----------------------------------------------------------------------------
    /// System                string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId                  int                The satellite's SV ID.
    /// SignalPowerOffsetDict dict string:double A dictionary of signal poweroffset pairs.
    ///                                          Accepted keys are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P",
    ///                                                             "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
    ///                                                             "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                                             "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                                             "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                                             "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and
    ///                                                             "PULSARX5"
    ///

    class GetManualPowerOffsetForSVResult;
    typedef std::shared_ptr<GetManualPowerOffsetForSVResult> GetManualPowerOffsetForSVResultPtr;
    
    
    class GetManualPowerOffsetForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetManualPowerOffsetForSVResult";
      inline static const char* const Documentation = "Result of GetManualPowerOffsetForSV.\n"      "\n"      "Name                  Type               Description\n"      "--------------------- ------------------ -----------------------------------------------------------------------------\n"      "System                string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "SvId                  int                The satellite's SV ID.\n"      "SignalPowerOffsetDict dict string:double A dictionary of signal poweroffset pairs.\n"      "                                         Accepted keys are: \"All\", \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\",\n"      "                                                            \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\",\n"      "                                                            \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"      "                                                            \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"      "                                                            \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"      "                                                            \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and\n"      "                                                            \"PULSARX5\"";
      inline static const char* const TargetId = "";



          GetManualPowerOffsetForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetManualPowerOffsetForSVResult(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setSignalPowerOffsetDict(signalPowerOffsetDict);
          }

          GetManualPowerOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setSignalPowerOffsetDict(signalPowerOffsetDict);
          }



          static GetManualPowerOffsetForSVResultPtr create(const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
          {
            return std::make_shared<GetManualPowerOffsetForSVResult>(system, svId, signalPowerOffsetDict);
          }

          static GetManualPowerOffsetForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::map<std::string, double>& signalPowerOffsetDict)
          {
            return std::make_shared<GetManualPowerOffsetForSVResult>(relatedCommand, system, svId, signalPowerOffsetDict);
          }

      static GetManualPowerOffsetForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetManualPowerOffsetForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::map<std::string, double>>::is_valid(m_values["SignalPowerOffsetDict"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "SignalPowerOffsetDict"}; 
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



          std::map<std::string, double> signalPowerOffsetDict() const
          {
            return parse_json<std::map<std::string, double>>::parse(m_values["SignalPowerOffsetDict"]);
          }

          void setSignalPowerOffsetDict(const std::map<std::string, double>& signalPowerOffsetDict)
          {
            m_values.AddMember("SignalPowerOffsetDict", parse_json<std::map<std::string, double>>::format(signalPowerOffsetDict, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetManualPowerOffsetForSVResult);
  }
}

