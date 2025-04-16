#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set if map is show/hide in Analysis tab.
///
/// Name Type Description
/// ---- ---- -------------
/// Show bool Show map flag
///

class ShowMapAnalysis;
typedef std::shared_ptr<ShowMapAnalysis> ShowMapAnalysisPtr;

class ShowMapAnalysis : public CommandBase
{
public:
  inline static const char* const CmdName = "ShowMapAnalysis";
  inline static const char* const Documentation = "Set if map is show/hide in Analysis tab.\n"
                                                  "\n"
                                                  "Name Type Description\n"
                                                  "---- ---- -------------\n"
                                                  "Show bool Show map flag";
  inline static const char* const TargetId = "";

  ShowMapAnalysis() : CommandBase(CmdName, TargetId) {}

  ShowMapAnalysis(bool show) : CommandBase(CmdName, TargetId) { setShow(show); }

  static ShowMapAnalysisPtr create(bool show) { return std::make_shared<ShowMapAnalysis>(show); }

  static ShowMapAnalysisPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<ShowMapAnalysis>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Show"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Show"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  bool show() const { return parse_json<bool>::parse(m_values["Show"]); }

  void setShow(bool show)
  {
    m_values.AddMember("Show", parse_json<bool>::format(show, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ShowMapAnalysis);
} // namespace Cmd
} // namespace Sdx
