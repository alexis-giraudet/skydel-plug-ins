#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPerturbations.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// System      string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId        int             The satellite's SV ID.
    /// Crs         double          Crs (meter)
    /// Crc         double          Crc (meter)
    /// Cis         double          Cis (rad)
    /// Cic         double          Cic (rad)
    /// Cus         double          Cus (rad)
    /// Cuc         double          Cuc (rad)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetPerturbationsResult;
    typedef std::shared_ptr<GetPerturbationsResult> GetPerturbationsResultPtr;
    
    
    class GetPerturbationsResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetPerturbationsResult";
      inline static const char* const Documentation = "Result of GetPerturbations.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId        int             The satellite's SV ID.\n"      "Crs         double          Crs (meter)\n"      "Crc         double          Crc (meter)\n"      "Cis         double          Cis (rad)\n"      "Cic         double          Cic (rad)\n"      "Cus         double          Cus (rad)\n"      "Cuc         double          Cuc (rad)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetPerturbationsResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetPerturbationsResult(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setCrs(crs);
            setCrc(crc);
            setCis(cis);
            setCic(cic);
            setCus(cus);
            setCuc(cuc);
            setDataSetName(dataSetName);
          }

          GetPerturbationsResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setCrs(crs);
            setCrc(crc);
            setCis(cis);
            setCic(cic);
            setCus(cus);
            setCuc(cuc);
            setDataSetName(dataSetName);
          }



          static GetPerturbationsResultPtr create(const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetPerturbationsResult>(system, svId, crs, crc, cis, cic, cus, cuc, dataSetName);
          }

          static GetPerturbationsResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, double crs, double crc, double cis, double cic, double cus, double cuc, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetPerturbationsResult>(relatedCommand, system, svId, crs, crc, cis, cic, cus, cuc, dataSetName);
          }

      static GetPerturbationsResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPerturbationsResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<double>::is_valid(m_values["Crs"])
                  && parse_json<double>::is_valid(m_values["Crc"])
                  && parse_json<double>::is_valid(m_values["Cis"])
                  && parse_json<double>::is_valid(m_values["Cic"])
                  && parse_json<double>::is_valid(m_values["Cus"])
                  && parse_json<double>::is_valid(m_values["Cuc"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Crs", "Crc", "Cis", "Cic", "Cus", "Cuc", "DataSetName"}; 
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



          double crs() const
          {
            return parse_json<double>::parse(m_values["Crs"]);
          }

          void setCrs(double crs)
          {
            m_values.AddMember("Crs", parse_json<double>::format(crs, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double crc() const
          {
            return parse_json<double>::parse(m_values["Crc"]);
          }

          void setCrc(double crc)
          {
            m_values.AddMember("Crc", parse_json<double>::format(crc, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double cis() const
          {
            return parse_json<double>::parse(m_values["Cis"]);
          }

          void setCis(double cis)
          {
            m_values.AddMember("Cis", parse_json<double>::format(cis, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double cic() const
          {
            return parse_json<double>::parse(m_values["Cic"]);
          }

          void setCic(double cic)
          {
            m_values.AddMember("Cic", parse_json<double>::format(cic, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double cus() const
          {
            return parse_json<double>::parse(m_values["Cus"]);
          }

          void setCus(double cus)
          {
            m_values.AddMember("Cus", parse_json<double>::format(cus, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double cuc() const
          {
            return parse_json<double>::parse(m_values["Cuc"]);
          }

          void setCuc(double cuc)
          {
            m_values.AddMember("Cuc", parse_json<double>::format(cuc, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::string> dataSetName() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::optional<std::string>& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPerturbationsResult);
  }
}

