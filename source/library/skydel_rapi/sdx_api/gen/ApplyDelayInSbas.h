#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set whether the ionospheric offsets grid should be used for SBAS corrections in message 26
///
/// Name      Type Description
/// --------- ---- --------------------------------------------
/// IsEnabled bool True if offsets are applied in Sbas messages
///

class ApplyDelayInSbas;
typedef std::shared_ptr<ApplyDelayInSbas> ApplyDelayInSbasPtr;

class ApplyDelayInSbas : public CommandBase
{
public:
  inline static const char* const CmdName = "ApplyDelayInSbas";
  inline static const char* const Documentation =
    "Set whether the ionospheric offsets grid should be used for SBAS corrections in message 26\n"
    "\n"
    "Name      Type Description\n"
    "--------- ---- --------------------------------------------\n"
    "IsEnabled bool True if offsets are applied in Sbas messages";
  inline static const char* const TargetId = "";

  ApplyDelayInSbas() : CommandBase(CmdName, TargetId) {}

  ApplyDelayInSbas(bool isEnabled) : CommandBase(CmdName, TargetId) { setIsEnabled(isEnabled); }

  static ApplyDelayInSbasPtr create(bool isEnabled) { return std::make_shared<ApplyDelayInSbas>(isEnabled); }

  static ApplyDelayInSbasPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ApplyDelayInSbas>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["IsEnabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"IsEnabled"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  bool isEnabled() const { return parse_json<bool>::parse(m_values["IsEnabled"]); }

  void setIsEnabled(bool isEnabled)
  {
    m_values.AddMember("IsEnabled",
                       parse_json<bool>::format(isEnabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ApplyDelayInSbas);
} // namespace Cmd
} // namespace Sdx
