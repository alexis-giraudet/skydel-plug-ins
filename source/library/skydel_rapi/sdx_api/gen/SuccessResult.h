#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// When command succeed.
///
///
///

class SuccessResult;
typedef std::shared_ptr<SuccessResult> SuccessResultPtr;

class SuccessResult : public CommandResult
{
public:
  inline static const char* const CmdName = "SuccessResult";
  inline static const char* const Documentation = "When command succeed.";
  inline static const char* const TargetId = "";

  SuccessResult() : CommandResult(CmdName, TargetId) {}

  SuccessResult(CommandBasePtr relatedCommand) : CommandResult(CmdName, TargetId, relatedCommand) {}

  static SuccessResultPtr create(CommandBasePtr relatedCommand)
  {
    return std::make_shared<SuccessResult>(relatedCommand);
  }

  static SuccessResultPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SuccessResult>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }
};
REGISTER_COMMAND_TO_FACTORY(SuccessResult);
} // namespace Cmd
} // namespace Sdx
