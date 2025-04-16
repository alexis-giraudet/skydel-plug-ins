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
/// Result of GetAllSVAntennaNames.
///
/// Name         Type         Description
/// ------------ ------------ --------------------------------------------------------------------------
/// System       string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// AntennaNames array string A list of antenna model names.
///

class GetAllSVAntennaNamesResult;
typedef std::shared_ptr<GetAllSVAntennaNamesResult> GetAllSVAntennaNamesResultPtr;

class GetAllSVAntennaNamesResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllSVAntennaNamesResult";
  inline static const char* const Documentation =
    "Result of GetAllSVAntennaNames.\n"
    "\n"
    "Name         Type         Description\n"
    "------------ ------------ --------------------------------------------------------------------------\n"
    "System       string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "AntennaNames array string A list of antenna model names.";
  inline static const char* const TargetId = "";

  GetAllSVAntennaNamesResult() : CommandResult(CmdName, TargetId) {}

  GetAllSVAntennaNamesResult(const std::string& system, const std::vector<std::string>& antennaNames) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setAntennaNames(antennaNames);
  }

  GetAllSVAntennaNamesResult(CommandBasePtr relatedCommand,
                             const std::string& system,
                             const std::vector<std::string>& antennaNames) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setAntennaNames(antennaNames);
  }

  static GetAllSVAntennaNamesResultPtr create(const std::string& system, const std::vector<std::string>& antennaNames)
  {
    return std::make_shared<GetAllSVAntennaNamesResult>(system, antennaNames);
  }

  static GetAllSVAntennaNamesResultPtr create(CommandBasePtr relatedCommand,
                                              const std::string& system,
                                              const std::vector<std::string>& antennaNames)
  {
    return std::make_shared<GetAllSVAntennaNamesResult>(relatedCommand, system, antennaNames);
  }

  static GetAllSVAntennaNamesResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllSVAntennaNamesResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::vector<std::string>>::is_valid(m_values["AntennaNames"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "AntennaNames"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::string> antennaNames() const
  {
    return parse_json<std::vector<std::string>>::parse(m_values["AntennaNames"]);
  }

  void setAntennaNames(const std::vector<std::string>& antennaNames)
  {
    m_values.AddMember("AntennaNames",
                       parse_json<std::vector<std::string>>::format(antennaNames, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetAllSVAntennaNamesResult);
} // namespace Cmd
} // namespace Sdx
