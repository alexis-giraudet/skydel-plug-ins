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
/// Import GLONASS almanac file
///
/// Name Type   Description
/// ---- ------ -----------------
/// Path string Almanac file path
///

class ImportGlonassAlmanac;
typedef std::shared_ptr<ImportGlonassAlmanac> ImportGlonassAlmanacPtr;

class ImportGlonassAlmanac : public CommandBase
{
public:
  inline static const char* const CmdName = "ImportGlonassAlmanac";
  inline static const char* const Documentation = "Import GLONASS almanac file\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ -----------------\n"
                                                  "Path string Almanac file path";
  inline static const char* const TargetId = "";

  ImportGlonassAlmanac() : CommandBase(CmdName, TargetId) {}

  ImportGlonassAlmanac(const std::string& path) : CommandBase(CmdName, TargetId) { setPath(path); }

  static ImportGlonassAlmanacPtr create(const std::string& path)
  {
    return std::make_shared<ImportGlonassAlmanac>(path);
  }

  static ImportGlonassAlmanacPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ImportGlonassAlmanac>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Path"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Path"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ImportGlonassAlmanac);
} // namespace Cmd
} // namespace Sdx
