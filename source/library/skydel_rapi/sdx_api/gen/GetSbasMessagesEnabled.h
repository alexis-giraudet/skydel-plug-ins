#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the enabled SBAS messages. Message 63 is always enabled
///
///
///

class GetSbasMessagesEnabled;
typedef std::shared_ptr<GetSbasMessagesEnabled> GetSbasMessagesEnabledPtr;

class GetSbasMessagesEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSbasMessagesEnabled";
  inline static const char* const Documentation = "Get the enabled SBAS messages. Message 63 is always enabled";
  inline static const char* const TargetId = "";

  GetSbasMessagesEnabled() : CommandBase(CmdName, TargetId) {}

  static GetSbasMessagesEnabledPtr create() { return std::make_shared<GetSbasMessagesEnabled>(); }

  static GetSbasMessagesEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasMessagesEnabled>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetSbasMessagesEnabled);
} // namespace Cmd
} // namespace Sdx
