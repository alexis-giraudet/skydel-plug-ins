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
/// Get an antenna change.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Unique identifier of the event
///

class GetAntennaChange;
typedef std::shared_ptr<GetAntennaChange> GetAntennaChangePtr;

class GetAntennaChange : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAntennaChange";
  inline static const char* const Documentation = "Get an antenna change.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ------------------------------\n"
                                                  "Id   string Unique identifier of the event";
  inline static const char* const TargetId = "";

  GetAntennaChange() : CommandBase(CmdName, TargetId) {}

  GetAntennaChange(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetAntennaChangePtr create(const std::string& id) { return std::make_shared<GetAntennaChange>(id); }

  static GetAntennaChangePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAntennaChange>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAntennaChange);
} // namespace Cmd
} // namespace Sdx
