#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get time delay to start streaming after PPS synchronization. A value of 1500
/// means the simulation will start streaming 1.5 sec after the PPS used for
/// synchornization.
///
///
///

class GetSyncTimeMainInstance;
typedef std::shared_ptr<GetSyncTimeMainInstance> GetSyncTimeMainInstancePtr;

class GetSyncTimeMainInstance : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSyncTimeMainInstance";
  inline static const char* const Documentation =
    "Get time delay to start streaming after PPS synchronization. A value of 1500\n"
    "means the simulation will start streaming 1.5 sec after the PPS used for\n"
    "synchornization.";
  inline static const char* const TargetId = "";

  GetSyncTimeMainInstance() : CommandBase(CmdName, TargetId) {}

  static GetSyncTimeMainInstancePtr create() { return std::make_shared<GetSyncTimeMainInstance>(); }

  static GetSyncTimeMainInstancePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSyncTimeMainInstance>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSyncTimeMainInstance);
} // namespace Cmd
} // namespace Sdx
