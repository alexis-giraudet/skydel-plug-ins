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
/// Tells if the RF output is enabled or disabled for each satellite.
///
/// Name   Type   Description
/// ------ ------ --------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
///

class IsRFOutputEnabledForEachSV;
typedef std::shared_ptr<IsRFOutputEnabledForEachSV> IsRFOutputEnabledForEachSVPtr;

class IsRFOutputEnabledForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsRFOutputEnabledForEachSV";
  inline static const char* const Documentation =
    "Tells if the RF output is enabled or disabled for each satellite.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ --------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  IsRFOutputEnabledForEachSV() : CommandBase(CmdName, TargetId) {}

  IsRFOutputEnabledForEachSV(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static IsRFOutputEnabledForEachSVPtr create(const std::string& system)
  {
    return std::make_shared<IsRFOutputEnabledForEachSV>(system);
  }

  static IsRFOutputEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsRFOutputEnabledForEachSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsRFOutputEnabledForEachSV);
} // namespace Cmd
} // namespace Sdx
