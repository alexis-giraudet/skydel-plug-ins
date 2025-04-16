#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"
#include "gen/SVDataUpdateMode.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSVDataUpdateMode.
///
/// Name Type             Description
/// ---- ---------------- ------------------------------------------------------------------
/// Mode SVDataUpdateMode SV Data Update Mode:
///                       Extrapolation: Skydel extrapolates from the first block (default).
///                       Dynamic: Blocks must be pushed during the simulation.
///

class GetSVDataUpdateModeResult;
typedef std::shared_ptr<GetSVDataUpdateModeResult> GetSVDataUpdateModeResultPtr;

class GetSVDataUpdateModeResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSVDataUpdateModeResult";
  inline static const char* const Documentation =
    "Result of GetSVDataUpdateMode.\n"
    "\n"
    "Name Type             Description\n"
    "---- ---------------- ------------------------------------------------------------------\n"
    "Mode SVDataUpdateMode SV Data Update Mode:\n"
    "                      Extrapolation: Skydel extrapolates from the first block (default).\n"
    "                      Dynamic: Blocks must be pushed during the simulation.";
  inline static const char* const TargetId = "";

  GetSVDataUpdateModeResult() : CommandResult(CmdName, TargetId) {}

  GetSVDataUpdateModeResult(const Sdx::SVDataUpdateMode& mode) : CommandResult(CmdName, TargetId) { setMode(mode); }

  GetSVDataUpdateModeResult(CommandBasePtr relatedCommand, const Sdx::SVDataUpdateMode& mode) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setMode(mode);
  }

  static GetSVDataUpdateModeResultPtr create(const Sdx::SVDataUpdateMode& mode)
  {
    return std::make_shared<GetSVDataUpdateModeResult>(mode);
  }

  static GetSVDataUpdateModeResultPtr create(CommandBasePtr relatedCommand, const Sdx::SVDataUpdateMode& mode)
  {
    return std::make_shared<GetSVDataUpdateModeResult>(relatedCommand, mode);
  }

  static GetSVDataUpdateModeResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSVDataUpdateModeResult>(ptr);
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

  Sdx::SVDataUpdateMode mode() const { return parse_json<Sdx::SVDataUpdateMode>::parse(m_values["Mode"]); }

  void setMode(const Sdx::SVDataUpdateMode& mode)
  {
    m_values.AddMember("Mode",
                       parse_json<Sdx::SVDataUpdateMode>::format(mode, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSVDataUpdateModeResult);
} // namespace Cmd
} // namespace Sdx
