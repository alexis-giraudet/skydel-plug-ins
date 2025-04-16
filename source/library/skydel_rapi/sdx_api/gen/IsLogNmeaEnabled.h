#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Logging of NMEA for the simulated position enable/disable.
/// If a receiver is connected, that NMEA is saved as well.
///
///
///

class IsLogNmeaEnabled;
typedef std::shared_ptr<IsLogNmeaEnabled> IsLogNmeaEnabledPtr;

class IsLogNmeaEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsLogNmeaEnabled";
  inline static const char* const Documentation = "Get Logging of NMEA for the simulated position enable/disable.\n"
                                                  "If a receiver is connected, that NMEA is saved as well.";
  inline static const char* const TargetId = "";

  IsLogNmeaEnabled() : CommandBase(CmdName, TargetId) {}

  static IsLogNmeaEnabledPtr create() { return std::make_shared<IsLogNmeaEnabled>(); }

  static IsLogNmeaEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLogNmeaEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsLogNmeaEnabled);
} // namespace Cmd
} // namespace Sdx
