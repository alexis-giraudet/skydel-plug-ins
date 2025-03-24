#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.
///
///
///

class GetGpsTimingReceiver;
typedef std::shared_ptr<GetGpsTimingReceiver> GetGpsTimingReceiverPtr;

class GetGpsTimingReceiver : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGpsTimingReceiver";
  inline static const char* const Documentation =
    "Get the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.";
  inline static const char* const TargetId = "";

  GetGpsTimingReceiver() : CommandBase(CmdName, TargetId) {}

  static GetGpsTimingReceiverPtr create() { return std::make_shared<GetGpsTimingReceiver>(); }

  static GetGpsTimingReceiverPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGpsTimingReceiver>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetGpsTimingReceiver);
} // namespace Cmd
} // namespace Sdx
