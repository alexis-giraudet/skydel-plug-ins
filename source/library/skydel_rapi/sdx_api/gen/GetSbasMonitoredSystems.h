#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the systems monitored by SBAS.
///
///
///

class GetSbasMonitoredSystems;
typedef std::shared_ptr<GetSbasMonitoredSystems> GetSbasMonitoredSystemsPtr;

class GetSbasMonitoredSystems : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSbasMonitoredSystems";
  inline static const char* const Documentation = "Get the systems monitored by SBAS.";
  inline static const char* const TargetId = "";

  GetSbasMonitoredSystems() : CommandBase(CmdName, TargetId) {}

  static GetSbasMonitoredSystemsPtr create() { return std::make_shared<GetSbasMonitoredSystems>(); }

  static GetSbasMonitoredSystemsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasMonitoredSystems>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSbasMonitoredSystems);
} // namespace Cmd
} // namespace Sdx
