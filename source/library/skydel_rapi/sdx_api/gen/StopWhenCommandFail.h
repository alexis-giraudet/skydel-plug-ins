#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// If enabled, simulation stops when a command result fail.
///
/// Name    Type Description
/// ------- ---- ----------------------------------
/// Enabled bool Enable stop when command fail flag
///

class StopWhenCommandFail;
typedef std::shared_ptr<StopWhenCommandFail> StopWhenCommandFailPtr;

class StopWhenCommandFail : public CommandBase
{
public:
  inline static const char* const CmdName = "StopWhenCommandFail";
  inline static const char* const Documentation = "If enabled, simulation stops when a command result fail.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- ----------------------------------\n"
                                                  "Enabled bool Enable stop when command fail flag";
  inline static const char* const TargetId = "";

  StopWhenCommandFail() : CommandBase(CmdName, TargetId) {}

  StopWhenCommandFail(bool enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static StopWhenCommandFailPtr create(bool enabled) { return std::make_shared<StopWhenCommandFail>(enabled); }

  static StopWhenCommandFailPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<StopWhenCommandFail>(ptr);
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

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(StopWhenCommandFail);
} // namespace Cmd
} // namespace Sdx
