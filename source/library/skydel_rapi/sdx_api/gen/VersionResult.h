#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetVersion.
///
/// Name    Type   Description
/// ------- ------ --------------
/// Version string Skydel version
///

class VersionResult;
typedef std::shared_ptr<VersionResult> VersionResultPtr;

class VersionResult : public CommandResult
{
public:
  inline static const char* const CmdName = "VersionResult";
  inline static const char* const Documentation = "Result of GetVersion.\n"
                                                  "\n"
                                                  "Name    Type   Description\n"
                                                  "------- ------ --------------\n"
                                                  "Version string Skydel version";
  inline static const char* const TargetId = "";

  VersionResult() : CommandResult(CmdName, TargetId) {}

  VersionResult(const std::string& version) : CommandResult(CmdName, TargetId) { setVersion(version); }

  VersionResult(CommandBasePtr relatedCommand, const std::string& version) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setVersion(version);
  }

  static VersionResultPtr create(const std::string& version) { return std::make_shared<VersionResult>(version); }

  static VersionResultPtr create(CommandBasePtr relatedCommand, const std::string& version)
  {
    return std::make_shared<VersionResult>(relatedCommand, version);
  }

  static VersionResultPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<VersionResult>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Version"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Version"};
    return names;
  }

  std::string version() const { return parse_json<std::string>::parse(m_values["Version"]); }

  void setVersion(const std::string& version)
  {
    m_values.AddMember("Version",
                       parse_json<std::string>::format(version, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(VersionResult);
} // namespace Cmd
} // namespace Sdx
