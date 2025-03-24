#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Remove all the interference transmitters.
///
///
///

class RemoveAllIntTx;
typedef std::shared_ptr<RemoveAllIntTx> RemoveAllIntTxPtr;

class RemoveAllIntTx : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveAllIntTx";
  inline static const char* const Documentation = "Remove all the interference transmitters.";
  inline static const char* const TargetId = "";

  RemoveAllIntTx() : CommandBase(CmdName, TargetId) {}

  static RemoveAllIntTxPtr create() { return std::make_shared<RemoveAllIntTx>(); }

  static RemoveAllIntTxPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<RemoveAllIntTx>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(RemoveAllIntTx);
} // namespace Cmd
} // namespace Sdx
