#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Returns the last known leap second date
///
///
///

class GetLastLeapSecondDate;
typedef std::shared_ptr<GetLastLeapSecondDate> GetLastLeapSecondDatePtr;

class GetLastLeapSecondDate : public CommandBase
{
public:
  inline static const char* const CmdName = "GetLastLeapSecondDate";
  inline static const char* const Documentation = "Returns the last known leap second date";
  inline static const char* const TargetId = "";

  GetLastLeapSecondDate() : CommandBase(CmdName, TargetId) {}

  static GetLastLeapSecondDatePtr create() { return std::make_shared<GetLastLeapSecondDate>(); }

  static GetLastLeapSecondDatePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetLastLeapSecondDate>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetLastLeapSecondDate);
} // namespace Cmd
} // namespace Sdx
