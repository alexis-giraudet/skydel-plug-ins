#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get if map is show/hide in Analysis tab.
///
///
///

class IsMapAnalysisEnabled;
typedef std::shared_ptr<IsMapAnalysisEnabled> IsMapAnalysisEnabledPtr;

class IsMapAnalysisEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsMapAnalysisEnabled";
  inline static const char* const Documentation = "Get if map is show/hide in Analysis tab.";
  inline static const char* const TargetId = "";

  IsMapAnalysisEnabled() : CommandBase(CmdName, TargetId) {}

  static IsMapAnalysisEnabledPtr create() { return std::make_shared<IsMapAnalysisEnabled>(); }

  static IsMapAnalysisEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsMapAnalysisEnabled>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(IsMapAnalysisEnabled);
} // namespace Cmd
} // namespace Sdx
