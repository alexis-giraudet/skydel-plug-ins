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
/// Get infos about the BeiDou D1 NAV message modification with this ID.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Unique identifier of the event
///

class GetMessageModificationToBeiDouD1Nav;
typedef std::shared_ptr<GetMessageModificationToBeiDouD1Nav> GetMessageModificationToBeiDouD1NavPtr;

class GetMessageModificationToBeiDouD1Nav : public CommandBase
{
public:
  inline static const char* const CmdName = "GetMessageModificationToBeiDouD1Nav";
  inline static const char* const Documentation =
    "Get infos about the BeiDou D1 NAV message modification with this ID.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Unique identifier of the event";
  inline static const char* const TargetId = "";

  GetMessageModificationToBeiDouD1Nav() : CommandBase(CmdName, TargetId) {}

  GetMessageModificationToBeiDouD1Nav(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetMessageModificationToBeiDouD1NavPtr create(const std::string& id)
  {
    return std::make_shared<GetMessageModificationToBeiDouD1Nav>(id);
  }

  static GetMessageModificationToBeiDouD1NavPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMessageModificationToBeiDouD1Nav>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetMessageModificationToBeiDouD1Nav);
} // namespace Cmd
} // namespace Sdx
