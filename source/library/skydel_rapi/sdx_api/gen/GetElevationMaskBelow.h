#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get elevation mask angle. See command EnableElevationMaskBelow
///
///
///

class GetElevationMaskBelow;
typedef std::shared_ptr<GetElevationMaskBelow> GetElevationMaskBelowPtr;

class GetElevationMaskBelow : public CommandBase
{
public:
  inline static const char* const CmdName = "GetElevationMaskBelow";
  inline static const char* const Documentation = "Get elevation mask angle. See command EnableElevationMaskBelow";
  inline static const char* const TargetId = "";

  GetElevationMaskBelow() : CommandBase(CmdName, TargetId) {}

  static GetElevationMaskBelowPtr create() { return std::make_shared<GetElevationMaskBelow>(); }

  static GetElevationMaskBelowPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetElevationMaskBelow>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetElevationMaskBelow);
} // namespace Cmd
} // namespace Sdx
