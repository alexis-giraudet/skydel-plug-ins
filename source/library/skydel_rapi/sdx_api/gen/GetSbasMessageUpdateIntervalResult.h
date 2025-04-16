#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSbasMessageUpdateInterval.
///
/// Name           Type Description
/// -------------- ---- -----------------------------------------------------------------------------------------------
/// Message        int  The message type.
/// UpdateInterval int  The message update interval in seconds. Accepted range is [6..300] and must be a multiple of 6.
///

class GetSbasMessageUpdateIntervalResult;
typedef std::shared_ptr<GetSbasMessageUpdateIntervalResult> GetSbasMessageUpdateIntervalResultPtr;

class GetSbasMessageUpdateIntervalResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSbasMessageUpdateIntervalResult";
  inline static const char* const Documentation =
    "Result of GetSbasMessageUpdateInterval.\n"
    "\n"
    "Name           Type Description\n"
    "-------------- ---- -----------------------------------------------------------------------------------------------\n"
    "Message        int  The message type.\n"
    "UpdateInterval int  The message update interval in seconds. Accepted range is [6..300] and must be a multiple of 6.";
  inline static const char* const TargetId = "";

  GetSbasMessageUpdateIntervalResult() : CommandResult(CmdName, TargetId) {}

  GetSbasMessageUpdateIntervalResult(int message, int updateInterval) : CommandResult(CmdName, TargetId)
  {

    setMessage(message);
    setUpdateInterval(updateInterval);
  }

  GetSbasMessageUpdateIntervalResult(CommandBasePtr relatedCommand, int message, int updateInterval) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setMessage(message);
    setUpdateInterval(updateInterval);
  }

  static GetSbasMessageUpdateIntervalResultPtr create(int message, int updateInterval)
  {
    return std::make_shared<GetSbasMessageUpdateIntervalResult>(message, updateInterval);
  }

  static GetSbasMessageUpdateIntervalResultPtr create(CommandBasePtr relatedCommand, int message, int updateInterval)
  {
    return std::make_shared<GetSbasMessageUpdateIntervalResult>(relatedCommand, message, updateInterval);
  }

  static GetSbasMessageUpdateIntervalResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasMessageUpdateIntervalResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSbasMessageUpdateIntervalResult);
} // namespace Cmd
} // namespace Sdx
