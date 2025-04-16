#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Please note the command SetWFAntennaElementEnabled is deprecated since 23.11. You may use SetWFElement.
///
/// Set WF antenna element enabled or disabled. A disabled antenna element is not simulated at all.
///
/// Name    Type Description
/// ------- ---- -------------------------------------------------
/// Element int  One-based index for element in antenna.
/// Enabled bool If True, this antenna element will bil simulated.
///

class SetWFAntennaElementEnabled;
typedef std::shared_ptr<SetWFAntennaElementEnabled> SetWFAntennaElementEnabledPtr;

class SetWFAntennaElementEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "SetWFAntennaElementEnabled";
  inline static const char* const Documentation =
    "Please note the command SetWFAntennaElementEnabled is deprecated since 23.11. You may use SetWFElement.\n"
    "\n"
    "Set WF antenna element enabled or disabled. A disabled antenna element is not simulated at all.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- -------------------------------------------------\n"
    "Element int  One-based index for element in antenna.\n"
    "Enabled bool If True, this antenna element will bil simulated.";
  inline static const char* const TargetId = "";

  inline static const char* const Deprecated =
    "Please note the command SetWFAntennaElementEnabled is deprecated since 23.11. You may use SetWFElement.";

  SetWFAntennaElementEnabled() : CommandBase(CmdName, TargetId) {}

  SetWFAntennaElementEnabled(int element, bool enabled) : CommandBase(CmdName, TargetId)
  {

    setElement(element);
    setEnabled(enabled);
  }

  static SetWFAntennaElementEnabledPtr create(int element, bool enabled)
  {
    return std::make_shared<SetWFAntennaElementEnabled>(element, enabled);
  }

  static SetWFAntennaElementEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetWFAntennaElementEnabled>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Element"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Element", "Enabled"};
    return names;
  }

  std::optional<std::string> deprecated() const { return std::optional<std::string> {Deprecated}; }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int element() const { return parse_json<int>::parse(m_values["Element"]); }

  void setElement(int element)
  {
    m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetWFAntennaElementEnabled);
} // namespace Cmd
} // namespace Sdx
