#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"
#include "gen/SVDataUpdateMode.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the SV Data Update Mode.
///
/// Name Type             Description
/// ---- ---------------- ------------------------------------------------------------------
/// Mode SVDataUpdateMode SV Data Update Mode:
///                       Extrapolation: Skydel extrapolates from the first block (default).
///                       Dynamic: Blocks must be pushed during the simulation.
///

class SetSVDataUpdateMode;
typedef std::shared_ptr<SetSVDataUpdateMode> SetSVDataUpdateModePtr;

class SetSVDataUpdateMode : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSVDataUpdateMode";
  inline static const char* const Documentation =
    "Set the SV Data Update Mode.\n"
    "\n"
    "Name Type             Description\n"
    "---- ---------------- ------------------------------------------------------------------\n"
    "Mode SVDataUpdateMode SV Data Update Mode:\n"
    "                      Extrapolation: Skydel extrapolates from the first block (default).\n"
    "                      Dynamic: Blocks must be pushed during the simulation.";
  inline static const char* const TargetId = "";

  SetSVDataUpdateMode() : CommandBase(CmdName, TargetId) {}

  SetSVDataUpdateMode(const Sdx::SVDataUpdateMode& mode) : CommandBase(CmdName, TargetId) { setMode(mode); }

  static SetSVDataUpdateModePtr create(const Sdx::SVDataUpdateMode& mode)
  {
    return std::make_shared<SetSVDataUpdateMode>(mode);
  }

  static SetSVDataUpdateModePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSVDataUpdateMode>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::SVDataUpdateMode>::is_valid(m_values["Mode"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Mode"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  Sdx::SVDataUpdateMode mode() const { return parse_json<Sdx::SVDataUpdateMode>::parse(m_values["Mode"]); }

  void setMode(const Sdx::SVDataUpdateMode& mode)
  {
    m_values.AddMember("Mode",
                       parse_json<Sdx::SVDataUpdateMode>::format(mode, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSVDataUpdateMode);
} // namespace Cmd
} // namespace Sdx
