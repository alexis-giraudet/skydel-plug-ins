#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)
///
///
///

class GetIssueOfDataGalileo;
typedef std::shared_ptr<GetIssueOfDataGalileo> GetIssueOfDataGalileoPtr;

class GetIssueOfDataGalileo : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIssueOfDataGalileo";
  inline static const char* const Documentation =
    "Get Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)";
  inline static const char* const TargetId = "";

  GetIssueOfDataGalileo() : CommandBase(CmdName, TargetId) {}

  static GetIssueOfDataGalileoPtr create() { return std::make_shared<GetIssueOfDataGalileo>(); }

  static GetIssueOfDataGalileoPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIssueOfDataGalileo>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataGalileo);
} // namespace Cmd
} // namespace Sdx
