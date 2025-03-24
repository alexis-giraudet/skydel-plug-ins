#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Clear automate page.
///
///
///

class ClearAutomatePage;
typedef std::shared_ptr<ClearAutomatePage> ClearAutomatePagePtr;

class ClearAutomatePage : public CommandBase
{
public:
  inline static const char* const CmdName = "ClearAutomatePage";
  inline static const char* const Documentation = "Clear automate page.";
  inline static const char* const TargetId = "";

  ClearAutomatePage() : CommandBase(CmdName, TargetId) {}

  static ClearAutomatePagePtr create() { return std::make_shared<ClearAutomatePage>(); }

  static ClearAutomatePagePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ClearAutomatePage>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(ClearAutomatePage);
} // namespace Cmd
} // namespace Sdx
