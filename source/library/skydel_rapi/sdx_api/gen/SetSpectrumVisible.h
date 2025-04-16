#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set if spectrums are show/hide.
///
/// Name    Type Description
/// ------- ---- ------------------
/// Visible bool Show spectrum flag
///

class SetSpectrumVisible;
typedef std::shared_ptr<SetSpectrumVisible> SetSpectrumVisiblePtr;

class SetSpectrumVisible : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSpectrumVisible";
  inline static const char* const Documentation = "Set if spectrums are show/hide.\n"
                                                  "\n"
                                                  "Name    Type Description\n"
                                                  "------- ---- ------------------\n"
                                                  "Visible bool Show spectrum flag";
  inline static const char* const TargetId = "";

  SetSpectrumVisible() : CommandBase(CmdName, TargetId) {}

  SetSpectrumVisible(bool visible) : CommandBase(CmdName, TargetId) { setVisible(visible); }

  static SetSpectrumVisiblePtr create(bool visible) { return std::make_shared<SetSpectrumVisible>(visible); }

  static SetSpectrumVisiblePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSpectrumVisible>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Visible"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Visible"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  bool visible() const { return parse_json<bool>::parse(m_values["Visible"]); }

  void setVisible(bool visible)
  {
    m_values.AddMember("Visible", parse_json<bool>::format(visible, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSpectrumVisible);
} // namespace Cmd
} // namespace Sdx
