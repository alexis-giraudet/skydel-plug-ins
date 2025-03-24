#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get OSNMA TESLA key size.
///
///
///

class GetOsnmaTeslaKeySize;
typedef std::shared_ptr<GetOsnmaTeslaKeySize> GetOsnmaTeslaKeySizePtr;

class GetOsnmaTeslaKeySize : public CommandBase
{
public:
  inline static const char* const CmdName = "GetOsnmaTeslaKeySize";
  inline static const char* const Documentation = "Get OSNMA TESLA key size.";
  inline static const char* const TargetId = "";

  GetOsnmaTeslaKeySize() : CommandBase(CmdName, TargetId) {}

  static GetOsnmaTeslaKeySizePtr create() { return std::make_shared<GetOsnmaTeslaKeySize>(); }

  static GetOsnmaTeslaKeySizePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetOsnmaTeslaKeySize>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetOsnmaTeslaKeySize);
} // namespace Cmd
} // namespace Sdx
