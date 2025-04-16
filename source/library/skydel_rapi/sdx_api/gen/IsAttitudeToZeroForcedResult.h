#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsAttitudeToZeroForced.
///
/// Name    Type Description
/// ------- ---- -----------------------------------------------
/// Enabled bool If true, vehicle won't rotate during simulation
///

class IsAttitudeToZeroForcedResult;
typedef std::shared_ptr<IsAttitudeToZeroForcedResult> IsAttitudeToZeroForcedResultPtr;

class IsAttitudeToZeroForcedResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsAttitudeToZeroForcedResult";
  inline static const char* const Documentation = "Result of IsAttitudeToZeroForced.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- -----------------------------------------------\n"
                                                  "Enabled bool If true, vehicle won't rotate during simulation";
  inline static const char* const TargetId = "";

  IsAttitudeToZeroForcedResult() : CommandResult(CmdName, TargetId) {}

  IsAttitudeToZeroForcedResult(bool enabled) : CommandResult(CmdName, TargetId) { setEnabled(enabled); }

  IsAttitudeToZeroForcedResult(CommandBasePtr relatedCommand, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
  }

  static IsAttitudeToZeroForcedResultPtr create(bool enabled)
  {
    return std::make_shared<IsAttitudeToZeroForcedResult>(enabled);
  }

  static IsAttitudeToZeroForcedResultPtr create(CommandBasePtr relatedCommand, bool enabled)
  {
    return std::make_shared<IsAttitudeToZeroForcedResult>(relatedCommand, enabled);
  }

  static IsAttitudeToZeroForcedResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsAttitudeToZeroForcedResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsAttitudeToZeroForcedResult);
} // namespace Cmd
} // namespace Sdx
