#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set transmitter antenna pattern.
///
/// Name Type               Description
/// ---- ------------------
/// -------------------------------------------------------------------------------------------------------------------------
/// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second
/// dimension to azimuth [0, 360[. Type AntennaPatternType Pattern type Id   string             Transmitter unique
/// identifier.
///

class SetIntTxAntenna;
typedef std::shared_ptr<SetIntTxAntenna> SetIntTxAntennaPtr;

class SetIntTxAntenna : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIntTxAntenna";
  inline static const char* const Documentation =
    "Set transmitter antenna pattern.\n"
    "\n"
    "Name Type               Description\n"
    "---- ------------------ -------------------------------------------------------------------------------------------------------------------------\n"
    "Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "Type AntennaPatternType Pattern type\n"
    "Id   string             Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  SetIntTxAntenna() : CommandBase(CmdName, TargetId) {}

  SetIntTxAntenna(const std::vector<std::vector<double>>& gain,
                  const Sdx::AntennaPatternType& type,
                  const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setGain(gain);
    setType(type);
    setId(id);
  }

  static SetIntTxAntennaPtr create(const std::vector<std::vector<double>>& gain,
                                   const Sdx::AntennaPatternType& type,
                                   const std::string& id)
  {
    return std::make_shared<SetIntTxAntenna>(gain, type, id);
  }

  static SetIntTxAntennaPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIntTxAntenna>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Gain", "Type", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::vector<std::vector<double>> gain() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
  }

  void setGain(const std::vector<std::vector<double>>& gain)
  {
    m_values.AddMember("Gain",
                       parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType type() const { return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]); }

  void setType(const Sdx::AntennaPatternType& type)
  {
    m_values.AddMember("Type",
                       parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetIntTxAntenna);
} // namespace Cmd
} // namespace Sdx
