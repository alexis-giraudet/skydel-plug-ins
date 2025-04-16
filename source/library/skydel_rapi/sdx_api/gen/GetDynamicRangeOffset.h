#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals.
/// Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite
/// power sliders in the Constellation tab is shifted by this offset.
///
///
///

class GetDynamicRangeOffset;
typedef std::shared_ptr<GetDynamicRangeOffset> GetDynamicRangeOffsetPtr;

class GetDynamicRangeOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetDynamicRangeOffset";
  inline static const char* const Documentation =
    "Get the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.";
  inline static const char* const TargetId = "";

  GetDynamicRangeOffset() : CommandBase(CmdName, TargetId) {}

  static GetDynamicRangeOffsetPtr create() { return std::make_shared<GetDynamicRangeOffset>(); }

  static GetDynamicRangeOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetDynamicRangeOffset>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetDynamicRangeOffset);
} // namespace Cmd
} // namespace Sdx
