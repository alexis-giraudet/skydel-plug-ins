#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Save configuration.
///
///
///

class Save;
typedef std::shared_ptr<Save> SavePtr;

class Save : public CommandBase
{
public:
  inline static const char* const CmdName = "Save";
  inline static const char* const Documentation = "Save configuration.";
  inline static const char* const TargetId = "";

  Save() : CommandBase(CmdName, TargetId) {}

  static SavePtr create() { return std::make_shared<Save>(); }

  static SavePtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<Save>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(Save);
} // namespace Cmd
} // namespace Sdx
