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
/// Set the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.
///
/// Name       Type   Description
/// ---------- ------ -------------------------------------------------------------------------------------------
/// IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.
/// Id         string N310 modulation target Id.
///

class SetN310LocalOscillatorSource;
typedef std::shared_ptr<SetN310LocalOscillatorSource> SetN310LocalOscillatorSourcePtr;

class SetN310LocalOscillatorSource : public CommandBase
{
public:
  inline static const char* const CmdName = "SetN310LocalOscillatorSource";
  inline static const char* const Documentation =
    "Set the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.\n"
    "\n"
    "Name       Type   Description\n"
    "---------- ------ -------------------------------------------------------------------------------------------\n"
    "IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.\n"
    "Id         string N310 modulation target Id.";
  inline static const char* const TargetId = "";

  SetN310LocalOscillatorSource() : CommandBase(CmdName, TargetId) {}

  SetN310LocalOscillatorSource(bool isExternal, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setIsExternal(isExternal);
    setId(id);
  }

  static SetN310LocalOscillatorSourcePtr create(bool isExternal, const std::string& id)
  {
    return std::make_shared<SetN310LocalOscillatorSource>(isExternal, id);
  }

  static SetN310LocalOscillatorSourcePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetN310LocalOscillatorSource>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["IsExternal"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IsExternal", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  bool isExternal() const { return parse_json<bool>::parse(m_values["IsExternal"]); }

  void setIsExternal(bool isExternal)
  {
    m_values.AddMember("IsExternal",
                       parse_json<bool>::format(isExternal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetN310LocalOscillatorSource);
} // namespace Cmd
} // namespace Sdx
