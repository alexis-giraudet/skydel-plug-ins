#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetUdreiForEachSV.
///
/// Name   Type      Description
/// ------ ---------
/// --------------------------------------------------------------------------------------------------------------------------
/// System string    "GPS" or "SBAS".
/// Udreis array int UDREI value to set for each satellite. Zero based index (index 0 => UDREI for SV ID 1, index 1 =>
/// UDREI for SV ID 2, etc).
///

class GetUdreiForEachSVResult;
typedef std::shared_ptr<GetUdreiForEachSVResult> GetUdreiForEachSVResultPtr;

class GetUdreiForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetUdreiForEachSVResult";
  inline static const char* const Documentation =
    "Result of GetUdreiForEachSV.\n"
    "\n"
    "Name   Type      Description\n"
    "------ --------- --------------------------------------------------------------------------------------------------------------------------\n"
    "System string    \"GPS\" or \"SBAS\".\n"
    "Udreis array int UDREI value to set for each satellite. Zero based index (index 0 => UDREI for SV ID 1, index 1 => UDREI for SV ID 2, etc).";
  inline static const char* const TargetId = "";

  GetUdreiForEachSVResult() : CommandResult(CmdName, TargetId) {}

  GetUdreiForEachSVResult(const std::string& system, const std::vector<int>& udreis) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setUdreis(udreis);
  }

  GetUdreiForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& udreis) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setUdreis(udreis);
  }

  static GetUdreiForEachSVResultPtr create(const std::string& system, const std::vector<int>& udreis)
  {
    return std::make_shared<GetUdreiForEachSVResult>(system, udreis);
  }

  static GetUdreiForEachSVResultPtr create(CommandBasePtr relatedCommand,
                                           const std::string& system,
                                           const std::vector<int>& udreis)
  {
    return std::make_shared<GetUdreiForEachSVResult>(relatedCommand, system, udreis);
  }

  static GetUdreiForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetUdreiForEachSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["Udreis"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Udreis"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<int> udreis() const { return parse_json<std::vector<int>>::parse(m_values["Udreis"]); }

  void setUdreis(const std::vector<int>& udreis)
  {
    m_values.AddMember("Udreis",
                       parse_json<std::vector<int>>::format(udreis, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetUdreiForEachSVResult);
} // namespace Cmd
} // namespace Sdx
