#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get elevation mask angle. See command EnableElevationMaskAbove
///
///
///

class GetElevationMaskAbove;
typedef std::shared_ptr<GetElevationMaskAbove> GetElevationMaskAbovePtr;

class GetElevationMaskAbove : public CommandBase
{
public:
  inline static const char* const CmdName = "GetElevationMaskAbove";
  inline static const char* const Documentation = "Get elevation mask angle. See command EnableElevationMaskAbove";
  inline static const char* const TargetId = "";

  GetElevationMaskAbove() : CommandBase(CmdName, TargetId) {}

  static GetElevationMaskAbovePtr create() { return std::make_shared<GetElevationMaskAbove>(); }

  static GetElevationMaskAbovePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetElevationMaskAbove>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetElevationMaskAbove);
} // namespace Cmd
} // namespace Sdx
