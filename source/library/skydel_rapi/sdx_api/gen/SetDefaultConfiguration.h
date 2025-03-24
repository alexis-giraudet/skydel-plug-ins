#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set current configuration as default configuration.
///
///
///

class SetDefaultConfiguration;
typedef std::shared_ptr<SetDefaultConfiguration> SetDefaultConfigurationPtr;

class SetDefaultConfiguration : public CommandBase
{
public:
  inline static const char* const CmdName = "SetDefaultConfiguration";
  inline static const char* const Documentation = "Set current configuration as default configuration.";
  inline static const char* const TargetId = "";

  SetDefaultConfiguration() : CommandBase(CmdName, TargetId) {}

  static SetDefaultConfigurationPtr create() { return std::make_shared<SetDefaultConfiguration>(); }

  static SetDefaultConfigurationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetDefaultConfiguration>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetDefaultConfiguration);
} // namespace Cmd
} // namespace Sdx
