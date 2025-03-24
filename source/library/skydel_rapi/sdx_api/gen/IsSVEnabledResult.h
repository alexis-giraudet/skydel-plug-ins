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
/// Result of IsSVEnabled.
///
/// Name    Type   Description
/// ------- ------
/// ----------------------------------------------------------------------------------------------------------------
/// System  string The satellite's constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC"
/// or "PULSAR" SvId    int    The satellite's SV ID (use 0 for all SVs). Enabled bool   The satellite will be
/// present/absent from the constellation
///

class IsSVEnabledResult;
typedef std::shared_ptr<IsSVEnabledResult> IsSVEnabledResultPtr;

class IsSVEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsSVEnabledResult";
  inline static const char* const Documentation =
    "Result of IsSVEnabled.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ ----------------------------------------------------------------------------------------------------------------\n"
    "System  string The satellite's constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId    int    The satellite's SV ID (use 0 for all SVs).\n"
    "Enabled bool   The satellite will be present/absent from the constellation";
  inline static const char* const TargetId = "";

  IsSVEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsSVEnabledResult(const std::string& system, int svId, bool enabled) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setEnabled(enabled);
  }

  IsSVEnabledResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setEnabled(enabled);
  }

  static IsSVEnabledResultPtr create(const std::string& system, int svId, bool enabled)
  {
    return std::make_shared<IsSVEnabledResult>(system, svId, enabled);
  }

  static IsSVEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled)
  {
    return std::make_shared<IsSVEnabledResult>(relatedCommand, system, svId, enabled);
  }

  static IsSVEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSVEnabledResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsSVEnabledResult);
} // namespace Cmd
} // namespace Sdx
