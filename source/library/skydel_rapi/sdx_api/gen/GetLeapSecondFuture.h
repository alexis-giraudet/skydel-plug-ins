#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the next leap second event
///
///
///

class GetLeapSecondFuture;
typedef std::shared_ptr<GetLeapSecondFuture> GetLeapSecondFuturePtr;

class GetLeapSecondFuture : public CommandBase
{
public:
  inline static const char* const CmdName = "GetLeapSecondFuture";
  inline static const char* const Documentation = "Get the next leap second event";
  inline static const char* const TargetId = "";

  GetLeapSecondFuture() : CommandBase(CmdName, TargetId) {}

  static GetLeapSecondFuturePtr create() { return std::make_shared<GetLeapSecondFuture>(); }

  static GetLeapSecondFuturePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetLeapSecondFuture>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetLeapSecondFuture);
} // namespace Cmd
} // namespace Sdx
