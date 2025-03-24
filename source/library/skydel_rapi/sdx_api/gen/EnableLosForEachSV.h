#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is
/// visible.
///
/// Name    Type       Description
/// ------- ----------
/// ----------------------------------------------------------------------------------------------------------- System
/// string     "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR" Enabled array bool Direct Line
/// of Sight enabled or not. Zero based index (index 0 => SV ID 1, index 1 => second SV ID 2, etc).
///

class EnableLosForEachSV;
typedef std::shared_ptr<EnableLosForEachSV> EnableLosForEachSVPtr;

class EnableLosForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableLosForEachSV";
  inline static const char* const Documentation =
    "Set Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.\n"
    "\n"
    "Name    Type       Description\n"
    "------- ---------- -----------------------------------------------------------------------------------------------------------\n"
    "System  string     \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Enabled array bool Direct Line of Sight enabled or not. Zero based index (index 0 => SV ID 1, index 1 => second SV ID 2, etc).";
  inline static const char* const TargetId = "";

  EnableLosForEachSV() : CommandBase(CmdName, TargetId) {}

  EnableLosForEachSV(const std::string& system, const std::vector<bool>& enabled) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setEnabled(enabled);
  }

  static EnableLosForEachSVPtr create(const std::string& system, const std::vector<bool>& enabled)
  {
    return std::make_shared<EnableLosForEachSV>(system, enabled);
  }

  static EnableLosForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableLosForEachSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::vector<bool>>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Enabled"};
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

  std::vector<bool> enabled() const { return parse_json<std::vector<bool>>::parse(m_values["Enabled"]); }

  void setEnabled(const std::vector<bool>& enabled)
  {
    m_values.AddMember("Enabled",
                       parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableLosForEachSV);
} // namespace Cmd
} // namespace Sdx
