#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetN310LocalOscillatorSource.
///
/// Name       Type   Description
/// ---------- ------ -------------------------------------------------------------------------------------------
/// IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.
/// Id         string N310 modulation target Id.
///

class GetN310LocalOscillatorSourceResult;
typedef std::shared_ptr<GetN310LocalOscillatorSourceResult> GetN310LocalOscillatorSourceResultPtr;

class GetN310LocalOscillatorSourceResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetN310LocalOscillatorSourceResult";
  inline static const char* const Documentation =
    "Result of GetN310LocalOscillatorSource.\n"
    "\n"
    "Name       Type   Description\n"
    "---------- ------ -------------------------------------------------------------------------------------------\n"
    "IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.\n"
    "Id         string N310 modulation target Id.";
  inline static const char* const TargetId = "";

  GetN310LocalOscillatorSourceResult() : CommandResult(CmdName, TargetId) {}

  GetN310LocalOscillatorSourceResult(bool isExternal, const std::string& id) : CommandResult(CmdName, TargetId)
  {

    setIsExternal(isExternal);
    setId(id);
  }

  GetN310LocalOscillatorSourceResult(CommandBasePtr relatedCommand, bool isExternal, const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIsExternal(isExternal);
    setId(id);
  }

  static GetN310LocalOscillatorSourceResultPtr create(bool isExternal, const std::string& id)
  {
    return std::make_shared<GetN310LocalOscillatorSourceResult>(isExternal, id);
  }

  static GetN310LocalOscillatorSourceResultPtr create(CommandBasePtr relatedCommand,
                                                      bool isExternal,
                                                      const std::string& id)
  {
    return std::make_shared<GetN310LocalOscillatorSourceResult>(relatedCommand, isExternal, id);
  }

  static GetN310LocalOscillatorSourceResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetN310LocalOscillatorSourceResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetN310LocalOscillatorSourceResult);
} // namespace Cmd
} // namespace Sdx
