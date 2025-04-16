#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
///
///
///

class GetIssueOfData;
typedef std::shared_ptr<GetIssueOfData> GetIssueOfDataPtr;

class GetIssueOfData : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIssueOfData";
  inline static const char* const Documentation =
    "Get GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";
  inline static const char* const TargetId = "";

  GetIssueOfData() : CommandBase(CmdName, TargetId) {}

  static GetIssueOfDataPtr create() { return std::make_shared<GetIssueOfData>(); }

  static GetIssueOfDataPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetIssueOfData>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetIssueOfData);
} // namespace Cmd
} // namespace Sdx
