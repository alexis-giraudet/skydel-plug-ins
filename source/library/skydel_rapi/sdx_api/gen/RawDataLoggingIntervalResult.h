#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetRawDataLoggingInterval.
///
/// Name         Type Description
/// ------------ ---- -------------------------
/// Days         int  Interval in days.
/// Hours        int  Interval in hours.
/// Minutes      int  Interval in minutes.
/// Seconds      int  Interval in seconds.
/// Milliseconds int  Interval in milliseconds.
///

class RawDataLoggingIntervalResult;
typedef std::shared_ptr<RawDataLoggingIntervalResult> RawDataLoggingIntervalResultPtr;

class RawDataLoggingIntervalResult : public CommandResult
{
public:
  inline static const char* const CmdName = "RawDataLoggingIntervalResult";
  inline static const char* const Documentation = "Result of GetRawDataLoggingInterval.\n"
                                                  "\n"
                                                  "Name         Type Description\n"
                                                  "------------ ---- -------------------------\n"
                                                  "Days         int  Interval in days.\n"
                                                  "Hours        int  Interval in hours.\n"
                                                  "Minutes      int  Interval in minutes.\n"
                                                  "Seconds      int  Interval in seconds.\n"
                                                  "Milliseconds int  Interval in milliseconds.";
  inline static const char* const TargetId = "";

  RawDataLoggingIntervalResult() : CommandResult(CmdName, TargetId) {}

  RawDataLoggingIntervalResult(int days, int hours, int minutes, int seconds, int milliseconds) :
    CommandResult(CmdName, TargetId)
  {

    setDays(days);
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
    setMilliseconds(milliseconds);
  }

  RawDataLoggingIntervalResult(CommandBasePtr relatedCommand,
                               int days,
                               int hours,
                               int minutes,
                               int seconds,
                               int milliseconds) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setDays(days);
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
    setMilliseconds(milliseconds);
  }

  static RawDataLoggingIntervalResultPtr create(int days, int hours, int minutes, int seconds, int milliseconds)
  {
    return std::make_shared<RawDataLoggingIntervalResult>(days, hours, minutes, seconds, milliseconds);
  }

  static RawDataLoggingIntervalResultPtr create(CommandBasePtr relatedCommand,
                                                int days,
                                                int hours,
                                                int minutes,
                                                int seconds,
                                                int milliseconds)
  {
    return std::make_shared<RawDataLoggingIntervalResult>(relatedCommand, days, hours, minutes, seconds, milliseconds);
  }

  static RawDataLoggingIntervalResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RawDataLoggingIntervalResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Days"]) &&
           parse_json<int>::is_valid(m_values["Hours"]) && parse_json<int>::is_valid(m_values["Minutes"]) &&
           parse_json<int>::is_valid(m_values["Seconds"]) && parse_json<int>::is_valid(m_values["Milliseconds"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Days", "Hours", "Minutes", "Seconds", "Milliseconds"};
    return names;
  }

  int days() const { return parse_json<int>::parse(m_values["Days"]); }

  void setDays(int days)
  {
    m_values.AddMember("Days", parse_json<int>::format(days, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int hours() const { return parse_json<int>::parse(m_values["Hours"]); }

  void setHours(int hours)
  {
    m_values.AddMember("Hours", parse_json<int>::format(hours, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int minutes() const { return parse_json<int>::parse(m_values["Minutes"]); }

  void setMinutes(int minutes)
  {
    m_values.AddMember("Minutes", parse_json<int>::format(minutes, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int seconds() const { return parse_json<int>::parse(m_values["Seconds"]); }

  void setSeconds(int seconds)
  {
    m_values.AddMember("Seconds", parse_json<int>::format(seconds, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int milliseconds() const { return parse_json<int>::parse(m_values["Milliseconds"]); }

  void setMilliseconds(int milliseconds)
  {
    m_values.AddMember("Milliseconds",
                       parse_json<int>::format(milliseconds, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RawDataLoggingIntervalResult);
} // namespace Cmd
} // namespace Sdx
