#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetOfficialLeapSecond
///
/// Name       Type Description
/// ---------- ---- -----------------
/// LeapSecond int  Leap second value
///

class GetOfficialLeapSecondResult;
typedef std::shared_ptr<GetOfficialLeapSecondResult> GetOfficialLeapSecondResultPtr;

class GetOfficialLeapSecondResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetOfficialLeapSecondResult";
  inline static const char* const Documentation = "Result of GetOfficialLeapSecond\n"
                                                  "\n"
                                                  "Name       Type Description\n"
                                                  "---------- ---- -----------------\n"
                                                  "LeapSecond int  Leap second value";
  inline static const char* const TargetId = "";

  GetOfficialLeapSecondResult() : CommandResult(CmdName, TargetId) {}

  GetOfficialLeapSecondResult(int leapSecond) : CommandResult(CmdName, TargetId) { setLeapSecond(leapSecond); }

  GetOfficialLeapSecondResult(CommandBasePtr relatedCommand, int leapSecond) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setLeapSecond(leapSecond);
  }

  static GetOfficialLeapSecondResultPtr create(int leapSecond)
  {
    return std::make_shared<GetOfficialLeapSecondResult>(leapSecond);
  }

  static GetOfficialLeapSecondResultPtr create(CommandBasePtr relatedCommand, int leapSecond)
  {
    return std::make_shared<GetOfficialLeapSecondResult>(relatedCommand, leapSecond);
  }

  static GetOfficialLeapSecondResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetOfficialLeapSecondResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["LeapSecond"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"LeapSecond"};
    return names;
  }

  int leapSecond() const { return parse_json<int>::parse(m_values["LeapSecond"]); }

  void setLeapSecond(int leapSecond)
  {
    m_values.AddMember("LeapSecond",
                       parse_json<int>::format(leapSecond, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetOfficialLeapSecondResult);
} // namespace Cmd
} // namespace Sdx
