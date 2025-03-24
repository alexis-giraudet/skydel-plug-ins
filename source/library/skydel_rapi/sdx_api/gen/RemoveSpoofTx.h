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
/// Removes the spoofer transmitter. See EnableSpoofTx if all you want is to
/// disable the interference temporarily.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class RemoveSpoofTx;
typedef std::shared_ptr<RemoveSpoofTx> RemoveSpoofTxPtr;

class RemoveSpoofTx : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveSpoofTx";
  inline static const char* const Documentation =
    "Removes the spoofer transmitter. See EnableSpoofTx if all you want is to\n"
    "disable the interference temporarily.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  RemoveSpoofTx() : CommandBase(CmdName, TargetId) {}

  RemoveSpoofTx(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static RemoveSpoofTxPtr create(const std::string& id) { return std::make_shared<RemoveSpoofTx>(id); }

  static RemoveSpoofTxPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<RemoveSpoofTx>(ptr); }

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
REGISTER_COMMAND_TO_FACTORY(RemoveSpoofTx);
} // namespace Cmd
} // namespace Sdx
