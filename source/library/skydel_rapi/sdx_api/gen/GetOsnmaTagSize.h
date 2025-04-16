#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get OSNMA tag size.
///
///
///

class GetOsnmaTagSize;
typedef std::shared_ptr<GetOsnmaTagSize> GetOsnmaTagSizePtr;

class GetOsnmaTagSize : public CommandBase
{
public:
  inline static const char* const CmdName = "GetOsnmaTagSize";
  inline static const char* const Documentation = "Get OSNMA tag size.";
  inline static const char* const TargetId = "";

  GetOsnmaTagSize() : CommandBase(CmdName, TargetId) {}

  static GetOsnmaTagSizePtr create() { return std::make_shared<GetOsnmaTagSize>(); }

  static GetOsnmaTagSizePtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetOsnmaTagSize>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetOsnmaTagSize);
} // namespace Cmd
} // namespace Sdx
