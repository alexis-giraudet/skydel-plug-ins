#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
///
///
///

class GetIssueOfDataBeiDou;
typedef std::shared_ptr<GetIssueOfDataBeiDou> GetIssueOfDataBeiDouPtr;

class GetIssueOfDataBeiDou : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIssueOfDataBeiDou";
  inline static const char* const Documentation =
    "Get BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";
  inline static const char* const TargetId = "";

  GetIssueOfDataBeiDou() : CommandBase(CmdName, TargetId) {}

  static GetIssueOfDataBeiDouPtr create() { return std::make_shared<GetIssueOfDataBeiDou>(); }

  static GetIssueOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIssueOfDataBeiDou>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataBeiDou);
} // namespace Cmd
} // namespace Sdx
