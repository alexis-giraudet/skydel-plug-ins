#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command GetPowerGlobalOffset is deprecated since 21.7. You may use GetGlobalPowerOffset.
///
/// Get global power offset default value for all signals and all systems
///
///
///

class GetPowerGlobalOffset;
typedef std::shared_ptr<GetPowerGlobalOffset> GetPowerGlobalOffsetPtr;

class GetPowerGlobalOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPowerGlobalOffset";
  inline static const char* const Documentation =
    "Please note the command GetPowerGlobalOffset is deprecated since 21.7. You may use GetGlobalPowerOffset.\n"
    "\n"
    "Get global power offset default value for all signals and all systems";
  inline static const char* const TargetId = "";

  GetPowerGlobalOffset() : CommandBase(CmdName, TargetId) {}

  static GetPowerGlobalOffsetPtr create() { return std::make_shared<GetPowerGlobalOffset>(); }

  static GetPowerGlobalOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPowerGlobalOffset>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetPowerGlobalOffset);
} // namespace Cmd
} // namespace Sdx
