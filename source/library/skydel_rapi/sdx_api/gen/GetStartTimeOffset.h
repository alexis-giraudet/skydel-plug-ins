#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to
/// set the start time of the simulation. This value has no effect when GPS start time is "custom" or "computer".
///
///
///

class GetStartTimeOffset;
typedef std::shared_ptr<GetStartTimeOffset> GetStartTimeOffsetPtr;

class GetStartTimeOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetStartTimeOffset";
  inline static const char* const Documentation =
    "Get offset between the simulated GPS time and time given by GPS Timing receiver when using GPS Timing receiver to set the start time of the simulation.\n"
    "This value has no effect when GPS start time is \"custom\" or \"computer\".";
  inline static const char* const TargetId = "";

  GetStartTimeOffset() : CommandBase(CmdName, TargetId) {}

  static GetStartTimeOffsetPtr create() { return std::make_shared<GetStartTimeOffset>(); }

  static GetStartTimeOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetStartTimeOffset>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetStartTimeOffset);
} // namespace Cmd
} // namespace Sdx
