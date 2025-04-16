#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set PSR ramp event. This function lets user change the pseudorange of any satellite.
/// If SV ID is set to 0, the change is applied to all satellites.
///
///           Hold Start Time
///           |         Hold Stop Time
///           |         |
///           ...........
///          ..         ...
///         ..            ...
///   .......               .........> Time
///         |               |
///         Start Time      Stop Time
///
///
/// Name          Type   Description
/// ------------- ------ ----------------------------------------------------------------------------------
/// System        string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId          int    The satellite's SV ID.
/// Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7
/// StartTime     int    Elapsed time in seconds since start of simulation.
/// HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime
/// HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime
/// StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime
/// Id            string Unique identifier automatically set by simulator if empty string.
///                      The IDs pool is common between all system.
///

class SetPseudorangeRampForSV;
typedef std::shared_ptr<SetPseudorangeRampForSV> SetPseudorangeRampForSVPtr;

class SetPseudorangeRampForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPseudorangeRampForSV";
  inline static const char* const Documentation =
    "Set PSR ramp event. This function lets user change the pseudorange of any satellite.\n"
    "If SV ID is set to 0, the change is applied to all satellites.\n"
    "\n"
    "          Hold Start Time\n"
    "          |         Hold Stop Time\n"
    "          |         |\n"
    "          ...........\n"
    "         ..         ...\n"
    "        ..            ...\n"
    "  .......               .........> Time\n"
    "        |               |\n"
    "        Start Time      Stop Time\n"
    "\n"
    "\n"
    "Name          Type   Description\n"
    "------------- ------ ----------------------------------------------------------------------------------\n"
    "System        string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId          int    The satellite's SV ID.\n"
    "Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7\n"
    "StartTime     int    Elapsed time in seconds since start of simulation.\n"
    "HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime\n"
    "HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime\n"
    "StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime\n"
    "Id            string Unique identifier automatically set by simulator if empty string.\n"
    "                     The IDs pool is common between all system.";
  inline static const char* const TargetId = "";

  SetPseudorangeRampForSV() : CommandBase(CmdName, TargetId) {}

  SetPseudorangeRampForSV(const std::string& system,
                          int svId,
                          double offset,
                          int startTime,
                          int holdStartTime,
                          int holdStopTime,
                          int stopTime,
                          const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setOffset(offset);
    setStartTime(startTime);
    setHoldStartTime(holdStartTime);
    setHoldStopTime(holdStopTime);
    setStopTime(stopTime);
    setId(id);
  }

  static SetPseudorangeRampForSVPtr create(const std::string& system,
                                           int svId,
                                           double offset,
                                           int startTime,
                                           int holdStartTime,
                                           int holdStopTime,
                                           int stopTime,
                                           const std::string& id)
  {
    return std::make_shared<SetPseudorangeRampForSV>(system,
                                                     svId,
                                                     offset,
                                                     startTime,
                                                     holdStartTime,
                                                     holdStopTime,
                                                     stopTime,
                                                     id);
  }

  static SetPseudorangeRampForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetPseudorangeRampForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<double>::is_valid(m_values["Offset"]) &&
           parse_json<int>::is_valid(m_values["StartTime"]) && parse_json<int>::is_valid(m_values["HoldStartTime"]) &&
           parse_json<int>::is_valid(m_values["HoldStopTime"]) && parse_json<int>::is_valid(m_values["StopTime"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string>
      names {"System", "SvId", "Offset", "StartTime", "HoldStartTime", "HoldStopTime", "StopTime", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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

  double offset() const { return parse_json<double>::parse(m_values["Offset"]); }

  void setOffset(double offset)
  {
    m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int startTime() const { return parse_json<int>::parse(m_values["StartTime"]); }

  void setStartTime(int startTime)
  {
    m_values.AddMember("StartTime",
                       parse_json<int>::format(startTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int holdStartTime() const { return parse_json<int>::parse(m_values["HoldStartTime"]); }

  void setHoldStartTime(int holdStartTime)
  {
    m_values.AddMember("HoldStartTime",
                       parse_json<int>::format(holdStartTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int holdStopTime() const { return parse_json<int>::parse(m_values["HoldStopTime"]); }

  void setHoldStopTime(int holdStopTime)
  {
    m_values.AddMember("HoldStopTime",
                       parse_json<int>::format(holdStopTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int stopTime() const { return parse_json<int>::parse(m_values["StopTime"]); }

  void setStopTime(int stopTime)
  {
    m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPseudorangeRampForSV);
} // namespace Cmd
} // namespace Sdx
