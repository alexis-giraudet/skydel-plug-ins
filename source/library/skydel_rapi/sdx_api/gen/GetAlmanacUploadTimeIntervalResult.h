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
/// Result of GetAlmanacUploadTimeInterval.
///
/// Name     Type   Description
/// -------- ------ ----------------------------------------------------------
/// System   string Must be "GPS"
/// Interval int    Interval duration in sec. Accepted range is [3600..259200]
///

class GetAlmanacUploadTimeIntervalResult;
typedef std::shared_ptr<GetAlmanacUploadTimeIntervalResult> GetAlmanacUploadTimeIntervalResultPtr;

class GetAlmanacUploadTimeIntervalResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAlmanacUploadTimeIntervalResult";
  inline static const char* const Documentation =
    "Result of GetAlmanacUploadTimeInterval.\n"
    "\n"
    "Name     Type   Description\n"
    "-------- ------ ----------------------------------------------------------\n"
    "System   string Must be \"GPS\"\n"
    "Interval int    Interval duration in sec. Accepted range is [3600..259200]";
  inline static const char* const TargetId = "";

  GetAlmanacUploadTimeIntervalResult() : CommandResult(CmdName, TargetId) {}

  GetAlmanacUploadTimeIntervalResult(const std::string& system, int interval) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setInterval(interval);
  }

  GetAlmanacUploadTimeIntervalResult(CommandBasePtr relatedCommand, const std::string& system, int interval) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setInterval(interval);
  }

  static GetAlmanacUploadTimeIntervalResultPtr create(const std::string& system, int interval)
  {
    return std::make_shared<GetAlmanacUploadTimeIntervalResult>(system, interval);
  }

  static GetAlmanacUploadTimeIntervalResultPtr create(CommandBasePtr relatedCommand,
                                                      const std::string& system,
                                                      int interval)
  {
    return std::make_shared<GetAlmanacUploadTimeIntervalResult>(relatedCommand, system, interval);
  }

  static GetAlmanacUploadTimeIntervalResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAlmanacUploadTimeIntervalResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAlmanacUploadTimeIntervalResult);
} // namespace Cmd
} // namespace Sdx
