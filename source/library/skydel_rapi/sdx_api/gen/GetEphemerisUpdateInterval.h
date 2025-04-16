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
/// Get the ephemeris update interval in seconds.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------
/// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
///

class GetEphemerisUpdateInterval;
typedef std::shared_ptr<GetEphemerisUpdateInterval> GetEphemerisUpdateIntervalPtr;

class GetEphemerisUpdateInterval : public CommandBase
{
public:
  inline static const char* const CmdName = "GetEphemerisUpdateInterval";
  inline static const char* const Documentation =
    "Get the ephemeris update interval in seconds.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------\n"
    "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  GetEphemerisUpdateInterval() : CommandBase(CmdName, TargetId) {}

  GetEphemerisUpdateInterval(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static GetEphemerisUpdateIntervalPtr create(const std::string& system)
  {
    return std::make_shared<GetEphemerisUpdateInterval>(system);
  }

  static GetEphemerisUpdateIntervalPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEphemerisUpdateInterval>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System"};
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
};
REGISTER_COMMAND_TO_FACTORY(GetEphemerisUpdateInterval);
} // namespace Cmd
} // namespace Sdx
