#pragma once

#include <memory>
#include <optional>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Create a new configuration.
///
/// Name                 Type          Description
/// -------------------- ------------- ----------------------------------------------
/// DiscardCurrentConfig bool          Discard current config even if it is not saved
/// LoadDefaultConfig    optional bool Apply the default configuration
///

class New;
typedef std::shared_ptr<New> NewPtr;

class New : public CommandBase
{
public:
  inline static const char* const CmdName = "New";
  inline static const char* const Documentation =
    "Create a new configuration.\n"
    "\n"
    "Name                 Type          Description\n"
    "-------------------- ------------- ----------------------------------------------\n"
    "DiscardCurrentConfig bool          Discard current config even if it is not saved\n"
    "LoadDefaultConfig    optional bool Apply the default configuration";
  inline static const char* const TargetId = "";

  New() : CommandBase(CmdName, TargetId) {}

  New(bool discardCurrentConfig, const std::optional<bool>& loadDefaultConfig = {}) : CommandBase(CmdName, TargetId)
  {

    setDiscardCurrentConfig(discardCurrentConfig);
    setLoadDefaultConfig(loadDefaultConfig);
  }

  static NewPtr create(bool discardCurrentConfig, const std::optional<bool>& loadDefaultConfig = {})
  {
    return std::make_shared<New>(discardCurrentConfig, loadDefaultConfig);
  }

  static NewPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<New>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["DiscardCurrentConfig"]) &&
           parse_json<std::optional<bool>>::is_valid(m_values["LoadDefaultConfig"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"DiscardCurrentConfig", "LoadDefaultConfig"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  bool discardCurrentConfig() const { return parse_json<bool>::parse(m_values["DiscardCurrentConfig"]); }

  void setDiscardCurrentConfig(bool discardCurrentConfig)
  {
    m_values.AddMember("DiscardCurrentConfig",
                       parse_json<bool>::format(discardCurrentConfig, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<bool> loadDefaultConfig() const
  {
    return parse_json<std::optional<bool>>::parse(m_values["LoadDefaultConfig"]);
  }

  void setLoadDefaultConfig(const std::optional<bool>& loadDefaultConfig)
  {
    m_values.AddMember("LoadDefaultConfig",
                       parse_json<std::optional<bool>>::format(loadDefaultConfig, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(New);
} // namespace Cmd
} // namespace Sdx
