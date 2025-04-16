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
/// Get the satellite pseudorange noise Gauss-Markov process attributes.
///
/// Name    Type   Description
/// ------- ------ --------------------------------------------------------------------------
/// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId    int    Satellite SV ID.
/// Process int    Gauss-Markov Process number (0 or 1)
///

class GetPseudorangeNoiseGaussMarkovForSV;
typedef std::shared_ptr<GetPseudorangeNoiseGaussMarkovForSV> GetPseudorangeNoiseGaussMarkovForSVPtr;

class GetPseudorangeNoiseGaussMarkovForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPseudorangeNoiseGaussMarkovForSV";
  inline static const char* const Documentation =
    "Get the satellite pseudorange noise Gauss-Markov process attributes.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------\n"
    "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId    int    Satellite SV ID.\n"
    "Process int    Gauss-Markov Process number (0 or 1)";
  inline static const char* const TargetId = "";

  GetPseudorangeNoiseGaussMarkovForSV() : CommandBase(CmdName, TargetId) {}

  GetPseudorangeNoiseGaussMarkovForSV(const std::string& system, int svId, int process) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setProcess(process);
  }

  static GetPseudorangeNoiseGaussMarkovForSVPtr create(const std::string& system, int svId, int process)
  {
    return std::make_shared<GetPseudorangeNoiseGaussMarkovForSV>(system, svId, process);
  }

  static GetPseudorangeNoiseGaussMarkovForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPseudorangeNoiseGaussMarkovForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<int>::is_valid(m_values["Process"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "Process"};
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

  int process() const { return parse_json<int>::parse(m_values["Process"]); }

  void setProcess(int process)
  {
    m_values.AddMember("Process", parse_json<int>::format(process, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetPseudorangeNoiseGaussMarkovForSV);
} // namespace Cmd
} // namespace Sdx
