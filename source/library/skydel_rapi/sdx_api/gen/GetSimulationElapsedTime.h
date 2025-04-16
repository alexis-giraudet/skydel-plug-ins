#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get simulation elapsed time in milliseconds.
///
///
///

class GetSimulationElapsedTime;
typedef std::shared_ptr<GetSimulationElapsedTime> GetSimulationElapsedTimePtr;

class GetSimulationElapsedTime : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSimulationElapsedTime";
  inline static const char* const Documentation = "Get simulation elapsed time in milliseconds.";
  inline static const char* const TargetId = "";

  GetSimulationElapsedTime() : CommandBase(CmdName, TargetId) {}

  static GetSimulationElapsedTimePtr create() { return std::make_shared<GetSimulationElapsedTime>(); }

  static GetSimulationElapsedTimePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSimulationElapsedTime>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSimulationElapsedTime);
} // namespace Cmd
} // namespace Sdx
