#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetGpsStartTime.
///
/// Name       Type     Description
/// ---------- -------- ------------------------------------------------------------------------------------------------
/// StartTime  datetime GPS date and time when the simulation started (it is the GPS time expressed in Gregorian format)
/// LeapSecond int      The number of leap seconds to convert GPS date and time into UTC
///

class GetGpsStartTimeResult;
typedef std::shared_ptr<GetGpsStartTimeResult> GetGpsStartTimeResultPtr;

class GetGpsStartTimeResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetGpsStartTimeResult";
  inline static const char* const Documentation =
    "Result of GetGpsStartTime.\n"
    "\n"
    "Name       Type     Description\n"
    "---------- -------- ------------------------------------------------------------------------------------------------\n"
    "StartTime  datetime GPS date and time when the simulation started (it is the GPS time expressed in Gregorian format)\n"
    "LeapSecond int      The number of leap seconds to convert GPS date and time into UTC";
  inline static const char* const TargetId = "";

  GetGpsStartTimeResult() : CommandResult(CmdName, TargetId) {}

  GetGpsStartTimeResult(const Sdx::DateTime& startTime, int leapSecond) : CommandResult(CmdName, TargetId)
  {

    setStartTime(startTime);
    setLeapSecond(leapSecond);
  }

  GetGpsStartTimeResult(CommandBasePtr relatedCommand, const Sdx::DateTime& startTime, int leapSecond) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setStartTime(startTime);
    setLeapSecond(leapSecond);
  }

  static GetGpsStartTimeResultPtr create(const Sdx::DateTime& startTime, int leapSecond)
  {
    return std::make_shared<GetGpsStartTimeResult>(startTime, leapSecond);
  }

  static GetGpsStartTimeResultPtr create(CommandBasePtr relatedCommand, const Sdx::DateTime& startTime, int leapSecond)
  {
    return std::make_shared<GetGpsStartTimeResult>(relatedCommand, startTime, leapSecond);
  }

  static GetGpsStartTimeResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGpsStartTimeResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::DateTime>::is_valid(m_values["StartTime"]) &&
           parse_json<int>::is_valid(m_values["LeapSecond"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"StartTime", "LeapSecond"};
    return names;
  }

  Sdx::DateTime startTime() const { return parse_json<Sdx::DateTime>::parse(m_values["StartTime"]); }

  void setStartTime(const Sdx::DateTime& startTime)
  {
    m_values.AddMember("StartTime",
                       parse_json<Sdx::DateTime>::format(startTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int leapSecond() const { return parse_json<int>::parse(m_values["LeapSecond"]); }

  void setLeapSecond(int leapSecond)
  {
    m_values.AddMember("LeapSecond",
                       parse_json<int>::format(leapSecond, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGpsStartTimeResult);
} // namespace Cmd
} // namespace Sdx
