#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get last Hardware in the loop extrapolation state. The states are defined as
/// the following increasing priority levels: Deterministic, NonDeterministic and Snap.
/// The state will stay on the highest level until polled. Polling the extrapolation state will reset it.
/// Returns GetHilExtrapolationStateResult.
///
///
///

class GetHilExtrapolationState;
typedef std::shared_ptr<GetHilExtrapolationState> GetHilExtrapolationStatePtr;

class GetHilExtrapolationState : public CommandBase
{
public:
  inline static const char* const CmdName = "GetHilExtrapolationState";
  inline static const char* const Documentation =
    "Get last Hardware in the loop extrapolation state. The states are defined as\n"
    "the following increasing priority levels: Deterministic, NonDeterministic and Snap.\n"
    "The state will stay on the highest level until polled. Polling the extrapolation state will reset it.\n"
    "Returns GetHilExtrapolationStateResult.";
  inline static const char* const TargetId = "";

  GetHilExtrapolationState() : CommandBase(CmdName, TargetId) {}

  static GetHilExtrapolationStatePtr create() { return std::make_shared<GetHilExtrapolationState>(); }

  static GetHilExtrapolationStatePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetHilExtrapolationState>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetHilExtrapolationState);
} // namespace Cmd
} // namespace Sdx
