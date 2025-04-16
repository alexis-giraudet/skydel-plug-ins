#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetDynamicRangeOffset.
///
/// Name   Type   Description
/// ------ ------ ----------------------------------------------------------------
/// Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.
///

class GetDynamicRangeOffsetResult;
typedef std::shared_ptr<GetDynamicRangeOffsetResult> GetDynamicRangeOffsetResultPtr;

class GetDynamicRangeOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetDynamicRangeOffsetResult";
  inline static const char* const Documentation =
    "Result of GetDynamicRangeOffset.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ----------------------------------------------------------------\n"
    "Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.";
  inline static const char* const TargetId = "";

  GetDynamicRangeOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetDynamicRangeOffsetResult(double offset) : CommandResult(CmdName, TargetId) { setOffset(offset); }

  GetDynamicRangeOffsetResult(CommandBasePtr relatedCommand, double offset) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setOffset(offset);
  }

  static GetDynamicRangeOffsetResultPtr create(double offset)
  {
    return std::make_shared<GetDynamicRangeOffsetResult>(offset);
  }

  static GetDynamicRangeOffsetResultPtr create(CommandBasePtr relatedCommand, double offset)
  {
    return std::make_shared<GetDynamicRangeOffsetResult>(relatedCommand, offset);
  }

  static GetDynamicRangeOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetDynamicRangeOffsetResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Offset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Offset"};
    return names;
  }

  double offset() const { return parse_json<double>::parse(m_values["Offset"]); }

  void setOffset(double offset)
  {
    m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetDynamicRangeOffsetResult);
} // namespace Cmd
} // namespace Sdx
