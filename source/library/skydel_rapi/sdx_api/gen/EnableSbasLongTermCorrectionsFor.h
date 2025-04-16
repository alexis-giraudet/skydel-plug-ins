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
/// Set whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.
///
/// Name      Type   Description
/// --------- ------ -------------------------------------
/// System    string As of today, only "GPS" is supported.
/// IsEnabled bool   True if corrections are enabled.
///

class EnableSbasLongTermCorrectionsFor;
typedef std::shared_ptr<EnableSbasLongTermCorrectionsFor> EnableSbasLongTermCorrectionsForPtr;

class EnableSbasLongTermCorrectionsFor : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableSbasLongTermCorrectionsFor";
  inline static const char* const Documentation =
    "Set whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ -------------------------------------\n"
    "System    string As of today, only \"GPS\" is supported.\n"
    "IsEnabled bool   True if corrections are enabled.";
  inline static const char* const TargetId = "";

  EnableSbasLongTermCorrectionsFor() : CommandBase(CmdName, TargetId) {}

  EnableSbasLongTermCorrectionsFor(const std::string& system, bool isEnabled) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setIsEnabled(isEnabled);
  }

  static EnableSbasLongTermCorrectionsForPtr create(const std::string& system, bool isEnabled)
  {
    return std::make_shared<EnableSbasLongTermCorrectionsFor>(system, isEnabled);
  }

  static EnableSbasLongTermCorrectionsForPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableSbasLongTermCorrectionsFor>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<bool>::is_valid(m_values["IsEnabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "IsEnabled"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool isEnabled() const { return parse_json<bool>::parse(m_values["IsEnabled"]); }

  void setIsEnabled(bool isEnabled)
  {
    m_values.AddMember("IsEnabled",
                       parse_json<bool>::format(isEnabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableSbasLongTermCorrectionsFor);
} // namespace Cmd
} // namespace Sdx
