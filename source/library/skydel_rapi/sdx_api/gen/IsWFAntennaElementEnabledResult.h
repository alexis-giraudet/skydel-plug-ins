#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsWFAntennaElementEnabled.
///
/// Name    Type Description
/// ------- ---- -------------------------------------------------
/// Element int  One-based index for element in antenna.
/// Enabled bool If True, this antenna element will bil simulated.
///

class IsWFAntennaElementEnabledResult;
typedef std::shared_ptr<IsWFAntennaElementEnabledResult> IsWFAntennaElementEnabledResultPtr;

class IsWFAntennaElementEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsWFAntennaElementEnabledResult";
  inline static const char* const Documentation = "Result of IsWFAntennaElementEnabled.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- -------------------------------------------------\n"
                                                  "Element int  One-based index for element in antenna.\n"
                                                  "Enabled bool If True, this antenna element will bil simulated.";
  inline static const char* const TargetId = "";

  IsWFAntennaElementEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsWFAntennaElementEnabledResult(int element, bool enabled) : CommandResult(CmdName, TargetId)
  {

    setElement(element);
    setEnabled(enabled);
  }

  IsWFAntennaElementEnabledResult(CommandBasePtr relatedCommand, int element, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setElement(element);
    setEnabled(enabled);
  }

  static IsWFAntennaElementEnabledResultPtr create(int element, bool enabled)
  {
    return std::make_shared<IsWFAntennaElementEnabledResult>(element, enabled);
  }

  static IsWFAntennaElementEnabledResultPtr create(CommandBasePtr relatedCommand, int element, bool enabled)
  {
    return std::make_shared<IsWFAntennaElementEnabledResult>(relatedCommand, element, enabled);
  }

  static IsWFAntennaElementEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsWFAntennaElementEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsWFAntennaElementEnabledResult);
} // namespace Cmd
} // namespace Sdx
