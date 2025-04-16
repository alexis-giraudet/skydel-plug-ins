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
/// Get whether each satellite is enabled or disabled for this constellation.
///
/// Name   Type   Description
/// ------ ------
/// ----------------------------------------------------------------------------------------------------------------
/// System string The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC"
/// or "PULSAR"
///

class IsEachSVEnabled;
typedef std::shared_ptr<IsEachSVEnabled> IsEachSVEnabledPtr;

class IsEachSVEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsEachSVEnabled";
  inline static const char* const Documentation =
    "Get whether each satellite is enabled or disabled for this constellation.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ----------------------------------------------------------------------------------------------------------------\n"
    "System string The satellites' constellation. Can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  IsEachSVEnabled() : CommandBase(CmdName, TargetId) {}

  IsEachSVEnabled(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static IsEachSVEnabledPtr create(const std::string& system) { return std::make_shared<IsEachSVEnabled>(system); }

  static IsEachSVEnabledPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<IsEachSVEnabled>(ptr); }

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
REGISTER_COMMAND_TO_FACTORY(IsEachSVEnabled);
} // namespace Cmd
} // namespace Sdx
