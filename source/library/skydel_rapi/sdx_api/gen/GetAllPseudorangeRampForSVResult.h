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
/// Result of GetAllPseudorangeRampForSV.
///
/// Name   Type         Description
/// ------ ------------ --------------------------------------------------------------------------
/// System string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId   int          The satellite's SV ID.
/// Ids    array string List of all the pseudorange ramps IDs for this system's satellite.
///

class GetAllPseudorangeRampForSVResult;
typedef std::shared_ptr<GetAllPseudorangeRampForSVResult> GetAllPseudorangeRampForSVResultPtr;

class GetAllPseudorangeRampForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllPseudorangeRampForSVResult";
  inline static const char* const Documentation =
    "Result of GetAllPseudorangeRampForSV.\n"
    "\n"
    "Name   Type         Description\n"
    "------ ------------ --------------------------------------------------------------------------\n"
    "System string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId   int          The satellite's SV ID.\n"
    "Ids    array string List of all the pseudorange ramps IDs for this system's satellite.";
  inline static const char* const TargetId = "";

  GetAllPseudorangeRampForSVResult() : CommandResult(CmdName, TargetId) {}

  GetAllPseudorangeRampForSVResult(const std::string& system, int svId, const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setIds(ids);
  }

  GetAllPseudorangeRampForSVResult(CommandBasePtr relatedCommand,
                                   const std::string& system,
                                   int svId,
                                   const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setIds(ids);
  }

  static GetAllPseudorangeRampForSVResultPtr create(const std::string& system,
                                                    int svId,
                                                    const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllPseudorangeRampForSVResult>(system, svId, ids);
  }

  static GetAllPseudorangeRampForSVResultPtr create(CommandBasePtr relatedCommand,
                                                    const std::string& system,
                                                    int svId,
                                                    const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllPseudorangeRampForSVResult>(relatedCommand, system, svId, ids);
  }

  static GetAllPseudorangeRampForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllPseudorangeRampForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::vector<std::string>>::is_valid(m_values["Ids"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "Ids"};
    return names;
  }

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

  std::vector<std::string> ids() const { return parse_json<std::vector<std::string>>::parse(m_values["Ids"]); }

  void setIds(const std::vector<std::string>& ids)
  {
    m_values.AddMember("Ids",
                       parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetAllPseudorangeRampForSVResult);
} // namespace Cmd
} // namespace Sdx
