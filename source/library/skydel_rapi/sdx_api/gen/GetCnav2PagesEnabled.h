#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the enabled L1C CNAV2 pages
///
///
///

class GetCnav2PagesEnabled;
typedef std::shared_ptr<GetCnav2PagesEnabled> GetCnav2PagesEnabledPtr;

class GetCnav2PagesEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "GetCnav2PagesEnabled";
  inline static const char* const Documentation = "Get the enabled L1C CNAV2 pages";
  inline static const char* const TargetId = "";

  GetCnav2PagesEnabled() : CommandBase(CmdName, TargetId) {}

  static GetCnav2PagesEnabledPtr create() { return std::make_shared<GetCnav2PagesEnabled>(); }

  static GetCnav2PagesEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetCnav2PagesEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetCnav2PagesEnabled);
} // namespace Cmd
} // namespace Sdx
