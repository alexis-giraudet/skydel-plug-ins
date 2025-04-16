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
/// This command completes the track started with the BeginSpoofTxTrackDefinition command. If
/// the track is accepted, the current track in the configuration is replaced with
/// this new track. If the track is not accepted, the current track in the config
/// remains unchanged.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class EndSpoofTxTrackDefinition;
typedef std::shared_ptr<EndSpoofTxTrackDefinition> EndSpoofTxTrackDefinitionPtr;

class EndSpoofTxTrackDefinition : public CommandBase
{
public:
  inline static const char* const CmdName = "EndSpoofTxTrackDefinition";
  inline static const char* const Documentation =
    "This command completes the track started with the BeginSpoofTxTrackDefinition command. If\n"
    "the track is accepted, the current track in the configuration is replaced with\n"
    "this new track. If the track is not accepted, the current track in the config\n"
    "remains unchanged.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  EndSpoofTxTrackDefinition() : CommandBase(CmdName, TargetId) {}

  EndSpoofTxTrackDefinition(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static EndSpoofTxTrackDefinitionPtr create(const std::string& id)
  {
    return std::make_shared<EndSpoofTxTrackDefinition>(id);
  }

  static EndSpoofTxTrackDefinitionPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EndSpoofTxTrackDefinition>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(EndSpoofTxTrackDefinition);
} // namespace Cmd
} // namespace Sdx
