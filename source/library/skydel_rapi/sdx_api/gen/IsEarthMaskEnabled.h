#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Indicates if the Earth mask is enabled.
///
///
///

class IsEarthMaskEnabled;
typedef std::shared_ptr<IsEarthMaskEnabled> IsEarthMaskEnabledPtr;

class IsEarthMaskEnabled : public CommandBase
{
public:
  inline static const char* const CmdName = "IsEarthMaskEnabled";
  inline static const char* const Documentation = "Indicates if the Earth mask is enabled.";
  inline static const char* const TargetId = "";

  IsEarthMaskEnabled() : CommandBase(CmdName, TargetId) {}

  static IsEarthMaskEnabledPtr create() { return std::make_shared<IsEarthMaskEnabled>(); }

  static IsEarthMaskEnabledPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsEarthMaskEnabled>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsEarthMaskEnabled);
} // namespace Cmd
} // namespace Sdx
