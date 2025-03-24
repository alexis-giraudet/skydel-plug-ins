#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Apply integrity flag for a SBAS satellite
///
/// Name   Type Description
/// ------ ---- ----------------------------
/// SvId   int  The satellite's SV ID
/// Health bool The integrity unhealthy flag
///

class SetSbasIntegrityHealthForSV;
typedef std::shared_ptr<SetSbasIntegrityHealthForSV> SetSbasIntegrityHealthForSVPtr;

class SetSbasIntegrityHealthForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSbasIntegrityHealthForSV";
  inline static const char* const Documentation = "Apply integrity flag for a SBAS satellite\n"
                                                  "\n"
                                                  "Name   Type Description\n"
                                                  "------ ---- ----------------------------\n"
                                                  "SvId   int  The satellite's SV ID\n"
                                                  "Health bool The integrity unhealthy flag";
  inline static const char* const TargetId = "";

  SetSbasIntegrityHealthForSV() : CommandBase(CmdName, TargetId) {}

  SetSbasIntegrityHealthForSV(int svId, bool health) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
  }

  static SetSbasIntegrityHealthForSVPtr create(int svId, bool health)
  {
    return std::make_shared<SetSbasIntegrityHealthForSV>(svId, health);
  }

  static SetSbasIntegrityHealthForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSbasIntegrityHealthForSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetSbasIntegrityHealthForSV);
} // namespace Cmd
} // namespace Sdx
