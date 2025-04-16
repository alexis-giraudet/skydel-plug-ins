#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get whether by default transmitters should keep the modification done during simulation.
///
///
///

class GetDefaultIntTxPersistence;
typedef std::shared_ptr<GetDefaultIntTxPersistence> GetDefaultIntTxPersistencePtr;

class GetDefaultIntTxPersistence : public CommandBase
{
public:
  inline static const char* const CmdName = "GetDefaultIntTxPersistence";
  inline static const char* const Documentation =
    "Get whether by default transmitters should keep the modification done during simulation.";
  inline static const char* const TargetId = "";

  GetDefaultIntTxPersistence() : CommandBase(CmdName, TargetId) {}

  static GetDefaultIntTxPersistencePtr create() { return std::make_shared<GetDefaultIntTxPersistence>(); }

  static GetDefaultIntTxPersistencePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetDefaultIntTxPersistence>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetDefaultIntTxPersistence);
} // namespace Cmd
} // namespace Sdx
