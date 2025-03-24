#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" constellation parameter value.
///
/// General constellation parameters:
///
///   Unit         Type     ParamName
///   sec          double   "ClockBias"
///   sec/sec      double   "ClockDrift"
///   sec/sec^2    double   "ClockDriftRate"
///   meter        double   "Crs", "Crc", "Accuracy"
///   meter/sec    double   "Adot"
///   rad          double   "Cis", "Cic", "Cus", "Cuc", "M0", "BigOmega", "I0", "LittleOmega"
///   rad/sec      double   "DeltaN", "BigOmegaDot", "Idot"
///   rad/sec^2    double   "DeltaN0dot"
///   sqrt(meter)  double   "SqrtA"
///   -            double   "Eccentricity"
///   -            integer  "Week Number", "Toe", "Transmission Time"
///
/// GPS:
///
///   Unit         Type     ParamName
///   sec          double   "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD", "IscL1ME",
///   "IscL2ME", "IscL1MR", "IscL2MR" sec          integer  "Fit interval"
///   -            integer  "IODE", "IODC", "UraIndex"
///   -            boolean  "IscL1CaAvailable", "IscL2CAvailable", "IscL5I5Available", "IscL5Q5Available",
///   "IscL1CPAvailable", "IscL1CDAvailable", "IscL1MEAvailable", "IscL2MEAvailable", "IscL1MRAvailable",
///   "IscL2MRAvailable"
///
/// Galileo:
///
///   Unit         Type     ParamName
///   sec          double   "Tgd"
///   ns           double   "BgdE1E5a", "BgdE1E5b"
///   -            integer  "SisaE1E5a", "SisaE1E5b", "IODNAV"
///
/// BeiDou:
///
///   Unit         Type     ParamName
///   sec          double   "Tgd1", "Tgd2", "TgdB1Cp", "TgdB2Ap"
///   -            integer  "IODE", "IODC", "AODE", "AODC"
///   -            boolean  "IscB1CdAvailable", "IscB2adAvailable"
///
/// QZSS:
///
///   Unit         Type     ParamName
///   sec          double   "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
///   sec          integer  "Fit interval"
///   -            integer  "IODE", "IODC", "UraIndex"
///   -            boolean  "IscL1CaAvailable", "IscL2CAvailable", "IscL5I5Available", "IscL5Q5Available",
///   "IscL1CPAvailable", "IscL1CDAvailable"
///
/// NavIC:
///
///   Unit         Type     ParamName
///   sec          double   "Tgd", "IscS", "IscL1P", "IscL1D"
///   -            integer  "IODEC", "UraIndex"
///   -            boolean  "IscSAvailable", "IscL1PAvailable", "IscL1DAvailable"
///
///
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR". SvId        int             The Satellite SV ID, or use 0
/// to apply new value to all satellites. ParamName   string          Parameter name (see table above for accepted
/// names). DataSetName optional string Optional name of the data set to use. If no value is provided, the active data
/// set is used.
///

class GetConstellationParameterForSV;
typedef std::shared_ptr<GetConstellationParameterForSV> GetConstellationParameterForSVPtr;

class GetConstellationParameterForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetConstellationParameterForSV";
  inline static const char* const Documentation =
    "Get \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\" constellation parameter value.\n"
    "\n"
    "General constellation parameters:\n"
    "\n"
    "  Unit         Type     ParamName\n"
    "  sec          double   \"ClockBias\"\n"
    "  sec/sec      double   \"ClockDrift\"\n"
    "  sec/sec^2    double   \"ClockDriftRate\"\n"
    "  meter        double   \"Crs\", \"Crc\", \"Accuracy\"\n"
    "  meter/sec    double   \"Adot\"\n"
    "  rad          double   \"Cis\", \"Cic\", \"Cus\", \"Cuc\", \"M0\", \"BigOmega\", \"I0\", \"LittleOmega\"\n"
    "  rad/sec      double   \"DeltaN\", \"BigOmegaDot\", \"Idot\" \n"
    "  rad/sec^2    double   \"DeltaN0dot\"\n"
    "  sqrt(meter)  double   \"SqrtA\"  \n"
    "  -            double   \"Eccentricity\"\n"
    "  -            integer  \"Week Number\", \"Toe\", \"Transmission Time\"\n"
    "\n"
    "GPS:\n"
    "\n"
    "  Unit         Type     ParamName\n"
    "  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\", \"IscL1ME\", \"IscL2ME\", \"IscL1MR\", \"IscL2MR\"\n"
    "  sec          integer  \"Fit interval\"\n"
    "  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n"
    "  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\", \"IscL1MEAvailable\", \"IscL2MEAvailable\", \"IscL1MRAvailable\", \"IscL2MRAvailable\"\n"
    "\n"
    "Galileo:\n"
    "\n"
    "  Unit         Type     ParamName\n"
    "  sec          double   \"Tgd\"\n"
    "  ns           double   \"BgdE1E5a\", \"BgdE1E5b\"\n"
    "  -            integer  \"SisaE1E5a\", \"SisaE1E5b\", \"IODNAV\" \n"
    "\n"
    "BeiDou:\n"
    "\n"
    "  Unit         Type     ParamName\n"
    "  sec          double   \"Tgd1\", \"Tgd2\", \"TgdB1Cp\", \"TgdB2Ap\"\n"
    "  -            integer  \"IODE\", \"IODC\", \"AODE\", \"AODC\"\n"
    "  -            boolean  \"IscB1CdAvailable\", \"IscB2adAvailable\"\n"
    "\n"
    "QZSS:\n"
    "\n"
    "  Unit         Type     ParamName\n"
    "  sec          double   \"Tgd\", \"IscL1Ca\", \"IscL2C\", \"IscL5I5\", \"IscL5Q5\", \"IscL1CP\", \"IscL1CD\"\n"
    "  sec          integer  \"Fit interval\"\n"
    "  -            integer  \"IODE\", \"IODC\", \"UraIndex\"\n"
    "  -            boolean  \"IscL1CaAvailable\", \"IscL2CAvailable\", \"IscL5I5Available\", \"IscL5Q5Available\", \"IscL1CPAvailable\", \"IscL1CDAvailable\"\n"
    "\n"
    "NavIC:\n"
    "\n"
    "  Unit         Type     ParamName\n"
    "  sec          double   \"Tgd\", \"IscS\", \"IscL1P\", \"IscL1D\"\n"
    "  -            integer  \"IODEC\", \"UraIndex\"\n"
    "  -            boolean  \"IscSAvailable\", \"IscL1PAvailable\", \"IscL1DAvailable\"\n"
    "\n"
    "\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"
    "SvId        int             The Satellite SV ID, or use 0 to apply new value to all satellites.\n"
    "ParamName   string          Parameter name (see table above for accepted names).\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetConstellationParameterForSV() : CommandBase(CmdName, TargetId) {}

  GetConstellationParameterForSV(const std::string& system,
                                 int svId,
                                 const std::string& paramName,
                                 const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setParamName(paramName);
    setDataSetName(dataSetName);
  }

  static GetConstellationParameterForSVPtr create(const std::string& system,
                                                  int svId,
                                                  const std::string& paramName,
                                                  const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetConstellationParameterForSV>(system, svId, paramName, dataSetName);
  }

  static GetConstellationParameterForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetConstellationParameterForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<std::string>::is_valid(m_values["ParamName"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "ParamName", "DataSetName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string paramName() const { return parse_json<std::string>::parse(m_values["ParamName"]); }

  void setParamName(const std::string& paramName)
  {
    m_values.AddMember("ParamName",
                       parse_json<std::string>::format(paramName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<std::string> dataSetName() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
  }

  void setDataSetName(const std::optional<std::string>& dataSetName)
  {
    m_values.AddMember("DataSetName",
                       parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetConstellationParameterForSV);
} // namespace Cmd
} // namespace Sdx
