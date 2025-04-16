#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Skydel version.
///
///
///

class GetVersion;
typedef std::shared_ptr<GetVersion> GetVersionPtr;

class GetVersion : public CommandBase
{
public:
  inline static const char* const CmdName = "GetVersion";
  inline static const char* const Documentation = "Get Skydel version.";
  inline static const char* const TargetId = "";

  GetVersion() : CommandBase(CmdName, TargetId) {}

  static GetVersionPtr create() { return std::make_shared<GetVersion>(); }

  static GetVersionPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetVersion>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetVersion);
} // namespace Cmd
} // namespace Sdx
