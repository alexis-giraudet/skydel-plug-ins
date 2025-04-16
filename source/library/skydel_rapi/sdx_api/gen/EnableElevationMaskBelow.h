#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).
///
/// Name    Type Description
/// ------- ---- ------------------------------------------------------------------
/// Enabled bool If true, mask satellites with elevation angle below masking angle.
///

class EnableElevationMaskBelow;
typedef std::shared_ptr<EnableElevationMaskBelow> EnableElevationMaskBelowPtr;

class EnableElevationMaskBelow : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableElevationMaskBelow";
  inline static const char* const Documentation =
    "Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ------------------------------------------------------------------\n"
    "Enabled bool If true, mask satellites with elevation angle below masking angle.";
  inline static const char* const TargetId = "";

  EnableElevationMaskBelow() : CommandBase(CmdName, TargetId) {}

  EnableElevationMaskBelow(bool enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static EnableElevationMaskBelowPtr create(bool enabled)
  {
    return std::make_shared<EnableElevationMaskBelow>(enabled);
  }

  static EnableElevationMaskBelowPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableElevationMaskBelow>(ptr);
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

  int executePermission() const { return EXECUTE_IF_IDLE; }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableElevationMaskBelow);
} // namespace Cmd
} // namespace Sdx
