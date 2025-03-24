#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get  the computer system time since epoch at PPS0, for the computer running this Skydel instance.
/// Use this command after StartPPS.
///
///
///

class GetComputerSystemTimeSinceEpochAtPps0;
typedef std::shared_ptr<GetComputerSystemTimeSinceEpochAtPps0> GetComputerSystemTimeSinceEpochAtPps0Ptr;

class GetComputerSystemTimeSinceEpochAtPps0 : public CommandBase
{
public:
  inline static const char* const CmdName = "GetComputerSystemTimeSinceEpochAtPps0";
  inline static const char* const Documentation =
    "Get  the computer system time since epoch at PPS0, for the computer running this Skydel instance.\n"
    "Use this command after StartPPS.";
  inline static const char* const TargetId = "";

  GetComputerSystemTimeSinceEpochAtPps0() : CommandBase(CmdName, TargetId) {}

  static GetComputerSystemTimeSinceEpochAtPps0Ptr create()
  {
    return std::make_shared<GetComputerSystemTimeSinceEpochAtPps0>();
  }

  static GetComputerSystemTimeSinceEpochAtPps0Ptr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetComputerSystemTimeSinceEpochAtPps0>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetComputerSystemTimeSinceEpochAtPps0);
} // namespace Cmd
} // namespace Sdx
