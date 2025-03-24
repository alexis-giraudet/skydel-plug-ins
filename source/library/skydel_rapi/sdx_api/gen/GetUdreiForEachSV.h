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
/// Get the UDREI value transmitted by SBAS for all satellites of the specified constellation.
///
/// Name   Type   Description
/// ------ ------ ----------------
/// System string "GPS" or "SBAS".
///

class GetUdreiForEachSV;
typedef std::shared_ptr<GetUdreiForEachSV> GetUdreiForEachSVPtr;

class GetUdreiForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetUdreiForEachSV";
  inline static const char* const Documentation =
    "Get the UDREI value transmitted by SBAS for all satellites of the specified constellation.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ----------------\n"
    "System string \"GPS\" or \"SBAS\".";
  inline static const char* const TargetId = "";

  GetUdreiForEachSV() : CommandBase(CmdName, TargetId) {}

  GetUdreiForEachSV(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static GetUdreiForEachSVPtr create(const std::string& system) { return std::make_shared<GetUdreiForEachSV>(system); }

  static GetUdreiForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetUdreiForEachSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetUdreiForEachSV);
} // namespace Cmd
} // namespace Sdx
