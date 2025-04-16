#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle
///
///
///

class IsSignalStrengthModelEnabled;
typedef std::shared_ptr<IsSignalStrengthModelEnabled> IsSignalStrengthModelEnabledPtr;

class IsSignalStrengthModelEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsSignalStrengthModelEnabled";
  inline static const char* const Documentation =
    "Get signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle";
  inline static const char* const TargetId = "";

  IsSignalStrengthModelEnabled() : CommandBase(CmdName, TargetId) {}

  static IsSignalStrengthModelEnabledPtr create() { return std::make_shared<IsSignalStrengthModelEnabled>(); }

  static IsSignalStrengthModelEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSignalStrengthModelEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsSignalStrengthModelEnabled);
} // namespace Cmd
} // namespace Sdx
