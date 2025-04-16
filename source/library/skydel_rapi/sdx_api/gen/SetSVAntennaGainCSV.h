#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set space vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic SV
/// Antenna.
///
/// Name     Type               Description
/// -------- ------------------
/// ------------------------------------------------------------------------------------------------------------------
/// FilePath string             File path of the CSV. For Default and None type, lets it empty. See formats in user
/// manual part 8.7.9.2.1. Models. Type     AntennaPatternType Pattern type Band     GNSSBand           Frequency band
/// System   string             "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// Name     optional string    Vehicle antenna name
///

class SetSVAntennaGainCSV;
typedef std::shared_ptr<SetSVAntennaGainCSV> SetSVAntennaGainCSVPtr;

class SetSVAntennaGainCSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSVAntennaGainCSV";
  inline static const char* const Documentation =
    "Set space vehicle gain antenna pattern from a CSV file. If no name is specified, the command is aplied to Basic SV Antenna.\n"
    "\n"
    "Name     Type               Description\n"
    "-------- ------------------ ------------------------------------------------------------------------------------------------------------------\n"
    "FilePath string             File path of the CSV. For Default and None type, lets it empty. See formats in user manual part 8.7.9.2.1. Models.\n"
    "Type     AntennaPatternType Pattern type\n"
    "Band     GNSSBand           Frequency band\n"
    "System   string             \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Name     optional string    Vehicle antenna name";
  inline static const char* const TargetId = "";

  SetSVAntennaGainCSV() : CommandBase(CmdName, TargetId) {}

  SetSVAntennaGainCSV(const std::string& filePath,
                      const Sdx::AntennaPatternType& type,
                      const Sdx::GNSSBand& band,
                      const std::string& system,
                      const std::optional<std::string>& name = {}) :
    CommandBase(CmdName, TargetId)
  {

    setFilePath(filePath);
    setType(type);
    setBand(band);
    setSystem(system);
    setName(name);
  }

  static SetSVAntennaGainCSVPtr create(const std::string& filePath,
                                       const Sdx::AntennaPatternType& type,
                                       const Sdx::GNSSBand& band,
                                       const std::string& system,
                                       const std::optional<std::string>& name = {})
  {
    return std::make_shared<SetSVAntennaGainCSV>(filePath, type, band, system, name);
  }

  static SetSVAntennaGainCSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSVAntennaGainCSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["FilePath"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"]) &&
           parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"]) &&
           parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"FilePath", "Type", "Band", "System", "Name"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string filePath() const { return parse_json<std::string>::parse(m_values["FilePath"]); }

  void setFilePath(const std::string& filePath)
  {
    m_values.AddMember("FilePath",
                       parse_json<std::string>::format(filePath, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType type() const { return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]); }

  void setType(const Sdx::AntennaPatternType& type)
  {
    m_values.AddMember("Type",
                       parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()),
                       m_values.GetAllocator());
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

  std::optional<std::string> name() const { return parse_json<std::optional<std::string>>::parse(m_values["Name"]); }

  void setName(const std::optional<std::string>& name)
  {
    m_values.AddMember("Name",
                       parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSVAntennaGainCSV);
} // namespace Cmd
} // namespace Sdx
