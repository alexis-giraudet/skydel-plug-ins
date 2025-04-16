#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).
///
///
///

class IsElevationMaskBelowEnabled;
typedef std::shared_ptr<IsElevationMaskBelowEnabled> IsElevationMaskBelowEnabledPtr;

class IsElevationMaskBelowEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsElevationMaskBelowEnabled";
  inline static const char* const Documentation =
    "Get GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).";
  inline static const char* const TargetId = "";

  IsElevationMaskBelowEnabled() : CommandBase(CmdName, TargetId) {}

  static IsElevationMaskBelowEnabledPtr create() { return std::make_shared<IsElevationMaskBelowEnabled>(); }

  static IsElevationMaskBelowEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsElevationMaskBelowEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsElevationMaskBelowEnabled);
} // namespace Cmd
} // namespace Sdx
