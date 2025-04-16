#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"
#include <map>
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a block of data defining the orbit, clock, and other parameters for one SV.
    ///   ParamName           Unit
    ///   "Time of ephemeris" sec (of GPS week)
    ///   "Week Number"       week
    ///   "Transmission Time" sec (of GPS week)
    ///   "ClockBias"         sec
    ///   "ClockDrift"        sec/sec
    ///   "ClockDriftRate"    sec/sec^2
    ///   "Crs"               meter
    ///   "Crc"               meter
    ///   "Cis"               rad
    ///   "Cic"               rad
    ///   "Cus"               rad
    ///   "Cuc"               rad
    ///   "DeltaN"            rad/sec
    ///   "M0"                rad
    ///   "Eccentricity"      -
    ///   "SqrtA"             sqrt(meter)
    ///   "BigOmega"          rad
    ///   "I0"                rad
    ///   "LittleOmega"       rad
    ///   "BigOmegaDot"       rad/sec
    ///   "Idot"              rad/sec
    ///   "Accuracy"          meter
    ///   "Adot"              meters/sec
    ///   "DeltaN0dot"        rad/sec^2
    /// 
    /// After a block is pushed for a SV, no other block can be pushed for that SV until the interpolation period is over.
    ///   Constellation   Interpolation period (sec)
    ///   GPS             3600
    ///   Galileo         300
    ///   BeiDou          1800
    ///   QZSS            1800
    ///   NavIC           2400
    /// 
    ///
    /// Name           Type                  Description
    /// -------------- --------------------- ---------------------------------------------------------------------------------------
    /// System         string                "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR".
    /// SvId           int                   Satellite's SV ID.
    /// Toc            datetime              Time of Clock.
    /// ParametersDict dict string:double    A dictionary of parameters pairs.
    ///                                      Accepted keys are: "Time of ephemeris", "Week Number", "Transmission Time",
    ///                                                         "ClockBias", "ClockDrift", "ClockDriftRate", "Crs", "Crc",
    ///                                                         "Cis", "Cic", "Cus", "Cuc", "DeltaN", "M0", "Eccentricity",
    ///                                                         "SqrtA", "BigOmega", "I0", "LittleOmega", "BigOmegaDot",
    ///                                                         "Idot", "Adot", "DeltaN0dot", "UraIndex", "IODE", "IODNAV",
    ///                                                         "IODEC", "IODC", "Tgd", "IscL1CA", "IscL2C", "IscL5I5",
    ///                                                         "IscL5Q5", "IscL1CP", "IscL1CD", "BgdE1E5a", "BgdE1E5b",
    ///                                                         "Tgd1", "Tgd2", "TgdB1Cp", "TgdB2ap", "IscB1Cd", "IscB2ad",
    ///                                                         "SisaE1E5a" and "SisaE1E5b"
    /// DataSetTypes   optional array string Optional data set type array: "Ephemeris" or "Orbit". If not provided, applies to both.
    ///

    class PushDynamicSVData;
    typedef std::shared_ptr<PushDynamicSVData> PushDynamicSVDataPtr;
    
    
    class PushDynamicSVData : public CommandBase
    {
    public:
      inline static const char* const CmdName = "PushDynamicSVData";
      inline static const char* const Documentation = "Push a block of data defining the orbit, clock, and other parameters for one SV.\n"      "  ParamName           Unit\n"      "  \"Time of ephemeris\" sec (of GPS week)\n"      "  \"Week Number\"       week\n"      "  \"Transmission Time\" sec (of GPS week)\n"      "  \"ClockBias\"         sec\n"      "  \"ClockDrift\"        sec/sec\n"      "  \"ClockDriftRate\"    sec/sec^2\n"      "  \"Crs\"               meter\n"      "  \"Crc\"               meter\n"      "  \"Cis\"               rad\n"      "  \"Cic\"               rad\n"      "  \"Cus\"               rad\n"      "  \"Cuc\"               rad\n"      "  \"DeltaN\"            rad/sec\n"      "  \"M0\"                rad\n"      "  \"Eccentricity\"      -\n"      "  \"SqrtA\"             sqrt(meter)\n"      "  \"BigOmega\"          rad\n"      "  \"I0\"                rad\n"      "  \"LittleOmega\"       rad\n"      "  \"BigOmegaDot\"       rad/sec\n"      "  \"Idot\"              rad/sec\n"      "  \"Accuracy\"          meter\n"      "  \"Adot\"              meters/sec\n"      "  \"DeltaN0dot\"        rad/sec^2\n"      "\n"      "After a block is pushed for a SV, no other block can be pushed for that SV until the interpolation period is over.\n"      "  Constellation   Interpolation period (sec)\n"      "  GPS             3600\n"      "  Galileo         300\n"      "  BeiDou          1800\n"      "  QZSS            1800\n"      "  NavIC           2400\n"      "\n"      "\n"      "Name           Type                  Description\n"      "-------------- --------------------- ---------------------------------------------------------------------------------------\n"      "System         string                \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "SvId           int                   Satellite's SV ID.\n"      "Toc            datetime              Time of Clock.\n"      "ParametersDict dict string:double    A dictionary of parameters pairs.\n"      "                                     Accepted keys are: \"Time of ephemeris\", \"Week Number\", \"Transmission Time\",\n"      "                                                        \"ClockBias\", \"ClockDrift\", \"ClockDriftRate\", \"Crs\", \"Crc\",\n"      "                                                        \"Cis\", \"Cic\", \"Cus\", \"Cuc\", \"DeltaN\", \"M0\", \"Eccentricity\",\n"      "                                                        \"SqrtA\", \"BigOmega\", \"I0\", \"LittleOmega\", \"BigOmegaDot\",\n"      "                                                        \"Idot\", \"Adot\", \"DeltaN0dot\", \"UraIndex\", \"IODE\", \"IODNAV\",\n"      "                                                        \"IODEC\", \"IODC\", \"Tgd\", \"IscL1CA\", \"IscL2C\", \"IscL5I5\",\n"      "                                                        \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\", \"BgdE1E5a\", \"BgdE1E5b\",\n"      "                                                        \"Tgd1\", \"Tgd2\", \"TgdB1Cp\", \"TgdB2ap\", \"IscB1Cd\", \"IscB2ad\",\n"      "                                                        \"SisaE1E5a\" and \"SisaE1E5b\"\n"      "DataSetTypes   optional array string Optional data set type array: \"Ephemeris\" or \"Orbit\". If not provided, applies to both.";
      inline static const char* const TargetId = "";



          PushDynamicSVData()
            : CommandBase(CmdName, TargetId)
          {}

          PushDynamicSVData(const std::string& system, int svId, const Sdx::DateTime& toc, const std::map<std::string, double>& parametersDict, const std::optional<std::vector<std::string>>& dataSetTypes = {})
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setToc(toc);
            setParametersDict(parametersDict);
            setDataSetTypes(dataSetTypes);
          }


          static PushDynamicSVDataPtr create(const std::string& system, int svId, const Sdx::DateTime& toc, const std::map<std::string, double>& parametersDict, const std::optional<std::vector<std::string>>& dataSetTypes = {})
          {
            return std::make_shared<PushDynamicSVData>(system, svId, toc, parametersDict, dataSetTypes);
          }

      static PushDynamicSVDataPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<PushDynamicSVData>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<Sdx::DateTime>::is_valid(m_values["Toc"])
                  && parse_json<std::map<std::string, double>>::is_valid(m_values["ParametersDict"])
                  && parse_json<std::optional<std::vector<std::string>>>::is_valid(m_values["DataSetTypes"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Toc", "ParametersDict", "DataSetTypes"}; 
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



          Sdx::DateTime toc() const
          {
            return parse_json<Sdx::DateTime>::parse(m_values["Toc"]);
          }

          void setToc(const Sdx::DateTime& toc)
          {
            m_values.AddMember("Toc", parse_json<Sdx::DateTime>::format(toc, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::map<std::string, double> parametersDict() const
          {
            return parse_json<std::map<std::string, double>>::parse(m_values["ParametersDict"]);
          }

          void setParametersDict(const std::map<std::string, double>& parametersDict)
          {
            m_values.AddMember("ParametersDict", parse_json<std::map<std::string, double>>::format(parametersDict, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::vector<std::string>> dataSetTypes() const
          {
            return parse_json<std::optional<std::vector<std::string>>>::parse(m_values["DataSetTypes"]);
          }

          void setDataSetTypes(const std::optional<std::vector<std::string>>& dataSetTypes)
          {
            m_values.AddMember("DataSetTypes", parse_json<std::optional<std::vector<std::string>>>::format(dataSetTypes, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(PushDynamicSVData);
  }
}

