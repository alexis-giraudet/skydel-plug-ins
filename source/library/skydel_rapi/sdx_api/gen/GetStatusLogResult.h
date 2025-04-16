#pragma once

#include <memory>
#include <vector>

#include "command_factory.h"
#include "command_result.h"
#include "gen/LogRecord.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetStatusLog.
///
/// Name    Type            Description
/// ------- --------------- ----------------
/// Records array LogRecord The log records.
///

class GetStatusLogResult;
typedef std::shared_ptr<GetStatusLogResult> GetStatusLogResultPtr;

class GetStatusLogResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetStatusLogResult";
  inline static const char* const Documentation = "Result of GetStatusLog.\n"
                                                  "\n"
                                                  "Name    Type            Description\n"
                                                  "------- --------------- ----------------\n"
                                                  "Records array LogRecord The log records.";
  inline static const char* const TargetId = "";

  GetStatusLogResult() : CommandResult(CmdName, TargetId) {}

  GetStatusLogResult(const std::vector<Sdx::LogRecord>& records) : CommandResult(CmdName, TargetId)
  {

    setRecords(records);
  }

  GetStatusLogResult(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setRecords(records);
  }

  static GetStatusLogResultPtr create(const std::vector<Sdx::LogRecord>& records)
  {
    return std::make_shared<GetStatusLogResult>(records);
  }

  static GetStatusLogResultPtr create(CommandBasePtr relatedCommand, const std::vector<Sdx::LogRecord>& records)
  {
    return std::make_shared<GetStatusLogResult>(relatedCommand, records);
  }

  static GetStatusLogResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetStatusLogResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<Sdx::LogRecord>>::is_valid(m_values["Records"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Records"};
    return names;
  }

  std::vector<Sdx::LogRecord> records() const
  {
    return parse_json<std::vector<Sdx::LogRecord>>::parse(m_values["Records"]);
  }

  void setRecords(const std::vector<Sdx::LogRecord>& records)
  {
    m_values.AddMember("Records",
                       parse_json<std::vector<Sdx::LogRecord>>::format(records, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetStatusLogResult);
} // namespace Cmd
} // namespace Sdx
