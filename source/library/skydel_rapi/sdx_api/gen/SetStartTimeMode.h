#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the simulation start time mode.
///
/// Name Type   Description
/// ---- ------ ---------------------------------------------------
/// Mode string Accepted Modes ("Custom", "Computer", "GPS", "NTP")
///

class SetStartTimeMode;
typedef std::shared_ptr<SetStartTimeMode> SetStartTimeModePtr;

class SetStartTimeMode : public CommandBase
{
public:
  inline static const char* const CmdName = "SetStartTimeMode";
  inline static const char* const Documentation =
    "Set the simulation start time mode.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ---------------------------------------------------\n"
    "Mode string Accepted Modes (\"Custom\", \"Computer\", \"GPS\", \"NTP\")";
  inline static const char* const TargetId = "";

  SetStartTimeMode() : CommandBase(CmdName, TargetId) {}

  SetStartTimeMode(const std::string& mode) : CommandBase(CmdName, TargetId) { setMode(mode); }

  static SetStartTimeModePtr create(const std::string& mode) { return std::make_shared<SetStartTimeMode>(mode); }

  static SetStartTimeModePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetStartTimeMode>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Mode"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Mode"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string mode() const { return parse_json<std::string>::parse(m_values["Mode"]); }

  void setMode(const std::string& mode)
  {
    m_values.AddMember("Mode", parse_json<std::string>::format(mode, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetStartTimeMode);
} // namespace Cmd
} // namespace Sdx
