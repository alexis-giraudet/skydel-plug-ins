#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get OSNMA TESLA hash function.
///
///
///

class GetOsnmaTeslaHashFunction;
typedef std::shared_ptr<GetOsnmaTeslaHashFunction> GetOsnmaTeslaHashFunctionPtr;

class GetOsnmaTeslaHashFunction : public CommandBase
{
public:
  inline static const char* const CmdName = "GetOsnmaTeslaHashFunction";
  inline static const char* const Documentation = "Get OSNMA TESLA hash function.";
  inline static const char* const TargetId = "";

  GetOsnmaTeslaHashFunction() : CommandBase(CmdName, TargetId) {}

  static GetOsnmaTeslaHashFunctionPtr create() { return std::make_shared<GetOsnmaTeslaHashFunction>(); }

  static GetOsnmaTeslaHashFunctionPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetOsnmaTeslaHashFunction>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetOsnmaTeslaHashFunction);
} // namespace Cmd
} // namespace Sdx
