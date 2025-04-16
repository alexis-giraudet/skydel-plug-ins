#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"
#include "gen/GNSSBand.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.
///
/// Name        Type               Description
/// ----------- ------------------
/// ----------------------------------------------------------------------------------------------------------------------------------
/// PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90]
/// and the second dimension to azimuth [0, 360[. Type        AntennaPatternType Pattern type Band        GNSSBand
/// Frequency band Name        optional string    Vehicle antenna name
///

class SetVehicleAntennaPhaseOffset;
typedef std::shared_ptr<SetVehicleAntennaPhaseOffset> SetVehicleAntennaPhaseOffsetPtr;

class SetVehicleAntennaPhaseOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "SetVehicleAntennaPhaseOffset";
  inline static const char* const Documentation =
    "Set Vehicle phase offset antenna pattern. If no name is specified, the command is aplied to Basic Vehicle Antenna.\n"
    "\n"
    "Name        Type               Description\n"
    "----------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------\n"
    "PhaseOffset array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "Type        AntennaPatternType Pattern type\n"
    "Band        GNSSBand           Frequency band\n"
    "Name        optional string    Vehicle antenna name";
  inline static const char* const TargetId = "";

  SetVehicleAntennaPhaseOffset() : CommandBase(CmdName, TargetId) {}

  SetVehicleAntennaPhaseOffset(const std::vector<std::vector<double>>& phaseOffset,
                               const Sdx::AntennaPatternType& type,
                               const Sdx::GNSSBand& band,
                               const std::optional<std::string>& name = {}) :
    CommandBase(CmdName, TargetId)
  {

    setPhaseOffset(phaseOffset);
    setType(type);
    setBand(band);
    setName(name);
  }

  static SetVehicleAntennaPhaseOffsetPtr create(const std::vector<std::vector<double>>& phaseOffset,
                                                const Sdx::AntennaPatternType& type,
                                                const Sdx::GNSSBand& band,
                                                const std::optional<std::string>& name = {})
  {
    return std::make_shared<SetVehicleAntennaPhaseOffset>(phaseOffset, type, band, name);
  }

  static SetVehicleAntennaPhaseOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetVehicleAntennaPhaseOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffset"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"]) &&
           parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"PhaseOffset", "Type", "Band", "Name"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::vector<std::vector<double>> phaseOffset() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffset"]);
  }

  void setPhaseOffset(const std::vector<std::vector<double>>& phaseOffset)
  {
    m_values.AddMember("PhaseOffset",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffset, m_values.GetAllocator()),
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

  std::optional<std::string> name() const { return parse_json<std::optional<std::string>>::parse(m_values["Name"]); }

  void setName(const std::optional<std::string>& name)
  {
    m_values.AddMember("Name",
                       parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetVehicleAntennaPhaseOffset);
} // namespace Cmd
} // namespace Sdx
