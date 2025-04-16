#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Clears the status log
///
///
///

class ClearStatusLog;
typedef std::shared_ptr<ClearStatusLog> ClearStatusLogPtr;

class ClearStatusLog : public CommandBase
{
public:
  inline static const char* const CmdName = "ClearStatusLog";
  inline static const char* const Documentation = "Clears the status log";
  inline static const char* const TargetId = "";

  ClearStatusLog() : CommandBase(CmdName, TargetId) {}

  static ClearStatusLogPtr create() { return std::make_shared<ClearStatusLog>(); }

  static ClearStatusLogPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<ClearStatusLog>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(ClearStatusLog);
} // namespace Cmd
} // namespace Sdx
