#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Arm the system for further PPS synchronization instructions.
///
///
///

class ArmPPS;
typedef std::shared_ptr<ArmPPS> ArmPPSPtr;

class ArmPPS : public CommandBase
{
public:
  inline static const char* const CmdName = "ArmPPS";
  inline static const char* const Documentation = "Arm the system for further PPS synchronization instructions.";
  inline static const char* const TargetId = "";

  ArmPPS() : CommandBase(CmdName, TargetId) {}

  static ArmPPSPtr create() { return std::make_shared<ArmPPS>(); }

  static ArmPPSPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<ArmPPS>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(ArmPPS);
} // namespace Cmd
} // namespace Sdx
