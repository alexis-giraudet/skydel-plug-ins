#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"
#include "gen/GNSSBand.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.
///
/// Name   Type            Description
/// ------ --------------- --------------------------------------------------------------------------
/// Band   GNSSBand        Frequency band
/// System string          "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Name   optional string SV antenna name
///

class GetSVAntennaGain;
typedef std::shared_ptr<GetSVAntennaGain> GetSVAntennaGainPtr;

class GetSVAntennaGain : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSVAntennaGain";
  inline static const char* const Documentation =
    "Get space vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic SV Antenna.\n"
    "\n"
    "Name   Type            Description\n"
    "------ --------------- --------------------------------------------------------------------------\n"
    "Band   GNSSBand        Frequency band\n"
    "System string          \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Name   optional string SV antenna name";
  inline static const char* const TargetId = "";

  GetSVAntennaGain() : CommandBase(CmdName, TargetId) {}

  GetSVAntennaGain(const Sdx::GNSSBand& band, const std::string& system, const std::optional<std::string>& name = {}) :
    CommandBase(CmdName, TargetId)
  {

    setBand(band);
    setSystem(system);
    setName(name);
  }

  static GetSVAntennaGainPtr create(const Sdx::GNSSBand& band,
                                    const std::string& system,
                                    const std::optional<std::string>& name = {})
  {
    return std::make_shared<GetSVAntennaGain>(band, system, name);
  }

  static GetSVAntennaGainPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSVAntennaGain>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"]) &&
           parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "System", "Name"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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

  std::optional<std::string> name() const { return parse_json<std::optional<std::string>>::parse(m_values["Name"]); }

  void setName(const std::optional<std::string>& name)
  {
    m_values.AddMember("Name",
                       parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSVAntennaGain);
} // namespace Cmd
} // namespace Sdx
