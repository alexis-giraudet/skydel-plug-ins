#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Hardware in the loop trajectory server port.
///
///
///

class GetHilPort;
typedef std::shared_ptr<GetHilPort> GetHilPortPtr;

class GetHilPort : public CommandBase
{
public:
  inline static const char* const CmdName = "GetHilPort";
  inline static const char* const Documentation = "Get Hardware in the loop trajectory server port.";
  inline static const char* const TargetId = "";

  GetHilPort() : CommandBase(CmdName, TargetId) {}

  static GetHilPortPtr create() { return std::make_shared<GetHilPort>(); }

  static GetHilPortPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetHilPort>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetHilPort);
} // namespace Cmd
} // namespace Sdx
