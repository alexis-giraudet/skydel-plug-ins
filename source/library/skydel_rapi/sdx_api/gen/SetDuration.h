#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the simulation duration. The simulation will stop automatically when this duration is reached
///
/// Name   Type Description
/// ------ ---- -----------------------
/// Second int  The duration in seconds
///

class SetDuration;
typedef std::shared_ptr<SetDuration> SetDurationPtr;

class SetDuration : public CommandBase
{
public:
  inline static const char* const CmdName = "SetDuration";
  inline static const char* const Documentation =
    "Set the simulation duration. The simulation will stop automatically when this duration is reached\n"
    "\n"
    "Name   Type Description\n"
    "------ ---- -----------------------\n"
    "Second int  The duration in seconds";
  inline static const char* const TargetId = "";

  SetDuration() : CommandBase(CmdName, TargetId) {}

  SetDuration(int second) : CommandBase(CmdName, TargetId) { setSecond(second); }

  static SetDurationPtr create(int second) { return std::make_shared<SetDuration>(second); }

  static SetDurationPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetDuration>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Second"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Second"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int second() const { return parse_json<int>::parse(m_values["Second"]); }

  void setSecond(int second)
  {
    m_values.AddMember("Second", parse_json<int>::format(second, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetDuration);
} // namespace Cmd
} // namespace Sdx
