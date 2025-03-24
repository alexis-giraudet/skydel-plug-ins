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
/// Set the ephemeris update interval in seconds.
///
/// Name     Type   Description
/// -------- ------
/// -----------------------------------------------------------------------------------------------------------------------
/// System   string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds
/// in a week (604800).
///

class SetEphemerisUpdateInterval;
typedef std::shared_ptr<SetEphemerisUpdateInterval> SetEphemerisUpdateIntervalPtr;

class SetEphemerisUpdateInterval : public CommandBase
{
public:
  inline static const char* const CmdName = "SetEphemerisUpdateInterval";
  inline static const char* const Documentation =
    "Set the ephemeris update interval in seconds.\n"
    "\n"
    "Name     Type   Description\n"
    "-------- ------ -----------------------------------------------------------------------------------------------------------------------\n"
    "System   string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Interval int    Interval duration in sec. Accepted range is [1..604800]. Must be a divider of the number of seconds in a week (604800).";
  inline static const char* const TargetId = "";

  SetEphemerisUpdateInterval() : CommandBase(CmdName, TargetId) {}

  SetEphemerisUpdateInterval(const std::string& system, int interval) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setInterval(interval);
  }

  static SetEphemerisUpdateIntervalPtr create(const std::string& system, int interval)
  {
    return std::make_shared<SetEphemerisUpdateInterval>(system, interval);
  }

  static SetEphemerisUpdateIntervalPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetEphemerisUpdateInterval>(ptr);
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

  int executePermission() const { return EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(SetEphemerisUpdateInterval);
} // namespace Cmd
} // namespace Sdx
