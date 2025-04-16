#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Tells if ephemeris data Logging is enabled
///
///
///

class IsLogRinexEnabled;
typedef std::shared_ptr<IsLogRinexEnabled> IsLogRinexEnabledPtr;

class IsLogRinexEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsLogRinexEnabled";
  inline static const char* const Documentation = "Tells if ephemeris data Logging is enabled";
  inline static const char* const TargetId = "";

  IsLogRinexEnabled() : CommandBase(CmdName, TargetId) {}

  static IsLogRinexEnabledPtr create() { return std::make_shared<IsLogRinexEnabled>(); }

  static IsLogRinexEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLogRinexEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsLogRinexEnabled);
} // namespace Cmd
} // namespace Sdx
