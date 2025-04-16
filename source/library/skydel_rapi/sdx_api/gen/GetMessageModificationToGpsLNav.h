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
/// Get infos about the GPS LNAV message modification with this ID.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Unique identifier of the event
///

class GetMessageModificationToGpsLNav;
typedef std::shared_ptr<GetMessageModificationToGpsLNav> GetMessageModificationToGpsLNavPtr;

class GetMessageModificationToGpsLNav : public CommandBase
{
public:
  inline static const char* const CmdName = "GetMessageModificationToGpsLNav";
  inline static const char* const Documentation = "Get infos about the GPS LNAV message modification with this ID.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ------------------------------\n"
                                                  "Id   string Unique identifier of the event";
  inline static const char* const TargetId = "";

  GetMessageModificationToGpsLNav() : CommandBase(CmdName, TargetId) {}

  GetMessageModificationToGpsLNav(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetMessageModificationToGpsLNavPtr create(const std::string& id)
  {
    return std::make_shared<GetMessageModificationToGpsLNav>(id);
  }

  static GetMessageModificationToGpsLNavPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMessageModificationToGpsLNav>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMessageModificationToGpsLNav);
} // namespace Cmd
} // namespace Sdx
