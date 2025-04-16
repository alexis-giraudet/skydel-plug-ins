#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).
///
///
///

class IsElevationMaskAboveEnabled;
typedef std::shared_ptr<IsElevationMaskAboveEnabled> IsElevationMaskAboveEnabledPtr;

class IsElevationMaskAboveEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsElevationMaskAboveEnabled";
  inline static const char* const Documentation =
    "Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).";
  inline static const char* const TargetId = "";

  IsElevationMaskAboveEnabled() : CommandBase(CmdName, TargetId) {}

  static IsElevationMaskAboveEnabledPtr create() { return std::make_shared<IsElevationMaskAboveEnabled>(); }

  static IsElevationMaskAboveEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsElevationMaskAboveEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsElevationMaskAboveEnabled);
} // namespace Cmd
} // namespace Sdx
