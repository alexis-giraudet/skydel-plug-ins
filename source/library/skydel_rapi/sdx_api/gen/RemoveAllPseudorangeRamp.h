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
/// Please note the command RemoveAllPseudorangeRamp is deprecated since 21.3. You may use
/// RemoveAllPseudorangeRampForSystem.
///
/// Remove all PSR Ramps for all satellites of the specified system.
///
/// Name   Type   Description
/// ------ ------ --------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
///

class RemoveAllPseudorangeRamp;
typedef std::shared_ptr<RemoveAllPseudorangeRamp> RemoveAllPseudorangeRampPtr;

class RemoveAllPseudorangeRamp : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveAllPseudorangeRamp";
  inline static const char* const Documentation =
    "Please note the command RemoveAllPseudorangeRamp is deprecated since 21.3. You may use RemoveAllPseudorangeRampForSystem.\n"
    "\n"
    "Remove all PSR Ramps for all satellites of the specified system.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ --------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  RemoveAllPseudorangeRamp() : CommandBase(CmdName, TargetId) {}

  RemoveAllPseudorangeRamp(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static RemoveAllPseudorangeRampPtr create(const std::string& system)
  {
    return std::make_shared<RemoveAllPseudorangeRamp>(system);
  }

  static RemoveAllPseudorangeRampPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveAllPseudorangeRamp>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(RemoveAllPseudorangeRamp);
} // namespace Cmd
} // namespace Sdx
