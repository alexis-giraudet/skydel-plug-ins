#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Tells if OSNMA is enabled or disabled.
///
/// Name Type Description
/// ---- ---- -----------------------------------------------------------
/// SvId int  The satellite's SV ID (use 0 for all Galileo's satellites).
///

class IsOsnmaEnabledForSV;
typedef std::shared_ptr<IsOsnmaEnabledForSV> IsOsnmaEnabledForSVPtr;

class IsOsnmaEnabledForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsOsnmaEnabledForSV";
  inline static const char* const Documentation =
    "Tells if OSNMA is enabled or disabled.\n"
    "\n"
    "Name Type Description\n"
    "---- ---- -----------------------------------------------------------\n"
    "SvId int  The satellite's SV ID (use 0 for all Galileo's satellites).";
  inline static const char* const TargetId = "";

  IsOsnmaEnabledForSV() : CommandBase(CmdName, TargetId) {}

  IsOsnmaEnabledForSV(int svId) : CommandBase(CmdName, TargetId) { setSvId(svId); }

  static IsOsnmaEnabledForSVPtr create(int svId) { return std::make_shared<IsOsnmaEnabledForSV>(svId); }

  static IsOsnmaEnabledForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsOsnmaEnabledForSV>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsOsnmaEnabledForSV);
} // namespace Cmd
} // namespace Sdx
