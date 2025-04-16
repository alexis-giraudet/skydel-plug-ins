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
/// Removes a multipath signal.
///
/// Name Type   Description
/// ---- ------ ----------------------------------------------------
/// Id   string Unique identifier of the multipath signal to remove.
///

class RemoveMultipath;
typedef std::shared_ptr<RemoveMultipath> RemoveMultipathPtr;

class RemoveMultipath : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveMultipath";
  inline static const char* const Documentation = "Removes a multipath signal.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ----------------------------------------------------\n"
                                                  "Id   string Unique identifier of the multipath signal to remove.";
  inline static const char* const TargetId = "";

  RemoveMultipath() : CommandBase(CmdName, TargetId) {}

  RemoveMultipath(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static RemoveMultipathPtr create(const std::string& id) { return std::make_shared<RemoveMultipath>(id); }

  static RemoveMultipathPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<RemoveMultipath>(ptr); }

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

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RemoveMultipath);
} // namespace Cmd
} // namespace Sdx
