#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get Skydel's Data Folder. The user can changed it in the GUI's Preferences.
///
///
///

class GetDataFolder;
typedef std::shared_ptr<GetDataFolder> GetDataFolderPtr;

class GetDataFolder : public CommandBase
{
public:
  inline static const char* const CmdName = "GetDataFolder";
  inline static const char* const Documentation =
    "Get Skydel's Data Folder. The user can changed it in the GUI's Preferences.";
  inline static const char* const TargetId = "";

  GetDataFolder() : CommandBase(CmdName, TargetId) {}

  static GetDataFolderPtr create() { return std::make_shared<GetDataFolder>(); }

  static GetDataFolderPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetDataFolder>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }
};
REGISTER_COMMAND_TO_FACTORY(GetDataFolder);
} // namespace Cmd
} // namespace Sdx
