#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the power information for the specified satellite.
    ///
    /// Name        Type         Description
    /// ----------- ------------ -------------------------------------------------------------------------------
    /// System      string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR".
    /// SvId        int          The Satellite's SV ID.
    /// SignalArray array string An array of signals.
    ///                          Accepted values are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P",
    ///                                               "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
    ///                                               "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                               "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                               "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                               "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and
    ///                                               "PULSARX5"
    ///

    class GetAllPowerForSV;
    typedef std::shared_ptr<GetAllPowerForSV> GetAllPowerForSVPtr;
    
    
    class GetAllPowerForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetAllPowerForSV";
      inline static const char* const Documentation = "Get the power information for the specified satellite.\n"      "\n"      "Name        Type         Description\n"      "----------- ------------ -------------------------------------------------------------------------------\n"      "System      string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "SvId        int          The Satellite's SV ID.\n"      "SignalArray array string An array of signals.\n"      "                         Accepted values are: \"All\", \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\",\n"      "                                              \"L2ME\", \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\",\n"      "                                              \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"      "                                              \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"      "                                              \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"      "                                              \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and\n"      "                                              \"PULSARX5\"";
      inline static const char* const TargetId = "";



          GetAllPowerForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetAllPowerForSV(const std::string& system, int svId, const std::vector<std::string>& signalArray)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setSignalArray(signalArray);
          }


          static GetAllPowerForSVPtr create(const std::string& system, int svId, const std::vector<std::string>& signalArray)
          {
            return std::make_shared<GetAllPowerForSV>(system, svId, signalArray);
          }

      static GetAllPowerForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllPowerForSV>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
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
    REGISTER_COMMAND_TO_FACTORY(GetAllPowerForSV);
  }
}

