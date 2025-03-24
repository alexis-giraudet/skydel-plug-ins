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
/// Get the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.
///
/// Name Type   Description
/// ---- ------ --------------------------
/// Id   string N310 modulation target Id.
///

class GetN310LocalOscillatorSource;
typedef std::shared_ptr<GetN310LocalOscillatorSource> GetN310LocalOscillatorSourcePtr;

class GetN310LocalOscillatorSource : public CommandBase
{
public:
  inline static const char* const CmdName = "GetN310LocalOscillatorSource";
  inline static const char* const Documentation =
    "Get the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ --------------------------\n"
    "Id   string N310 modulation target Id.";
  inline static const char* const TargetId = "";

  GetN310LocalOscillatorSource() : CommandBase(CmdName, TargetId) {}

  GetN310LocalOscillatorSource(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetN310LocalOscillatorSourcePtr create(const std::string& id)
  {
    return std::make_shared<GetN310LocalOscillatorSource>(id);
  }

  static GetN310LocalOscillatorSourcePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetN310LocalOscillatorSource>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetN310LocalOscillatorSource);
} // namespace Cmd
} // namespace Sdx
