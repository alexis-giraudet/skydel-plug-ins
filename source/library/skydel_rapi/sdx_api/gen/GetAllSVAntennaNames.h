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
/// Get a list of all space vehicle antenna names.
///
/// Name   Type   Description
/// ------ ------ --------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
///

class GetAllSVAntennaNames;
typedef std::shared_ptr<GetAllSVAntennaNames> GetAllSVAntennaNamesPtr;

class GetAllSVAntennaNames : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAllSVAntennaNames";
  inline static const char* const Documentation =
    "Get a list of all space vehicle antenna names.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ --------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  GetAllSVAntennaNames() : CommandBase(CmdName, TargetId) {}

  GetAllSVAntennaNames(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static GetAllSVAntennaNamesPtr create(const std::string& system)
  {
    return std::make_shared<GetAllSVAntennaNames>(system);
  }

  static GetAllSVAntennaNamesPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllSVAntennaNames>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System"};
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
};
REGISTER_COMMAND_TO_FACTORY(GetAllSVAntennaNames);
} // namespace Cmd
} // namespace Sdx
