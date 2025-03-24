#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Open configuration.
///
/// Name                 Type   Description
/// -------------------- ------
/// ---------------------------------------------------------------------------------------------------- Path string
/// Filename path, Automatically add file suffix if missing. If folder not defined, user default folder.
/// DiscardCurrentConfig bool   Discard current config even if it is not saved
///

class Open;
typedef std::shared_ptr<Open> OpenPtr;

class Open : public CommandBase
{
public:
  inline static const char* const CmdName = "Open";
  inline static const char* const Documentation =
    "Open configuration.\n"
    "\n"
    "Name                 Type   Description\n"
    "-------------------- ------ ----------------------------------------------------------------------------------------------------\n"
    "Path                 string Filename path, Automatically add file suffix if missing. If folder not defined, user default folder.\n"
    "DiscardCurrentConfig bool   Discard current config even if it is not saved";
  inline static const char* const TargetId = "";

  Open() : CommandBase(CmdName, TargetId) {}

  Open(const std::string& path, bool discardCurrentConfig) : CommandBase(CmdName, TargetId)
  {

    setPath(path);
    setDiscardCurrentConfig(discardCurrentConfig);
  }

  static OpenPtr create(const std::string& path, bool discardCurrentConfig)
  {
    return std::make_shared<Open>(path, discardCurrentConfig);
  }

  static OpenPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<Open>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Path"]) &&
           parse_json<bool>::is_valid(m_values["DiscardCurrentConfig"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Path", "DiscardCurrentConfig"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE; }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool discardCurrentConfig() const { return parse_json<bool>::parse(m_values["DiscardCurrentConfig"]); }

  void setDiscardCurrentConfig(bool discardCurrentConfig)
  {
    m_values.AddMember("DiscardCurrentConfig",
                       parse_json<bool>::format(discardCurrentConfig, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(Open);
} // namespace Cmd
} // namespace Sdx
