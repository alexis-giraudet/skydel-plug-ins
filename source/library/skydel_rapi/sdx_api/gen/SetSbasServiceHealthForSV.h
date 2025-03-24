#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Apply service provider for a satellite
///
/// Name   Type Description
/// ------ ---- ---------------------
/// SvId   int  The satellite's SV ID
/// Health int  The service provider
///

class SetSbasServiceHealthForSV;
typedef std::shared_ptr<SetSbasServiceHealthForSV> SetSbasServiceHealthForSVPtr;

class SetSbasServiceHealthForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSbasServiceHealthForSV";
  inline static const char* const Documentation = "Apply service provider for a satellite\n"
                                                  "\n"
                                                  "Name   Type Description\n"
                                                  "------ ---- ---------------------\n"
                                                  "SvId   int  The satellite's SV ID\n"
                                                  "Health int  The service provider";
  inline static const char* const TargetId = "";

  SetSbasServiceHealthForSV() : CommandBase(CmdName, TargetId) {}

  SetSbasServiceHealthForSV(int svId, int health) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
  }

  static SetSbasServiceHealthForSVPtr create(int svId, int health)
  {
    return std::make_shared<SetSbasServiceHealthForSV>(svId, health);
  }

  static SetSbasServiceHealthForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSbasServiceHealthForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<int>::is_valid(m_values["Health"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Health"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int health() const { return parse_json<int>::parse(m_values["Health"]); }

  void setHealth(int health)
  {
    m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSbasServiceHealthForSV);
} // namespace Cmd
} // namespace Sdx
