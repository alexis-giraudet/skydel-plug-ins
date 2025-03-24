#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with
/// an index 1, etc.
///
///
///

class GetIonoGridErrorAll;
typedef std::shared_ptr<GetIonoGridErrorAll> GetIonoGridErrorAllPtr;

class GetIonoGridErrorAll : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIonoGridErrorAll";
  inline static const char* const Documentation =
    "Get Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.";
  inline static const char* const TargetId = "";

  GetIonoGridErrorAll() : CommandBase(CmdName, TargetId) {}

  static GetIonoGridErrorAllPtr create() { return std::make_shared<GetIonoGridErrorAll>(); }

  static GetIonoGridErrorAllPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridErrorAll>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIonoGridErrorAll);
} // namespace Cmd
} // namespace Sdx
