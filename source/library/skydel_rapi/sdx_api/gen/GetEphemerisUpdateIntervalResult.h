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
/// Result of GetEphemerisUpdateInterval.
///
/// Name     Type   Description
/// -------- ------
/// -----------------------------------------------------------------------------------------------------------------------
/// System   string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds
/// in a week (604800).
///

class GetEphemerisUpdateIntervalResult;
typedef std::shared_ptr<GetEphemerisUpdateIntervalResult> GetEphemerisUpdateIntervalResultPtr;

class GetEphemerisUpdateIntervalResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetEphemerisUpdateIntervalResult";
  inline static const char* const Documentation =
    "Result of GetEphemerisUpdateInterval.\n"
    "\n"
    "Name     Type   Description\n"
    "-------- ------ -----------------------------------------------------------------------------------------------------------------------\n"
    "System   string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds in a week (604800).";
  inline static const char* const TargetId = "";

  GetEphemerisUpdateIntervalResult() : CommandResult(CmdName, TargetId) {}

  GetEphemerisUpdateIntervalResult(const std::string& system, int interval) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setInterval(interval);
  }

  GetEphemerisUpdateIntervalResult(CommandBasePtr relatedCommand, const std::string& system, int interval) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setInterval(interval);
  }

  static GetEphemerisUpdateIntervalResultPtr create(const std::string& system, int interval)
  {
    return std::make_shared<GetEphemerisUpdateIntervalResult>(system, interval);
  }

  static GetEphemerisUpdateIntervalResultPtr create(CommandBasePtr relatedCommand,
                                                    const std::string& system,
                                                    int interval)
  {
    return std::make_shared<GetEphemerisUpdateIntervalResult>(relatedCommand, system, interval);
  }

  static GetEphemerisUpdateIntervalResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEphemerisUpdateIntervalResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["Interval"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Interval"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int interval() const { return parse_json<int>::parse(m_values["Interval"]); }

  void setInterval(int interval)
  {
    m_values.AddMember("Interval", parse_json<int>::format(interval, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetEphemerisUpdateIntervalResult);
} // namespace Cmd
} // namespace Sdx
