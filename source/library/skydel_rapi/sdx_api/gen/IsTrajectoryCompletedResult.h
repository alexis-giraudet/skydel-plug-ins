#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsTrajectoryCompleted.
///
/// Name        Type Description
/// ----------- ---- ------------------------------------------
/// IsCompleted bool Whether the trajectory is completed or not
///

class IsTrajectoryCompletedResult;
typedef std::shared_ptr<IsTrajectoryCompletedResult> IsTrajectoryCompletedResultPtr;

class IsTrajectoryCompletedResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsTrajectoryCompletedResult";
  inline static const char* const Documentation = "Result of IsTrajectoryCompleted.\n"
                                                  "\n"
                                                  "Name        Type Description\n"
                                                  "----------- ---- ------------------------------------------\n"
                                                  "IsCompleted bool Whether the trajectory is completed or not";
  inline static const char* const TargetId = "";

  IsTrajectoryCompletedResult() : CommandResult(CmdName, TargetId) {}

  IsTrajectoryCompletedResult(bool isCompleted) : CommandResult(CmdName, TargetId) { setIsCompleted(isCompleted); }

  IsTrajectoryCompletedResult(CommandBasePtr relatedCommand, bool isCompleted) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIsCompleted(isCompleted);
  }

  static IsTrajectoryCompletedResultPtr create(bool isCompleted)
  {
    return std::make_shared<IsTrajectoryCompletedResult>(isCompleted);
  }

  static IsTrajectoryCompletedResultPtr create(CommandBasePtr relatedCommand, bool isCompleted)
  {
    return std::make_shared<IsTrajectoryCompletedResult>(relatedCommand, isCompleted);
  }

  static IsTrajectoryCompletedResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsTrajectoryCompletedResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["IsCompleted"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IsCompleted"};
    return names;
  }

  bool isCompleted() const { return parse_json<bool>::parse(m_values["IsCompleted"]); }

  void setIsCompleted(bool isCompleted)
  {
    m_values.AddMember("IsCompleted",
                       parse_json<bool>::format(isCompleted, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsTrajectoryCompletedResult);
} // namespace Cmd
} // namespace Sdx
