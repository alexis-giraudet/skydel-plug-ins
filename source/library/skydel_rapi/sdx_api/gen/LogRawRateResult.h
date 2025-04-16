#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetLogRawRate.
///
/// Name Type Description
/// ---- ---- --------------------------------------
/// Rate int  Accepted rates are 10, 100 and 1000 Hz
///

class LogRawRateResult;
typedef std::shared_ptr<LogRawRateResult> LogRawRateResultPtr;

class LogRawRateResult : public CommandResult
{
public:
  inline static const char* const CmdName = "LogRawRateResult";
  inline static const char* const Documentation = "Result of GetLogRawRate.\n"
                                                  "\n"
                                                  "Name Type Description\n"
                                                  "---- ---- --------------------------------------\n"
                                                  "Rate int  Accepted rates are 10, 100 and 1000 Hz";
  inline static const char* const TargetId = "";

  LogRawRateResult() : CommandResult(CmdName, TargetId) {}

  LogRawRateResult(int rate) : CommandResult(CmdName, TargetId) { setRate(rate); }

  LogRawRateResult(CommandBasePtr relatedCommand, int rate) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setRate(rate);
  }

  static LogRawRateResultPtr create(int rate) { return std::make_shared<LogRawRateResult>(rate); }

  static LogRawRateResultPtr create(CommandBasePtr relatedCommand, int rate)
  {
    return std::make_shared<LogRawRateResult>(relatedCommand, rate);
  }

  static LogRawRateResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<LogRawRateResult>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Rate"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Rate"};
    return names;
  }

  int rate() const { return parse_json<int>::parse(m_values["Rate"]); }

  void setRate(int rate)
  {
    m_values.AddMember("Rate", parse_json<int>::format(rate, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(LogRawRateResult);
} // namespace Cmd
} // namespace Sdx
