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
/// Enable (or disable) RF output for specified satellite. Use SV ID 0 to enabled/disable all satellites.
///
/// Name    Type   Description
/// ------- ------ --------------------------------------------------------------------------
/// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId    int    The satellite's SV ID
/// Enabled bool   RF is enabled when value is True
///

class EnableRFOutputForSV;
typedef std::shared_ptr<EnableRFOutputForSV> EnableRFOutputForSVPtr;

class EnableRFOutputForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableRFOutputForSV";
  inline static const char* const Documentation =
    "Enable (or disable) RF output for specified satellite. Use SV ID 0 to enabled/disable all satellites.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------\n"
    "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId    int    The satellite's SV ID\n"
    "Enabled bool   RF is enabled when value is True";
  inline static const char* const TargetId = "";

  EnableRFOutputForSV() : CommandBase(CmdName, TargetId) {}

  EnableRFOutputForSV(const std::string& system, int svId, bool enabled) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setEnabled(enabled);
  }

  static EnableRFOutputForSVPtr create(const std::string& system, int svId, bool enabled)
  {
    return std::make_shared<EnableRFOutputForSV>(system, svId, enabled);
  }

  static EnableRFOutputForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableRFOutputForSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(EnableRFOutputForSV);
} // namespace Cmd
} // namespace Sdx
