#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get NavIC Issue of data, Ephemeris and Clock (IODEC)
///
///
///

class GetIssueOfDataNavIC;
typedef std::shared_ptr<GetIssueOfDataNavIC> GetIssueOfDataNavICPtr;

class GetIssueOfDataNavIC : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIssueOfDataNavIC";
  inline static const char* const Documentation = "Get NavIC Issue of data, Ephemeris and Clock (IODEC)";
  inline static const char* const TargetId = "";

  GetIssueOfDataNavIC() : CommandBase(CmdName, TargetId) {}

  static GetIssueOfDataNavICPtr create() { return std::make_shared<GetIssueOfDataNavIC>(); }

  static GetIssueOfDataNavICPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIssueOfDataNavIC>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataNavIC);
} // namespace Cmd
} // namespace Sdx
