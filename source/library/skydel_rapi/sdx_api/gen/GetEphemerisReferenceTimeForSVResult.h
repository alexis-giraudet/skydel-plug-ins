#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetEphemerisReferenceTimeForSV.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" SvId        int             The satellite's SV ID. Time
/// datetime        GPS date and time (it is the GPS time expressed in UTC format) DataSetName optional string Optional
/// name of the data set to use. If no value is provided, the active data set is used.
///

class GetEphemerisReferenceTimeForSVResult;
typedef std::shared_ptr<GetEphemerisReferenceTimeForSVResult> GetEphemerisReferenceTimeForSVResultPtr;
typedef GetEphemerisReferenceTimeForSVResult GetEphemerisReferenceTimeResult;
typedef std::shared_ptr<GetEphemerisReferenceTimeResult> GetEphemerisReferenceTimeResultPtr;

class GetEphemerisReferenceTimeForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetEphemerisReferenceTimeForSVResult";
  inline static const char* const Documentation =
    "Result of GetEphemerisReferenceTimeForSV.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId        int             The satellite's SV ID.\n"
    "Time        datetime        GPS date and time (it is the GPS time expressed in UTC format)\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetEphemerisReferenceTimeForSVResult() : CommandResult(CmdName, TargetId) {}

  GetEphemerisReferenceTimeForSVResult(const std::string& system,
                                       int svId,
                                       const Sdx::DateTime& time,
                                       const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setTime(time);
    setDataSetName(dataSetName);
  }

  GetEphemerisReferenceTimeForSVResult(CommandBasePtr relatedCommand,
                                       const std::string& system,
                                       int svId,
                                       const Sdx::DateTime& time,
                                       const std::optional<std::string>& dataSetName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setTime(time);
    setDataSetName(dataSetName);
  }

  static GetEphemerisReferenceTimeForSVResultPtr create(const std::string& system,
                                                        int svId,
                                                        const Sdx::DateTime& time,
                                                        const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetEphemerisReferenceTimeForSVResult>(system, svId, time, dataSetName);
  }

  static GetEphemerisReferenceTimeForSVResultPtr create(CommandBasePtr relatedCommand,
                                                        const std::string& system,
                                                        int svId,
                                                        const Sdx::DateTime& time,
                                                        const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetEphemerisReferenceTimeForSVResult>(relatedCommand, system, svId, time, dataSetName);
  }

  static GetEphemerisReferenceTimeForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEphemerisReferenceTimeForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<Sdx::DateTime>::is_valid(m_values["Time"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "Time", "DataSetName"};
    return names;
  }

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

  Sdx::DateTime time() const { return parse_json<Sdx::DateTime>::parse(m_values["Time"]); }

  void setTime(const Sdx::DateTime& time)
  {
    m_values.AddMember("Time",
                       parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(GetEphemerisReferenceTimeForSVResult);
} // namespace Cmd
} // namespace Sdx
