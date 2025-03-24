#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Clear all interferences
///
///
///

class RemoveAllInterferences;
typedef std::shared_ptr<RemoveAllInterferences> RemoveAllInterferencesPtr;

class RemoveAllInterferences : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveAllInterferences";
  inline static const char* const Documentation = "Clear all interferences";
  inline static const char* const TargetId = "";

  RemoveAllInterferences() : CommandBase(CmdName, TargetId) {}

  static RemoveAllInterferencesPtr create() { return std::make_shared<RemoveAllInterferences>(); }

  static RemoveAllInterferencesPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveAllInterferences>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(RemoveAllInterferences);
} // namespace Cmd
} // namespace Sdx
