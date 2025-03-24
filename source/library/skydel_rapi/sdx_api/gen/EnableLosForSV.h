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
/// Set Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is
/// visible.
///
/// Name    Type   Description
/// ------- ------ --------------------------------------------------------------------------
/// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId    int    The satellite's SV ID
/// Enabled bool   Direct Line of Sight enabled or not
///

class EnableLosForSV;
typedef std::shared_ptr<EnableLosForSV> EnableLosForSVPtr;

class EnableLosForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableLosForSV";
  inline static const char* const Documentation =
    "Set Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------\n"
    "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId    int    The satellite's SV ID\n"
    "Enabled bool   Direct Line of Sight enabled or not";
  inline static const char* const TargetId = "";

  EnableLosForSV() : CommandBase(CmdName, TargetId) {}

  EnableLosForSV(const std::string& system, int svId, bool enabled) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setEnabled(enabled);
  }

  static EnableLosForSVPtr create(const std::string& system, int svId, bool enabled)
  {
    return std::make_shared<EnableLosForSV>(system, svId, enabled);
  }

  static EnableLosForSVPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<EnableLosForSV>(ptr); }

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

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(EnableLosForSV);
} // namespace Cmd
} // namespace Sdx
