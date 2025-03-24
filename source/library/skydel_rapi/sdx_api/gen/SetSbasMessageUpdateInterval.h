#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the SBAS message update interval.
///
/// Name           Type Description
/// -------------- ---- -----------------------------------------------------------------------------------------------
/// Message        int  The message type.
/// UpdateInterval int  The message update interval in seconds. Accepted range is [6..300] and must be a multiple of 6.
///

class SetSbasMessageUpdateInterval;
typedef std::shared_ptr<SetSbasMessageUpdateInterval> SetSbasMessageUpdateIntervalPtr;

class SetSbasMessageUpdateInterval : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSbasMessageUpdateInterval";
  inline static const char* const Documentation =
    "Set the SBAS message update interval.\n"
    "\n"
    "Name           Type Description\n"
    "-------------- ---- -----------------------------------------------------------------------------------------------\n"
    "Message        int  The message type.\n"
    "UpdateInterval int  The message update interval in seconds. Accepted range is [6..300] and must be a multiple of 6.";
  inline static const char* const TargetId = "";

  SetSbasMessageUpdateInterval() : CommandBase(CmdName, TargetId) {}

  SetSbasMessageUpdateInterval(int message, int updateInterval) : CommandBase(CmdName, TargetId)
  {

    setMessage(message);
    setUpdateInterval(updateInterval);
  }

  static SetSbasMessageUpdateIntervalPtr create(int message, int updateInterval)
  {
    return std::make_shared<SetSbasMessageUpdateInterval>(message, updateInterval);
  }

  static SetSbasMessageUpdateIntervalPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSbasMessageUpdateInterval>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Message"]) &&
           parse_json<int>::is_valid(m_values["UpdateInterval"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Message", "UpdateInterval"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  int message() const { return parse_json<int>::parse(m_values["Message"]); }

  void setMessage(int message)
  {
    m_values.AddMember("Message", parse_json<int>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int updateInterval() const { return parse_json<int>::parse(m_values["UpdateInterval"]); }

  void setUpdateInterval(int updateInterval)
  {
    m_values.AddMember("UpdateInterval",
                       parse_json<int>::format(updateInterval, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSbasMessageUpdateInterval);
} // namespace Cmd
} // namespace Sdx
