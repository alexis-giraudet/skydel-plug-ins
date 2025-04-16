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
/// Add an offset (in db) for all values of the pattern.
///
/// Name        Type            Description
/// ----------- --------------- ------------------------------------------------------------------------------------
/// Band        GNSSBand        Offset will be apply to this band.
/// Offset      double          Power offset
/// AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna
///

class AddVehicleGainPatternOffset;
typedef std::shared_ptr<AddVehicleGainPatternOffset> AddVehicleGainPatternOffsetPtr;

class AddVehicleGainPatternOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "AddVehicleGainPatternOffset";
  inline static const char* const Documentation =
    "Add an offset (in db) for all values of the pattern.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- ------------------------------------------------------------------------------------\n"
    "Band        GNSSBand        Offset will be apply to this band.\n"
    "Offset      double          Power offset\n"
    "AntennaName optional string Vehicle antenna name. If no name is specified, apply the offset to the Basic Antenna";
  inline static const char* const TargetId = "";

  AddVehicleGainPatternOffset() : CommandBase(CmdName, TargetId) {}

  AddVehicleGainPatternOffset(const Sdx::GNSSBand& band,
                              double offset,
                              const std::optional<std::string>& antennaName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setBand(band);
    setOffset(offset);
    setAntennaName(antennaName);
  }

  static AddVehicleGainPatternOffsetPtr create(const Sdx::GNSSBand& band,
                                               double offset,
                                               const std::optional<std::string>& antennaName = {})
  {
    return std::make_shared<AddVehicleGainPatternOffset>(band, offset, antennaName);
  }

  static AddVehicleGainPatternOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<AddVehicleGainPatternOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"]) &&
           parse_json<double>::is_valid(m_values["Offset"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["AntennaName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "Offset", "AntennaName"};
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
REGISTER_COMMAND_TO_FACTORY(AddVehicleGainPatternOffset);
} // namespace Cmd
} // namespace Sdx
