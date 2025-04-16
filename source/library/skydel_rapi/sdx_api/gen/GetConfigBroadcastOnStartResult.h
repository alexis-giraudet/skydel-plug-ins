#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetConfigBroadcastOnStart.
///
/// Name             Type Description
/// ---------------- ---- --------------------------------------------------------------
/// BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.
///

class GetConfigBroadcastOnStartResult;
typedef std::shared_ptr<GetConfigBroadcastOnStartResult> GetConfigBroadcastOnStartResultPtr;

class GetConfigBroadcastOnStartResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetConfigBroadcastOnStartResult";
  inline static const char* const Documentation =
    "Result of GetConfigBroadcastOnStart.\n"
    "\n"
    "Name             Type Description\n"
    "---------------- ---- --------------------------------------------------------------\n"
    "BroadcastOnStart bool True to broadcast the configuration on start, false otherwise.";
  inline static const char* const TargetId = "";

  GetConfigBroadcastOnStartResult() : CommandResult(CmdName, TargetId) {}

  GetConfigBroadcastOnStartResult(bool broadcastOnStart) : CommandResult(CmdName, TargetId)
  {

    setBroadcastOnStart(broadcastOnStart);
  }

  GetConfigBroadcastOnStartResult(CommandBasePtr relatedCommand, bool broadcastOnStart) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setBroadcastOnStart(broadcastOnStart);
  }

  static GetConfigBroadcastOnStartResultPtr create(bool broadcastOnStart)
  {
    return std::make_shared<GetConfigBroadcastOnStartResult>(broadcastOnStart);
  }

  static GetConfigBroadcastOnStartResultPtr create(CommandBasePtr relatedCommand, bool broadcastOnStart)
  {
    return std::make_shared<GetConfigBroadcastOnStartResult>(relatedCommand, broadcastOnStart);
  }

  static GetConfigBroadcastOnStartResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetConfigBroadcastOnStartResult>(ptr);
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

  bool broadcastOnStart() const { return parse_json<bool>::parse(m_values["BroadcastOnStart"]); }

  void setBroadcastOnStart(bool broadcastOnStart)
  {
    m_values.AddMember("BroadcastOnStart",
                       parse_json<bool>::format(broadcastOnStart, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetConfigBroadcastOnStartResult);
} // namespace Cmd
} // namespace Sdx
