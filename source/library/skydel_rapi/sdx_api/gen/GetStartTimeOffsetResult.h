#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetStartTimeOffset.
///
/// Name   Type Description
/// ------ ---- -----------------------------------------------------------------------------------------
/// Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver
///

class GetStartTimeOffsetResult;
typedef std::shared_ptr<GetStartTimeOffsetResult> GetStartTimeOffsetResultPtr;

class GetStartTimeOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetStartTimeOffsetResult";
  inline static const char* const Documentation =
    "Result of GetStartTimeOffset.\n"
    "\n"
    "Name   Type Description\n"
    "------ ---- -----------------------------------------------------------------------------------------\n"
    "Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver";
  inline static const char* const TargetId = "";

  GetStartTimeOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetStartTimeOffsetResult(int offset) : CommandResult(CmdName, TargetId) { setOffset(offset); }

  GetStartTimeOffsetResult(CommandBasePtr relatedCommand, int offset) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setOffset(offset);
  }

  static GetStartTimeOffsetResultPtr create(int offset) { return std::make_shared<GetStartTimeOffsetResult>(offset); }

  static GetStartTimeOffsetResultPtr create(CommandBasePtr relatedCommand, int offset)
  {
    return std::make_shared<GetStartTimeOffsetResult>(relatedCommand, offset);
  }

  static GetStartTimeOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetStartTimeOffsetResult>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Offset"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Offset"};
    return names;
  }

  int offset() const { return parse_json<int>::parse(m_values["Offset"]); }

  void setOffset(int offset)
  {
    m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetStartTimeOffsetResult);
} // namespace Cmd
} // namespace Sdx
