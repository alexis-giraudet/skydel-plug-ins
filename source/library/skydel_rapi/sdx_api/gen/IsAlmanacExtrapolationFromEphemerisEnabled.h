#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get state of almanac extrapolation from ephemeris in Dynamic SV data.
///
///
///

class IsAlmanacExtrapolationFromEphemerisEnabled;
typedef std::shared_ptr<IsAlmanacExtrapolationFromEphemerisEnabled> IsAlmanacExtrapolationFromEphemerisEnabledPtr;

class IsAlmanacExtrapolationFromEphemerisEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsAlmanacExtrapolationFromEphemerisEnabled";
  inline static const char* const Documentation =
    "Get state of almanac extrapolation from ephemeris in Dynamic SV data.";
  inline static const char* const TargetId = "";

  IsAlmanacExtrapolationFromEphemerisEnabled() : CommandBase(CmdName, TargetId) {}

  static IsAlmanacExtrapolationFromEphemerisEnabledPtr create()
  {
    return std::make_shared<IsAlmanacExtrapolationFromEphemerisEnabled>();
  }

  static IsAlmanacExtrapolationFromEphemerisEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsAlmanacExtrapolationFromEphemerisEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsAlmanacExtrapolationFromEphemerisEnabled);
} // namespace Cmd
} // namespace Sdx
