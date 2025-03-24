#pragma once

#include <memory>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Enable (or disable) OSNMA for each Galileo's satellite individually.
///
/// Name    Type       Description
/// ------- ----------
/// -------------------------------------------------------------------------------------------------------------
/// Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second
/// SV ID, etc).
///

class EnableOsnmaForEachSV;
typedef std::shared_ptr<EnableOsnmaForEachSV> EnableOsnmaForEachSVPtr;

class EnableOsnmaForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableOsnmaForEachSV";
  inline static const char* const Documentation =
    "Enable (or disable) OSNMA for each Galileo's satellite individually.\n"
    "\n"
    "Name    Type       Description\n"
    "------- ---------- -------------------------------------------------------------------------------------------------------------\n"
    "Enabled array bool OSNMA is enabled when value is True. Zero based index (index 0 => first SV ID, index 1 => second SV ID, etc).";
  inline static const char* const TargetId = "";

  EnableOsnmaForEachSV() : CommandBase(CmdName, TargetId) {}

  EnableOsnmaForEachSV(const std::vector<bool>& enabled) : CommandBase(CmdName, TargetId) { setEnabled(enabled); }

  static EnableOsnmaForEachSVPtr create(const std::vector<bool>& enabled)
  {
    return std::make_shared<EnableOsnmaForEachSV>(enabled);
  }

  static EnableOsnmaForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableOsnmaForEachSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<bool>>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::vector<bool> enabled() const { return parse_json<std::vector<bool>>::parse(m_values["Enabled"]); }

  void setEnabled(const std::vector<bool>& enabled)
  {
    m_values.AddMember("Enabled",
                       parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableOsnmaForEachSV);
} // namespace Cmd
} // namespace Sdx
