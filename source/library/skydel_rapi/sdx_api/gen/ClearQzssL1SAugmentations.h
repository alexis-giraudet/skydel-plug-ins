#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Clears all QZSS L1S augmentations.
///
///
///

class ClearQzssL1SAugmentations;
typedef std::shared_ptr<ClearQzssL1SAugmentations> ClearQzssL1SAugmentationsPtr;

class ClearQzssL1SAugmentations : public CommandBase
{
public:
  inline static const char* const CmdName = "ClearQzssL1SAugmentations";
  inline static const char* const Documentation = "Clears all QZSS L1S augmentations.";
  inline static const char* const TargetId = "";

  ClearQzssL1SAugmentations() : CommandBase(CmdName, TargetId) {}

  static ClearQzssL1SAugmentationsPtr create() { return std::make_shared<ClearQzssL1SAugmentations>(); }

  static ClearQzssL1SAugmentationsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ClearQzssL1SAugmentations>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(ClearQzssL1SAugmentations);
} // namespace Cmd
} // namespace Sdx
