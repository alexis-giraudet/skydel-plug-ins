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
/// Result of GetEphemerisTocOffset.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------
/// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// Offset int    Offset in sec. Accepted range is [-604800..604800].
///

class GetEphemerisTocOffsetResult;
typedef std::shared_ptr<GetEphemerisTocOffsetResult> GetEphemerisTocOffsetResultPtr;

class GetEphemerisTocOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetEphemerisTocOffsetResult";
  inline static const char* const Documentation =
    "Result of GetEphemerisTocOffset.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------\n"
    "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Offset int    Offset in sec. Accepted range is [-604800..604800].";
  inline static const char* const TargetId = "";

  GetEphemerisTocOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetEphemerisTocOffsetResult(const std::string& system, int offset) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setOffset(offset);
  }

  GetEphemerisTocOffsetResult(CommandBasePtr relatedCommand, const std::string& system, int offset) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setOffset(offset);
  }

  static GetEphemerisTocOffsetResultPtr create(const std::string& system, int offset)
  {
    return std::make_shared<GetEphemerisTocOffsetResult>(system, offset);
  }

  static GetEphemerisTocOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int offset)
  {
    return std::make_shared<GetEphemerisTocOffsetResult>(relatedCommand, system, offset);
  }

  static GetEphemerisTocOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEphemerisTocOffsetResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetEphemerisTocOffsetResult);
} // namespace Cmd
} // namespace Sdx
