#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetPseudorangeRampForSV.
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

class GetPseudorangeRampForSVResult;
typedef std::shared_ptr<GetPseudorangeRampForSVResult> GetPseudorangeRampForSVResultPtr;

class GetPseudorangeRampForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetPseudorangeRampForSVResult";
  inline static const char* const Documentation =
    "Result of GetPseudorangeRampForSV.\n"
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

  GetPseudorangeRampForSVResult() : CommandResult(CmdName, TargetId) {}

  GetPseudorangeRampForSVResult(const std::string& system,
                                int svId,
                                double offset,
                                int startTime,
                                int holdStartTime,
                                int holdStopTime,
                                int stopTime,
                                const std::string& id) :
    CommandResult(CmdName, TargetId)
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

  GetPseudorangeRampForSVResult(CommandBasePtr relatedCommand,
                                const std::string& system,
                                int svId,
                                double offset,
                                int startTime,
                                int holdStartTime,
                                int holdStopTime,
                                int stopTime,
                                const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
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

  static GetPseudorangeRampForSVResultPtr create(const std::string& system,
                                                 int svId,
                                                 double offset,
                                                 int startTime,
                                                 int holdStartTime,
                                                 int holdStopTime,
                                                 int stopTime,
                                                 const std::string& id)
  {
    return std::make_shared<GetPseudorangeRampForSVResult>(system,
                                                           svId,
                                                           offset,
                                                           startTime,
                                                           holdStartTime,
                                                           holdStopTime,
                                                           stopTime,
                                                           id);
  }

  static GetPseudorangeRampForSVResultPtr create(CommandBasePtr relatedCommand,
                                                 const std::string& system,
                                                 int svId,
                                                 double offset,
                                                 int startTime,
                                                 int holdStartTime,
                                                 int holdStopTime,
                                                 int stopTime,
                                                 const std::string& id)
  {
    return std::make_shared<GetPseudorangeRampForSVResult>(relatedCommand,
                                                           system,
                                                           svId,
                                                           offset,
                                                           startTime,
                                                           holdStartTime,
                                                           holdStopTime,
                                                           stopTime,
                                                           id);
  }

  static GetPseudorangeRampForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPseudorangeRampForSVResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetPseudorangeRampForSVResult);
} // namespace Cmd
} // namespace Sdx
