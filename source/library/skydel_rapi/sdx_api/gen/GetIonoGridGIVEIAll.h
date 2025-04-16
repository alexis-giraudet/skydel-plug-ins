#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an
/// index 1, etc.
///
/// Name            Type            Description
/// --------------- --------------- -------------------------------
/// ServiceProvider optional string The service provider (optional)
///

class GetIonoGridGIVEIAll;
typedef std::shared_ptr<GetIonoGridGIVEIAll> GetIonoGridGIVEIAllPtr;

class GetIonoGridGIVEIAll : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIonoGridGIVEIAll";
  inline static const char* const Documentation =
    "Get GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.\n"
    "\n"
    "Name            Type            Description\n"
    "--------------- --------------- -------------------------------\n"
    "ServiceProvider optional string The service provider (optional)";
  inline static const char* const TargetId = "";

  GetIonoGridGIVEIAll(const std::optional<std::string>& serviceProvider = {}) : CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
  }

  static GetIonoGridGIVEIAllPtr create(const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<GetIonoGridGIVEIAll>(serviceProvider);
  }

  static GetIonoGridGIVEIAllPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridGIVEIAll>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ServiceProvider"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::optional<std::string> serviceProvider() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
  }

  void setServiceProvider(const std::optional<std::string>& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIonoGridGIVEIAll);
} // namespace Cmd
} // namespace Sdx
