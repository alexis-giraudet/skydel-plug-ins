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
/// Set whether the transmitter should keep the modifications done during the simulation.
///
/// Name        Type   Description
/// ----------- ------ ------------------------------------------------------
/// Persistence bool   True to keep the modifications, false to discard them.
/// Id          string Transmitter unique identifier.
///

class SetIntTxPersistence;
typedef std::shared_ptr<SetIntTxPersistence> SetIntTxPersistencePtr;

class SetIntTxPersistence : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIntTxPersistence";
  inline static const char* const Documentation =
    "Set whether the transmitter should keep the modifications done during the simulation.\n"
    "\n"
    "Name        Type   Description\n"
    "----------- ------ ------------------------------------------------------\n"
    "Persistence bool   True to keep the modifications, false to discard them.\n"
    "Id          string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetIntTxPersistence() : CommandBase(CmdName, TargetId) {}

  SetIntTxPersistence(bool persistence, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setPersistence(persistence);
    setId(id);
  }

  static SetIntTxPersistencePtr create(bool persistence, const std::string& id)
  {
    return std::make_shared<SetIntTxPersistence>(persistence, id);
  }

  static SetIntTxPersistencePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIntTxPersistence>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Persistence"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Persistence", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  bool persistence() const { return parse_json<bool>::parse(m_values["Persistence"]); }

  void setPersistence(bool persistence)
  {
    m_values.AddMember("Persistence",
                       parse_json<bool>::format(persistence, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetIntTxPersistence);
} // namespace Cmd
} // namespace Sdx
