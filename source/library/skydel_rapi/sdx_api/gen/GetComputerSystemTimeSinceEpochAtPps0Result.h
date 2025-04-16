#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetComputerSystemTimeSinceEpochAtPps0.
///
/// Name         Type   Description
/// ------------ ------ ---------------------------------------------------------
/// Milliseconds double Computer system time since epoch at PPS0 in milliseconds.
///

class GetComputerSystemTimeSinceEpochAtPps0Result;
typedef std::shared_ptr<GetComputerSystemTimeSinceEpochAtPps0Result> GetComputerSystemTimeSinceEpochAtPps0ResultPtr;

class GetComputerSystemTimeSinceEpochAtPps0Result : public CommandResult
{
public:
  inline static const char* const CmdName = "GetComputerSystemTimeSinceEpochAtPps0Result";
  inline static const char* const Documentation =
    "Result of GetComputerSystemTimeSinceEpochAtPps0.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ ---------------------------------------------------------\n"
    "Milliseconds double Computer system time since epoch at PPS0 in milliseconds.";
  inline static const char* const TargetId = "";

  GetComputerSystemTimeSinceEpochAtPps0Result() : CommandResult(CmdName, TargetId) {}

  GetComputerSystemTimeSinceEpochAtPps0Result(double milliseconds) : CommandResult(CmdName, TargetId)
  {

    setMilliseconds(milliseconds);
  }

  GetComputerSystemTimeSinceEpochAtPps0Result(CommandBasePtr relatedCommand, double milliseconds) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setMilliseconds(milliseconds);
  }

  static GetComputerSystemTimeSinceEpochAtPps0ResultPtr create(double milliseconds)
  {
    return std::make_shared<GetComputerSystemTimeSinceEpochAtPps0Result>(milliseconds);
  }

  static GetComputerSystemTimeSinceEpochAtPps0ResultPtr create(CommandBasePtr relatedCommand, double milliseconds)
  {
    return std::make_shared<GetComputerSystemTimeSinceEpochAtPps0Result>(relatedCommand, milliseconds);
  }

  static GetComputerSystemTimeSinceEpochAtPps0ResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetComputerSystemTimeSinceEpochAtPps0Result>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Milliseconds"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Milliseconds"};
    return names;
  }

  double milliseconds() const { return parse_json<double>::parse(m_values["Milliseconds"]); }

  void setMilliseconds(double milliseconds)
  {
    m_values.AddMember("Milliseconds",
                       parse_json<double>::format(milliseconds, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetComputerSystemTimeSinceEpochAtPps0Result);
} // namespace Cmd
} // namespace Sdx
