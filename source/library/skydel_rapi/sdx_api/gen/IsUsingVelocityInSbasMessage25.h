#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get whether SBAS message 25 should send velocity corrections
///
///
///

class IsUsingVelocityInSbasMessage25;
typedef std::shared_ptr<IsUsingVelocityInSbasMessage25> IsUsingVelocityInSbasMessage25Ptr;

class IsUsingVelocityInSbasMessage25 : public CommandBase
{
public:
  inline static const char* const CmdName = "IsUsingVelocityInSbasMessage25";
  inline static const char* const Documentation = "Get whether SBAS message 25 should send velocity corrections";
  inline static const char* const TargetId = "";

  IsUsingVelocityInSbasMessage25() : CommandBase(CmdName, TargetId) {}

  static IsUsingVelocityInSbasMessage25Ptr create() { return std::make_shared<IsUsingVelocityInSbasMessage25>(); }

  static IsUsingVelocityInSbasMessage25Ptr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsUsingVelocityInSbasMessage25>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsUsingVelocityInSbasMessage25);
} // namespace Cmd
} // namespace Sdx
