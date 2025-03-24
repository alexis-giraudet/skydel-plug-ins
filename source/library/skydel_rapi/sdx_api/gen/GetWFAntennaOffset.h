#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the WF antenna offset infos.
///
///
///

class GetWFAntennaOffset;
typedef std::shared_ptr<GetWFAntennaOffset> GetWFAntennaOffsetPtr;

class GetWFAntennaOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetWFAntennaOffset";
  inline static const char* const Documentation = "Get the WF antenna offset infos.";
  inline static const char* const TargetId = "";

  GetWFAntennaOffset() : CommandBase(CmdName, TargetId) {}

  static GetWFAntennaOffsetPtr create() { return std::make_shared<GetWFAntennaOffset>(); }

  static GetWFAntennaOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetWFAntennaOffset>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetWFAntennaOffset);
} // namespace Cmd
} // namespace Sdx
