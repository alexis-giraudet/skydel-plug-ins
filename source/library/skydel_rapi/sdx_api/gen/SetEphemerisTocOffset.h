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
/// Set the ephemeris TOC offset in seconds relative to the ephemeris update time.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------
/// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// Offset int    Offset in sec. Accepted range is [-604800..604800].
///

class SetEphemerisTocOffset;
typedef std::shared_ptr<SetEphemerisTocOffset> SetEphemerisTocOffsetPtr;

class SetEphemerisTocOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "SetEphemerisTocOffset";
  inline static const char* const Documentation =
    "Set the ephemeris TOC offset in seconds relative to the ephemeris update time.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------\n"
    "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Offset int    Offset in sec. Accepted range is [-604800..604800].";
  inline static const char* const TargetId = "";

  SetEphemerisTocOffset() : CommandBase(CmdName, TargetId) {}

  SetEphemerisTocOffset(const std::string& system, int offset) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setOffset(offset);
  }

  static SetEphemerisTocOffsetPtr create(const std::string& system, int offset)
  {
    return std::make_shared<SetEphemerisTocOffset>(system, offset);
  }

  static SetEphemerisTocOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetEphemerisTocOffset>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetEphemerisTocOffset);
} // namespace Cmd
} // namespace Sdx
