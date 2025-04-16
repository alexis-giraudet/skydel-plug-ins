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
/// Disable all multipath for the specified satellite.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------------------------------------------------
/// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId   int    The satellite's SV ID
/// Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)
///

class RemoveAllMultipathForSV;
typedef std::shared_ptr<RemoveAllMultipathForSV> RemoveAllMultipathForSVPtr;

class RemoveAllMultipathForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveAllMultipathForSV";
  inline static const char* const Documentation =
    "Disable all multipath for the specified satellite.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------------------------------------------\n"
    "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId   int    The satellite's SV ID\n"
    "Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)";
  inline static const char* const TargetId = "";

  RemoveAllMultipathForSV() : CommandBase(CmdName, TargetId) {}

  RemoveAllMultipathForSV(const std::string& system, int svId, bool reset) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setReset(reset);
  }

  static RemoveAllMultipathForSVPtr create(const std::string& system, int svId, bool reset)
  {
    return std::make_shared<RemoveAllMultipathForSV>(system, svId, reset);
  }

  static RemoveAllMultipathForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveAllMultipathForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<bool>::is_valid(m_values["Reset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "Reset"};
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

  bool reset() const { return parse_json<bool>::parse(m_values["Reset"]); }

  void setReset(bool reset)
  {
    m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RemoveAllMultipathForSV);
} // namespace Cmd
} // namespace Sdx
