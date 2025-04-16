#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"
#include "gen/GNSSBand.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSVGainPatternOffset.
///
/// Name        Type            Description
/// ----------- --------------- ------------------------------------------------------------------------------------
/// Band        GNSSBand        Offset will be apply to this band.
/// System      string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Offset      double          Power offset
/// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
///

class GetSVGainPatternOffsetResult;
typedef std::shared_ptr<GetSVGainPatternOffsetResult> GetSVGainPatternOffsetResultPtr;

class GetSVGainPatternOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSVGainPatternOffsetResult";
  inline static const char* const Documentation =
    "Result of GetSVGainPatternOffset.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- ------------------------------------------------------------------------------------\n"
    "Band        GNSSBand        Offset will be apply to this band.\n"
    "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Offset      double          Power offset\n"
    "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
  inline static const char* const TargetId = "";

  GetSVGainPatternOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetSVGainPatternOffsetResult(const Sdx::GNSSBand& band,
                               const std::string& system,
                               double offset,
                               const std::optional<std::string>& antennaName = {}) :
    CommandResult(CmdName, TargetId)
  {

    setBand(band);
    setSystem(system);
    setOffset(offset);
    setAntennaName(antennaName);
  }

  GetSVGainPatternOffsetResult(CommandBasePtr relatedCommand,
                               const Sdx::GNSSBand& band,
                               const std::string& system,
                               double offset,
                               const std::optional<std::string>& antennaName = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setBand(band);
    setSystem(system);
    setOffset(offset);
    setAntennaName(antennaName);
  }

  static GetSVGainPatternOffsetResultPtr create(const Sdx::GNSSBand& band,
                                                const std::string& system,
                                                double offset,
                                                const std::optional<std::string>& antennaName = {})
  {
    return std::make_shared<GetSVGainPatternOffsetResult>(band, system, offset, antennaName);
  }

  static GetSVGainPatternOffsetResultPtr create(CommandBasePtr relatedCommand,
                                                const Sdx::GNSSBand& band,
                                                const std::string& system,
                                                double offset,
                                                const std::optional<std::string>& antennaName = {})
  {
    return std::make_shared<GetSVGainPatternOffsetResult>(relatedCommand, band, system, offset, antennaName);
  }

  static GetSVGainPatternOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSVGainPatternOffsetResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"]) &&
           parse_json<std::string>::is_valid(m_values["System"]) && parse_json<double>::is_valid(m_values["Offset"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "System", "Offset", "AntennaName"};
    return names;
  }

  Sdx::GNSSBand band() const { return parse_json<Sdx::GNSSBand>::parse(m_values["Band"]); }

  void setBand(const Sdx::GNSSBand& band)
  {
    m_values.AddMember("Band",
                       parse_json<Sdx::GNSSBand>::format(band, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double offset() const { return parse_json<double>::parse(m_values["Offset"]); }

  void setOffset(double offset)
  {
    m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<std::string> antennaName() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["AntennaName"]);
  }

  void setAntennaName(const std::optional<std::string>& antennaName)
  {
    m_values.AddMember("AntennaName",
                       parse_json<std::optional<std::string>>::format(antennaName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSVGainPatternOffsetResult);
} // namespace Cmd
} // namespace Sdx
