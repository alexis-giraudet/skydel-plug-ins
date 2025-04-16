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
    /// Get the PRNs transmitted by the SV ID for these signals.
    ///
    /// Name        Type         Description
    /// ----------- ------------ ---------------------------------------------------------------------------
    /// SvId        int          Satellite SV ID.
    /// SignalArray array string An array of signals.
    ///                          Accepted values are: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2",
    ///                                               "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA",
    ///                                               "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S",
    ///                                               "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
    ///                                               "PULSARXL", "PULSARX1" and "PULSARX5"
    ///

    class GetTransmittedPrnForSV;
    typedef std::shared_ptr<GetTransmittedPrnForSV> GetTransmittedPrnForSVPtr;
    
    
    class GetTransmittedPrnForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetTransmittedPrnForSV";
      inline static const char* const Documentation = "Get the PRNs transmitted by the SV ID for these signals.\n"      "\n"      "Name        Type         Description\n"      "----------- ------------ ---------------------------------------------------------------------------\n"      "SvId        int          Satellite SV ID.\n"      "SignalArray array string An array of signals.\n"      "                         Accepted values are: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\",\n"      "                                              \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\",\n"      "                                              \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\",\n"      "                                              \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"      "                                              \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"";
      inline static const char* const TargetId = "";



          GetTransmittedPrnForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetTransmittedPrnForSV(int svId, const std::vector<std::string>& signalArray)
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setSignalArray(signalArray);
          }


          static GetTransmittedPrnForSVPtr create(int svId, const std::vector<std::string>& signalArray)
          {
            return std::make_shared<GetTransmittedPrnForSV>(svId, signalArray);
          }

      static GetTransmittedPrnForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetTransmittedPrnForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "SignalArray"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetTransmittedPrnForSV);
  }
}

