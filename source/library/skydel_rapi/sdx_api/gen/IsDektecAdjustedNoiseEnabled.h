#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Indicates if noise level adjustment for Advanced Jammers on Dektec is enabled.
///
///
///

class IsDektecAdjustedNoiseEnabled;
typedef std::shared_ptr<IsDektecAdjustedNoiseEnabled> IsDektecAdjustedNoiseEnabledPtr;

class IsDektecAdjustedNoiseEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsDektecAdjustedNoiseEnabled";
  inline static const char* const Documentation =
    "Indicates if noise level adjustment for Advanced Jammers on Dektec is enabled.";
  inline static const char* const TargetId = "";

  IsDektecAdjustedNoiseEnabled() : CommandBase(CmdName, TargetId) {}

  static IsDektecAdjustedNoiseEnabledPtr create() { return std::make_shared<IsDektecAdjustedNoiseEnabled>(); }

  static IsDektecAdjustedNoiseEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsDektecAdjustedNoiseEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsDektecAdjustedNoiseEnabled);
} // namespace Cmd
} // namespace Sdx
