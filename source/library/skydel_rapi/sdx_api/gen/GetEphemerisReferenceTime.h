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
/// Please note the command GetEphemerisReferenceTime is deprecated since 21.3. You may use
/// GetEphemerisReferenceTimeForSV.
///
/// Get the ephemeris reference time for the specified constellation.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" SvId        int             The satellite's SV ID.
/// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is
/// used.
///

class GetEphemerisReferenceTime;
typedef std::shared_ptr<GetEphemerisReferenceTime> GetEphemerisReferenceTimePtr;

class GetEphemerisReferenceTime : public CommandBase
{
public:
  inline static const char* const CmdName = "GetEphemerisReferenceTime";
  inline static const char* const Documentation =
    "Please note the command GetEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.\n"
    "\n"
    "Get the ephemeris reference time for the specified constellation.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId        int             The satellite's SV ID.\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetEphemerisReferenceTime() : CommandBase(CmdName, TargetId) {}

  GetEphemerisReferenceTime(const std::string& system, int svId, const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setDataSetName(dataSetName);
  }

  static GetEphemerisReferenceTimePtr create(const std::string& system,
                                             int svId,
                                             const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetEphemerisReferenceTime>(system, svId, dataSetName);
  }

  static GetEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEphemerisReferenceTime>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "DataSetName"};
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
REGISTER_COMMAND_TO_FACTORY(GetEphemerisReferenceTime);
} // namespace Cmd
} // namespace Sdx
