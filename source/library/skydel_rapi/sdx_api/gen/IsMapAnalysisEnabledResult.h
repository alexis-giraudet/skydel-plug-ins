#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsMapAnalysisEnabled.
///
/// Name Type Description
/// ---- ---- -------------
/// Show bool Show map flag
///

class IsMapAnalysisEnabledResult;
typedef std::shared_ptr<IsMapAnalysisEnabledResult> IsMapAnalysisEnabledResultPtr;

class IsMapAnalysisEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsMapAnalysisEnabledResult";
  inline static const char* const Documentation = "Result of IsMapAnalysisEnabled.\n"
                                                  "\n"
                                                  "Name Type Description\n"
                                                  "---- ---- -------------\n"
                                                  "Show bool Show map flag";
  inline static const char* const TargetId = "";

  IsMapAnalysisEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsMapAnalysisEnabledResult(bool show) : CommandResult(CmdName, TargetId) { setShow(show); }

  IsMapAnalysisEnabledResult(CommandBasePtr relatedCommand, bool show) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setShow(show);
  }

  static IsMapAnalysisEnabledResultPtr create(bool show) { return std::make_shared<IsMapAnalysisEnabledResult>(show); }

  static IsMapAnalysisEnabledResultPtr create(CommandBasePtr relatedCommand, bool show)
  {
    return std::make_shared<IsMapAnalysisEnabledResult>(relatedCommand, show);
  }

  static IsMapAnalysisEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsMapAnalysisEnabledResult>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Show"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Show"};
    return names;
  }

  bool show() const { return parse_json<bool>::parse(m_values["Show"]); }

  void setShow(bool show)
  {
    m_values.AddMember("Show", parse_json<bool>::format(show, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsMapAnalysisEnabledResult);
} // namespace Cmd
} // namespace Sdx
