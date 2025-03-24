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
/// Get Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is
/// visible.
///
/// Name   Type   Description
/// ------ ------ --------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId   int    The satellite's SV ID
///

class IsLosEnabledForSV;
typedef std::shared_ptr<IsLosEnabledForSV> IsLosEnabledForSVPtr;

class IsLosEnabledForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsLosEnabledForSV";
  inline static const char* const Documentation =
    "Get Direct Line Of Sight signal from satellite enabled or disabled. Generally used when only multipaths signal is visible.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ --------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId   int    The satellite's SV ID";
  inline static const char* const TargetId = "";

  IsLosEnabledForSV() : CommandBase(CmdName, TargetId) {}

  IsLosEnabledForSV(const std::string& system, int svId) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
  }

  static IsLosEnabledForSVPtr create(const std::string& system, int svId)
  {
    return std::make_shared<IsLosEnabledForSV>(system, svId);
  }

  static IsLosEnabledForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsLosEnabledForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId"};
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

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsLosEnabledForSV);
} // namespace Cmd
} // namespace Sdx
