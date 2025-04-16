#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set GLONASS satellite Ephemeris Health Flag Bn(ln)
///
/// Name   Type Description
/// ------ ---- --------------------------------------
/// SvId   int  The satellite's SV ID 1..24
/// Health bool Status, false = OK, true = Malfunction
///

class SetGlonassEphemerisHealthFlagForSV;
typedef std::shared_ptr<SetGlonassEphemerisHealthFlagForSV> SetGlonassEphemerisHealthFlagForSVPtr;

class SetGlonassEphemerisHealthFlagForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetGlonassEphemerisHealthFlagForSV";
  inline static const char* const Documentation = "Set GLONASS satellite Ephemeris Health Flag Bn(ln)\n"
                                                  "\n"
                                                  "Name   Type Description\n"
                                                  "------ ---- --------------------------------------\n"
                                                  "SvId   int  The satellite's SV ID 1..24\n"
                                                  "Health bool Status, false = OK, true = Malfunction";
  inline static const char* const TargetId = "";

  SetGlonassEphemerisHealthFlagForSV() : CommandBase(CmdName, TargetId) {}

  SetGlonassEphemerisHealthFlagForSV(int svId, bool health) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
  }

  static SetGlonassEphemerisHealthFlagForSVPtr create(int svId, bool health)
  {
    return std::make_shared<SetGlonassEphemerisHealthFlagForSV>(svId, health);
  }

  static SetGlonassEphemerisHealthFlagForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetGlonassEphemerisHealthFlagForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<bool>::is_valid(m_values["Health"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Health"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool health() const { return parse_json<bool>::parse(m_values["Health"]); }

  void setHealth(bool health)
  {
    m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetGlonassEphemerisHealthFlagForSV);
} // namespace Cmd
} // namespace Sdx
