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
/// Result of GetSVAntennaModelForEachSV.
///
/// Name              Type         Description
/// ----------------- ------------
/// ----------------------------------------------------------------------------------------------------- System string
/// "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR" AntennaModelNames array string Antenna
/// model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
///

class GetSVAntennaModelForEachSVResult;
typedef std::shared_ptr<GetSVAntennaModelForEachSVResult> GetSVAntennaModelForEachSVResultPtr;

class GetSVAntennaModelForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSVAntennaModelForEachSVResult";
  inline static const char* const Documentation =
    "Result of GetSVAntennaModelForEachSV.\n"
    "\n"
    "Name              Type         Description\n"
    "----------------- ------------ -----------------------------------------------------------------------------------------------------\n"
    "System            string       \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "AntennaModelNames array string Antenna model name for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
  inline static const char* const TargetId = "";

  GetSVAntennaModelForEachSVResult() : CommandResult(CmdName, TargetId) {}

  GetSVAntennaModelForEachSVResult(const std::string& system, const std::vector<std::string>& antennaModelNames) :
    CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setAntennaModelNames(antennaModelNames);
  }

  GetSVAntennaModelForEachSVResult(CommandBasePtr relatedCommand,
                                   const std::string& system,
                                   const std::vector<std::string>& antennaModelNames) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setAntennaModelNames(antennaModelNames);
  }

  static GetSVAntennaModelForEachSVResultPtr create(const std::string& system,
                                                    const std::vector<std::string>& antennaModelNames)
  {
    return std::make_shared<GetSVAntennaModelForEachSVResult>(system, antennaModelNames);
  }

  static GetSVAntennaModelForEachSVResultPtr create(CommandBasePtr relatedCommand,
                                                    const std::string& system,
                                                    const std::vector<std::string>& antennaModelNames)
  {
    return std::make_shared<GetSVAntennaModelForEachSVResult>(relatedCommand, system, antennaModelNames);
  }

  static GetSVAntennaModelForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSVAntennaModelForEachSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::vector<std::string>>::is_valid(m_values["AntennaModelNames"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "AntennaModelNames"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::string> antennaModelNames() const
  {
    return parse_json<std::vector<std::string>>::parse(m_values["AntennaModelNames"]);
  }

  void setAntennaModelNames(const std::vector<std::string>& antennaModelNames)
  {
    m_values.AddMember("AntennaModelNames",
                       parse_json<std::vector<std::string>>::format(antennaModelNames, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSVAntennaModelForEachSVResult);
} // namespace Cmd
} // namespace Sdx
