#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Import ionospheric parameters from a Rinex file.
///
/// Name Type            Description
/// ---- --------------- ------------------------------------------------------------------------------
/// Path string          File path
/// Type optional string Ionospheric parameters type: "Klobuchar" or "BDGIM". The default is Klobuchar.
///

class ImportIonoParameters;
typedef std::shared_ptr<ImportIonoParameters> ImportIonoParametersPtr;

class ImportIonoParameters : public CommandBase
{
public:
  inline static const char* const CmdName = "ImportIonoParameters";
  inline static const char* const Documentation =
    "Import ionospheric parameters from a Rinex file.\n"
    "\n"
    "Name Type            Description\n"
    "---- --------------- ------------------------------------------------------------------------------\n"
    "Path string          File path\n"
    "Type optional string Ionospheric parameters type: \"Klobuchar\" or \"BDGIM\". The default is Klobuchar.";
  inline static const char* const TargetId = "";

  ImportIonoParameters() : CommandBase(CmdName, TargetId) {}

  ImportIonoParameters(const std::string& path, const std::optional<std::string>& type = {}) :
    CommandBase(CmdName, TargetId)
  {

    setPath(path);
    setType(type);
  }

  static ImportIonoParametersPtr create(const std::string& path, const std::optional<std::string>& type = {})
  {
    return std::make_shared<ImportIonoParameters>(path, type);
  }

  static ImportIonoParametersPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ImportIonoParameters>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Path"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Type"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Path", "Type"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<std::string> type() const { return parse_json<std::optional<std::string>>::parse(m_values["Type"]); }

  void setType(const std::optional<std::string>& type)
  {
    m_values.AddMember("Type",
                       parse_json<std::optional<std::string>>::format(type, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ImportIonoParameters);
} // namespace Cmd
} // namespace Sdx
