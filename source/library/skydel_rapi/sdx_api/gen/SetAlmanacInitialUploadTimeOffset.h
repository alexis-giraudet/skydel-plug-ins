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
/// Set next almanac upload time relative to simulation start time.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------------------------------------------
/// System string Must be "GPS"
/// Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]
///

class SetAlmanacInitialUploadTimeOffset;
typedef std::shared_ptr<SetAlmanacInitialUploadTimeOffset> SetAlmanacInitialUploadTimeOffsetPtr;

class SetAlmanacInitialUploadTimeOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "SetAlmanacInitialUploadTimeOffset";
  inline static const char* const Documentation =
    "Set next almanac upload time relative to simulation start time.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------------------------------------\n"
    "System string Must be \"GPS\"\n"
    "Offset int    Next upload time in sec (relative to simulation start time). Accepted range is [30..259200]";
  inline static const char* const TargetId = "";

  SetAlmanacInitialUploadTimeOffset() : CommandBase(CmdName, TargetId) {}

  SetAlmanacInitialUploadTimeOffset(const std::string& system, int offset) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setOffset(offset);
  }

  static SetAlmanacInitialUploadTimeOffsetPtr create(const std::string& system, int offset)
  {
    return std::make_shared<SetAlmanacInitialUploadTimeOffset>(system, offset);
  }

  static SetAlmanacInitialUploadTimeOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetAlmanacInitialUploadTimeOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["Offset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Offset"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int offset() const { return parse_json<int>::parse(m_values["Offset"]); }

  void setOffset(int offset)
  {
    m_values.AddMember("Offset", parse_json<int>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetAlmanacInitialUploadTimeOffset);
} // namespace Cmd
} // namespace Sdx
