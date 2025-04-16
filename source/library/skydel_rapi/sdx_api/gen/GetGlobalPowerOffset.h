#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get global power offset default value for all signals and all systems
///
///
///

class GetGlobalPowerOffset;
typedef std::shared_ptr<GetGlobalPowerOffset> GetGlobalPowerOffsetPtr;

class GetGlobalPowerOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGlobalPowerOffset";
  inline static const char* const Documentation =
    "Get global power offset default value for all signals and all systems";
  inline static const char* const TargetId = "";

  GetGlobalPowerOffset() : CommandBase(CmdName, TargetId) {}

  static GetGlobalPowerOffsetPtr create() { return std::make_shared<GetGlobalPowerOffset>(); }

  static GetGlobalPowerOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGlobalPowerOffset>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetGlobalPowerOffset);
} // namespace Cmd
} // namespace Sdx
