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
/// Get Vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic vehicle Antenna.
///
/// Name Type            Description
/// ---- --------------- --------------------
/// Band GNSSBand        Frequency band
/// Name optional string Vehicle antenna name
///

class GetVehicleAntennaGain;
typedef std::shared_ptr<GetVehicleAntennaGain> GetVehicleAntennaGainPtr;

class GetVehicleAntennaGain : public CommandBase
{
public:
  inline static const char* const CmdName = "GetVehicleAntennaGain";
  inline static const char* const Documentation =
    "Get Vehicle gain antenna pattern. If no name is specified, the command is aplied to Basic vehicle Antenna.\n"
    "\n"
    "Name Type            Description\n"
    "---- --------------- --------------------\n"
    "Band GNSSBand        Frequency band\n"
    "Name optional string Vehicle antenna name";
  inline static const char* const TargetId = "";

  GetVehicleAntennaGain() : CommandBase(CmdName, TargetId) {}

  GetVehicleAntennaGain(const Sdx::GNSSBand& band, const std::optional<std::string>& name = {}) :
    CommandBase(CmdName, TargetId)
  {

    setBand(band);
    setName(name);
  }

  static GetVehicleAntennaGainPtr create(const Sdx::GNSSBand& band, const std::optional<std::string>& name = {})
  {
    return std::make_shared<GetVehicleAntennaGain>(band, name);
  }

  static GetVehicleAntennaGainPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleAntennaGain>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::GNSSBand>::is_valid(m_values["Band"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "Name"};
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

  std::optional<std::string> name() const { return parse_json<std::optional<std::string>>::parse(m_values["Name"]); }

  void setName(const std::optional<std::string>& name)
  {
    m_values.AddMember("Name",
                       parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaGain);
} // namespace Cmd
} // namespace Sdx
