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
/// Get Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is
/// visible.
///
/// Name   Type   Description
/// ------ ------ --------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
///

class IsLOSEnabledForEachSV;
typedef std::shared_ptr<IsLOSEnabledForEachSV> IsLOSEnabledForEachSVPtr;

class IsLOSEnabledForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsLOSEnabledForEachSV";
  inline static const char* const Documentation =
    "Get Direct Line Of Sight signal from satellite disabled or enabled. Generally used when only multipaths signal is visible.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ --------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  IsLOSEnabledForEachSV() : CommandBase(CmdName, TargetId) {}

  IsLOSEnabledForEachSV(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static IsLOSEnabledForEachSVPtr create(const std::string& system)
  {
    return std::make_shared<IsLOSEnabledForEachSV>(system);
  }

  static IsLOSEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLOSEnabledForEachSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsLOSEnabledForEachSV);
} // namespace Cmd
} // namespace Sdx
