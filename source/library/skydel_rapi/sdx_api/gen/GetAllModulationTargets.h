#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get all the modulation targets IDs
///
///
///

class GetAllModulationTargets;
typedef std::shared_ptr<GetAllModulationTargets> GetAllModulationTargetsPtr;

class GetAllModulationTargets : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAllModulationTargets";
  inline static const char* const Documentation = "Get all the modulation targets IDs";
  inline static const char* const TargetId = "";

  GetAllModulationTargets() : CommandBase(CmdName, TargetId) {}

  static GetAllModulationTargetsPtr create() { return std::make_shared<GetAllModulationTargets>(); }

  static GetAllModulationTargetsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllModulationTargets>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAllModulationTargets);
} // namespace Cmd
} // namespace Sdx
