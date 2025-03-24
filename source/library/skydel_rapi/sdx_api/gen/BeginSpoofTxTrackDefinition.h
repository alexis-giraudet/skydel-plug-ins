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
/// Begins a new spoofer transmitter track definition. Actual track remains unchanged until
/// EndSpoofTxTrackDefinition command is sent and successful. After this command, the
/// client must push time and position pairs to form a complete track. Once all the
/// positions are sent, the client must send the command EndSpoofTxTrackDefinition.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class BeginSpoofTxTrackDefinition;
typedef std::shared_ptr<BeginSpoofTxTrackDefinition> BeginSpoofTxTrackDefinitionPtr;

class BeginSpoofTxTrackDefinition : public CommandBase
{
public:
  inline static const char* const CmdName = "BeginSpoofTxTrackDefinition";
  inline static const char* const Documentation =
    "Begins a new spoofer transmitter track definition. Actual track remains unchanged until\n"
    "EndSpoofTxTrackDefinition command is sent and successful. After this command, the\n"
    "client must push time and position pairs to form a complete track. Once all the\n"
    "positions are sent, the client must send the command EndSpoofTxTrackDefinition.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  BeginSpoofTxTrackDefinition() : CommandBase(CmdName, TargetId) {}

  BeginSpoofTxTrackDefinition(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static BeginSpoofTxTrackDefinitionPtr create(const std::string& id)
  {
    return std::make_shared<BeginSpoofTxTrackDefinition>(id);
  }

  static BeginSpoofTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<BeginSpoofTxTrackDefinition>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(BeginSpoofTxTrackDefinition);
} // namespace Cmd
} // namespace Sdx
