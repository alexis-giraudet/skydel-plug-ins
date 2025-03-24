#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsStopMasterWhenSlaveStop.
///
/// Name    Type Description
/// ------- ---- ---------------------------------------
/// Enabled bool Enable master stop when slave fail flag
///

class IsStopMasterWhenSlaveStopResult;
typedef std::shared_ptr<IsStopMasterWhenSlaveStopResult> IsStopMasterWhenSlaveStopResultPtr;

class IsStopMasterWhenSlaveStopResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsStopMasterWhenSlaveStopResult";
  inline static const char* const Documentation = "Result of IsStopMasterWhenSlaveStop.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- ---------------------------------------\n"
                                                  "Enabled bool Enable master stop when slave fail flag";
  inline static const char* const TargetId = "";

  IsStopMasterWhenSlaveStopResult() : CommandResult(CmdName, TargetId) {}

  IsStopMasterWhenSlaveStopResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsStopMasterWhenSlaveStopResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsStopMasterWhenSlaveStopResultPtr create(bool enabled)
  {
    return std::make_shared<IsStopMasterWhenSlaveStopResult>(enabled);
  }

  static IsStopMasterWhenSlaveStopResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsStopMasterWhenSlaveStopResult>(relatedCommand, enabled);
  }

  static IsStopMasterWhenSlaveStopResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsStopMasterWhenSlaveStopResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled"};
    return names;
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsStopMasterWhenSlaveStopResult);
} // namespace Cmd
} // namespace Sdx
