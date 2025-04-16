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
/// Result of GetVisibleSV.
///
/// Name   Type      Description
/// ------ --------- ---------------------------------------------------------------------------------------------
/// System string    The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId   array int A list containing the visible satellites' SV IDs
///

class GetVisibleSVResult;
typedef std::shared_ptr<GetVisibleSVResult> GetVisibleSVResultPtr;

class GetVisibleSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVisibleSVResult";
  inline static const char* const Documentation =
    "Result of GetVisibleSV.\n"
    "\n"
    "Name   Type      Description\n"
    "------ --------- ---------------------------------------------------------------------------------------------\n"
    "System string    The system, can be \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId   array int A list containing the visible satellites' SV IDs";
  inline static const char* const TargetId = "";

  GetVisibleSVResult() : CommandResult(CmdName, TargetId) {}

  GetVisibleSVResult(const std::string& system, const std::vector<int>& svId) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
  }

  GetVisibleSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& svId) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
  }

  static GetVisibleSVResultPtr create(const std::string& system, const std::vector<int>& svId)
  {
    return std::make_shared<GetVisibleSVResult>(system, svId);
  }

  static GetVisibleSVResultPtr create(CommandBasePtr relatedCommand,
                                      const std::string& system,
                                      const std::vector<int>& svId)
  {
    return std::make_shared<GetVisibleSVResult>(relatedCommand, system, svId);
  }

  static GetVisibleSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVisibleSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["SvId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<int> svId() const { return parse_json<std::vector<int>>::parse(m_values["SvId"]); }

  void setSvId(const std::vector<int>& svId)
  {
    m_values.AddMember("SvId",
                       parse_json<std::vector<int>>::format(svId, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVisibleSVResult);
} // namespace Cmd
} // namespace Sdx
