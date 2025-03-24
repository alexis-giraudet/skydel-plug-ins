#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command SetEphemerisReferenceTime is deprecated since 21.3. You may use
/// SetEphemerisReferenceTimeForSV.
///
/// Set the ephemeris reference time for the specified constellation.
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- System      string
/// "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR" SvId        int             The satellite's SV ID. Time
/// datetime        GPS date and time (it is the GPS time expressed in UTC format) DataSetName optional string Optional
/// name of the data set to use. If no value is provided, the active data set is used.
///

class SetEphemerisReferenceTime;
typedef std::shared_ptr<SetEphemerisReferenceTime> SetEphemerisReferenceTimePtr;

class SetEphemerisReferenceTime : public CommandBase
{
public:
  inline static const char* const CmdName = "SetEphemerisReferenceTime";
  inline static const char* const Documentation =
    "Please note the command SetEphemerisReferenceTime is deprecated since 21.3. You may use SetEphemerisReferenceTimeForSV.\n"
    "\n"
    "Set the ephemeris reference time for the specified constellation.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId        int             The satellite's SV ID.\n"
    "Time        datetime        GPS date and time (it is the GPS time expressed in UTC format)\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  SetEphemerisReferenceTime() : CommandBase(CmdName, TargetId) {}

  SetEphemerisReferenceTime(const std::string& system,
                            int svId,
                            const Sdx::DateTime& time,
                            const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setTime(time);
    setDataSetName(dataSetName);
  }

  static SetEphemerisReferenceTimePtr create(const std::string& system,
                                             int svId,
                                             const Sdx::DateTime& time,
                                             const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<SetEphemerisReferenceTime>(system, svId, time, dataSetName);
  }

  static SetEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetEphemerisReferenceTime>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetEphemerisReferenceTime);
} // namespace Cmd
} // namespace Sdx
