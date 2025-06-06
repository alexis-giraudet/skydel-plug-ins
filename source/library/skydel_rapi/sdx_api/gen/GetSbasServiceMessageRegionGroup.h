#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get infos about the SBAS service message region group at this index.
///
/// Name            Type   Description
/// --------------- ------ -----------------------------------------------------------------------
/// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
/// Id              string Unique identifier of the SBAS service message region group.
///

class GetSbasServiceMessageRegionGroup;
typedef std::shared_ptr<GetSbasServiceMessageRegionGroup> GetSbasServiceMessageRegionGroupPtr;

class GetSbasServiceMessageRegionGroup : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSbasServiceMessageRegionGroup";
  inline static const char* const Documentation =
    "Get infos about the SBAS service message region group at this index.\n"
    "\n"
    "Name            Type   Description\n"
    "--------------- ------ -----------------------------------------------------------------------\n"
    "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"
    "Id              string Unique identifier of the SBAS service message region group.";
  inline static const char* const TargetId = "";

  GetSbasServiceMessageRegionGroup() : CommandBase(CmdName, TargetId) {}

  GetSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
    setId(id);
  }

  static GetSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, const std::string& id)
  {
    return std::make_shared<GetSbasServiceMessageRegionGroup>(serviceProvider, id);
  }

  static GetSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasServiceMessageRegionGroup>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ServiceProvider"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ServiceProvider", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string serviceProvider() const { return parse_json<std::string>::parse(m_values["ServiceProvider"]); }

  void setServiceProvider(const std::string& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSbasServiceMessageRegionGroup);
} // namespace Cmd
} // namespace Sdx
