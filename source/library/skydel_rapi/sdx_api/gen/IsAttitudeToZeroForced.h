#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get force vehicle yaw, pitch and roll to zero enabled or disabled
///
///
///

class IsAttitudeToZeroForced;
typedef std::shared_ptr<IsAttitudeToZeroForced> IsAttitudeToZeroForcedPtr;

class IsAttitudeToZeroForced : public CommandBase
{
public:
  inline static const char* const CmdName = "IsAttitudeToZeroForced";
  inline static const char* const Documentation = "Get force vehicle yaw, pitch and roll to zero enabled or disabled";
  inline static const char* const TargetId = "";

  IsAttitudeToZeroForced() : CommandBase(CmdName, TargetId) {}

  static IsAttitudeToZeroForcedPtr create() { return std::make_shared<IsAttitudeToZeroForced>(); }

  static IsAttitudeToZeroForcedPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsAttitudeToZeroForced>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsAttitudeToZeroForced);
} // namespace Cmd
} // namespace Sdx
