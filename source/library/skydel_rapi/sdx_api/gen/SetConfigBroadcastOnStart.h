#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set whether the main instance should send its configuration to every worker instance when simulation start.
///
/// Name             Type Description
/// ---------------- ---- --------------------------------------------------------------
/// BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.
///

class SetConfigBroadcastOnStart;
typedef std::shared_ptr<SetConfigBroadcastOnStart> SetConfigBroadcastOnStartPtr;

class SetConfigBroadcastOnStart : public CommandBase
{
public:
  inline static const char* const CmdName = "SetConfigBroadcastOnStart";
  inline static const char* const Documentation =
    "Set whether the main instance should send its configuration to every worker instance when simulation start.\n"
    "\n"
    "Name             Type Description\n"
    "---------------- ---- --------------------------------------------------------------\n"
    "BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.";
  inline static const char* const TargetId = "";

  SetConfigBroadcastOnStart() : CommandBase(CmdName, TargetId) {}

  SetConfigBroadcastOnStart(bool broadcastOnStart) : CommandBase(CmdName, TargetId)
  {

    setBroadcastOnStart(broadcastOnStart);
  }

  static SetConfigBroadcastOnStartPtr create(bool broadcastOnStart)
  {
    return std::make_shared<SetConfigBroadcastOnStart>(broadcastOnStart);
  }

  static SetConfigBroadcastOnStartPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetConfigBroadcastOnStart>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["BroadcastOnStart"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"BroadcastOnStart"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  bool broadcastOnStart() const { return parse_json<bool>::parse(m_values["BroadcastOnStart"]); }

  void setBroadcastOnStart(bool broadcastOnStart)
  {
    m_values.AddMember("BroadcastOnStart",
                       parse_json<bool>::format(broadcastOnStart, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetConfigBroadcastOnStart);
} // namespace Cmd
} // namespace Sdx
