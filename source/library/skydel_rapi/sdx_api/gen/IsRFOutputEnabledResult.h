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
/// Result of IsRFOutputEnabled.
///
/// Name    Type   Description
/// ------- ------ --------------------------------------------------------------------------
/// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId    int    The satellite's SV ID
/// Enabled bool   RF is enabled when value is True
///

class IsRFOutputEnabledResult;
typedef std::shared_ptr<IsRFOutputEnabledResult> IsRFOutputEnabledResultPtr;

class IsRFOutputEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsRFOutputEnabledResult";
  inline static const char* const Documentation =
    "Result of IsRFOutputEnabled.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------\n"
    "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId    int    The satellite's SV ID\n"
    "Enabled bool   RF is enabled when value is True";
  inline static const char* const TargetId = "";

  IsRFOutputEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsRFOutputEnabledResult(const std::string& system, int svId, bool enabled) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setEnabled(enabled);
  }

  IsRFOutputEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setEnabled(enabled);
  }

  static IsRFOutputEnabledResultPtr create(const std::string& system, int svId, bool enabled)
  {
    return std::make_shared<IsRFOutputEnabledResult>(system, svId, enabled);
  }

  static IsRFOutputEnabledResultPtr create(CommandBasePtr relatedCommand,
                                           const std::string& system,
                                           int svId,
                                           bool enabled)
  {
    return std::make_shared<IsRFOutputEnabledResult>(relatedCommand, system, svId, enabled);
  }

  static IsRFOutputEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsRFOutputEnabledResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "Enabled"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsRFOutputEnabledResult);
} // namespace Cmd
} // namespace Sdx
