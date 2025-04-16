#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to
/// set the start time of the simulation. This value has no effect when GPS start time is "custom" or "computer".
///
/// Name   Type Description
/// ------ ---- -----------------------------------------------------------------------------------------
/// Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver
///

class SetStartTimeOffset;
typedef std::shared_ptr<SetStartTimeOffset> SetStartTimeOffsetPtr;

class SetStartTimeOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "SetStartTimeOffset";
  inline static const char* const Documentation =
    "Set offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.\n"
    "This value has no effect when GPS start time is \"custom\" or \"computer\".\n"
    "\n"
    "Name   Type Description\n"
    "------ ---- -----------------------------------------------------------------------------------------\n"
    "Offset int  Time Offset, in seconds, between simulated GPS time and time given by GPS Timing receiver";
  inline static const char* const TargetId = "";

  SetStartTimeOffset() : CommandBase(CmdName, TargetId) {}

  SetStartTimeOffset(int offset) : CommandBase(CmdName, TargetId) { setOffset(offset); }

  static SetStartTimeOffsetPtr create(int offset) { return std::make_shared<SetStartTimeOffset>(offset); }

  static SetStartTimeOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetStartTimeOffset>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Offset"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Offset"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int offset() const { return parse_json<int>::parse(m_values["Offset"]); }

  void setOffset(int offset)
  {
    m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetStartTimeOffset);
} // namespace Cmd
} // namespace Sdx
