#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"
#include "gen/AntennaPatternType.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetVehicleAntennaModel.
///
/// Name                 Type               Description
/// -------------------- ------------------
/// ----------------------------------------------------------------------------------------------------------------------------------
/// GainL1               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90]
/// and the second dimension to azimuth [0, 360[. GainTypeL1           AntennaPatternType Pattern type GainOffsetL1
/// double             Pattern offset GainL2               array array double Gain matrix (dB). The first dimension will
/// be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[. GainTypeL2 AntennaPatternType Pattern
/// type GainOffsetL2         double             Pattern offset GainL5               array array double Gain matrix
/// (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
/// GainTypeL5           AntennaPatternType Pattern type
/// GainOffsetL5         double             Pattern offset
/// GainE6               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90]
/// and the second dimension to azimuth [0, 360[. GainTypeE6           AntennaPatternType Pattern type GainOffsetE6
/// double             Pattern offset GainS                array array double Gain matrix (dB). The first dimension will
/// be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[. GainTypeS AntennaPatternType Pattern
/// type GainOffsetS          double             Pattern offset GainC                array array double Gain matrix
/// (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
/// GainTypeC            AntennaPatternType Pattern type
/// GainOffsetC          double             Pattern offset
/// PhaseOffsetL1        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation
/// [-90, 90] and the second dimension to azimuth [0, 360[. PhaseOffsetTypeL1    AntennaPatternType Pattern type
/// PhasePatternOffsetL1 double             Pattern offset
/// PhaseOffsetL2        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation
/// [-90, 90] and the second dimension to azimuth [0, 360[. PhaseOffsetTypeL2    AntennaPatternType Pattern type
/// PhasePatternOffsetL2 double             Pattern offset
/// PhaseOffsetL5        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation
/// [-90, 90] and the second dimension to azimuth [0, 360[. PhaseOffsetTypeL5    AntennaPatternType Pattern type
/// PhasePatternOffsetL5 double             Pattern offset
/// PhaseOffsetE6        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation
/// [-90, 90] and the second dimension to azimuth [0, 360[. PhaseOffsetTypeE6    AntennaPatternType Pattern type
/// PhasePatternOffsetE6 double             Pattern offset
/// PhaseOffsetS         array array double Phase offset matrix (rad). The first dimension will be mapped to elevation
/// [-90, 90] and the second dimension to azimuth [0, 360[. PhaseOffsetTypeS     AntennaPatternType Pattern type
/// PhasePatternOffsetS  double             Pattern offset
/// PhaseOffsetC         array array double Phase offset matrix (rad). The first dimension will be mapped to elevation
/// [-90, 90] and the second dimension to azimuth [0, 360[. PhaseOffsetTypeC     AntennaPatternType Pattern type
/// PhasePatternOffsetC  double             Pattern offset
/// X                    double             Antenna X offset in the body frame (meter)
/// Y                    double             Antenna Y offset in the body frame (meter)
/// Z                    double             Antenna Z offset in the body frame (meter)
/// Yaw                  double             Antenna Yaw offset in the body frame (rad)
/// Pitch                double             Antenna Pitch offset in the body frame (rad)
/// Roll                 double             Antenna Roll offset in the body frame (rad)
/// Name                 string             Vehicle antenna model name
///

class GetVehicleAntennaModelResult;
typedef std::shared_ptr<GetVehicleAntennaModelResult> GetVehicleAntennaModelResultPtr;

class GetVehicleAntennaModelResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVehicleAntennaModelResult";
  inline static const char* const Documentation =
    "Result of GetVehicleAntennaModel.\n"
    "\n"
    "Name                 Type               Description\n"
    "-------------------- ------------------ ----------------------------------------------------------------------------------------------------------------------------------\n"
    "GainL1               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "GainTypeL1           AntennaPatternType Pattern type\n"
    "GainOffsetL1         double             Pattern offset\n"
    "GainL2               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "GainTypeL2           AntennaPatternType Pattern type\n"
    "GainOffsetL2         double             Pattern offset\n"
    "GainL5               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "GainTypeL5           AntennaPatternType Pattern type\n"
    "GainOffsetL5         double             Pattern offset\n"
    "GainE6               array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "GainTypeE6           AntennaPatternType Pattern type\n"
    "GainOffsetE6         double             Pattern offset\n"
    "GainS                array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "GainTypeS            AntennaPatternType Pattern type\n"
    "GainOffsetS          double             Pattern offset\n"
    "GainC                array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "GainTypeC            AntennaPatternType Pattern type\n"
    "GainOffsetC          double             Pattern offset\n"
    "PhaseOffsetL1        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "PhaseOffsetTypeL1    AntennaPatternType Pattern type\n"
    "PhasePatternOffsetL1 double             Pattern offset\n"
    "PhaseOffsetL2        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "PhaseOffsetTypeL2    AntennaPatternType Pattern type\n"
    "PhasePatternOffsetL2 double             Pattern offset\n"
    "PhaseOffsetL5        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "PhaseOffsetTypeL5    AntennaPatternType Pattern type\n"
    "PhasePatternOffsetL5 double             Pattern offset\n"
    "PhaseOffsetE6        array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "PhaseOffsetTypeE6    AntennaPatternType Pattern type\n"
    "PhasePatternOffsetE6 double             Pattern offset\n"
    "PhaseOffsetS         array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "PhaseOffsetTypeS     AntennaPatternType Pattern type\n"
    "PhasePatternOffsetS  double             Pattern offset\n"
    "PhaseOffsetC         array array double Phase offset matrix (rad). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
    "PhaseOffsetTypeC     AntennaPatternType Pattern type\n"
    "PhasePatternOffsetC  double             Pattern offset\n"
    "X                    double             Antenna X offset in the body frame (meter)\n"
    "Y                    double             Antenna Y offset in the body frame (meter)\n"
    "Z                    double             Antenna Z offset in the body frame (meter)\n"
    "Yaw                  double             Antenna Yaw offset in the body frame (rad)\n"
    "Pitch                double             Antenna Pitch offset in the body frame (rad)\n"
    "Roll                 double             Antenna Roll offset in the body frame (rad)\n"
    "Name                 string             Vehicle antenna model name";
  inline static const char* const TargetId = "";

  GetVehicleAntennaModelResult() : CommandResult(CmdName, TargetId) {}

  GetVehicleAntennaModelResult(const std::vector<std::vector<double>>& gainL1,
                               const Sdx::AntennaPatternType& gainTypeL1,
                               double gainOffsetL1,
                               const std::vector<std::vector<double>>& gainL2,
                               const Sdx::AntennaPatternType& gainTypeL2,
                               double gainOffsetL2,
                               const std::vector<std::vector<double>>& gainL5,
                               const Sdx::AntennaPatternType& gainTypeL5,
                               double gainOffsetL5,
                               const std::vector<std::vector<double>>& gainE6,
                               const Sdx::AntennaPatternType& gainTypeE6,
                               double gainOffsetE6,
                               const std::vector<std::vector<double>>& gainS,
                               const Sdx::AntennaPatternType& gainTypeS,
                               double gainOffsetS,
                               const std::vector<std::vector<double>>& gainC,
                               const Sdx::AntennaPatternType& gainTypeC,
                               double gainOffsetC,
                               const std::vector<std::vector<double>>& phaseOffsetL1,
                               const Sdx::AntennaPatternType& phaseOffsetTypeL1,
                               double phasePatternOffsetL1,
                               const std::vector<std::vector<double>>& phaseOffsetL2,
                               const Sdx::AntennaPatternType& phaseOffsetTypeL2,
                               double phasePatternOffsetL2,
                               const std::vector<std::vector<double>>& phaseOffsetL5,
                               const Sdx::AntennaPatternType& phaseOffsetTypeL5,
                               double phasePatternOffsetL5,
                               const std::vector<std::vector<double>>& phaseOffsetE6,
                               const Sdx::AntennaPatternType& phaseOffsetTypeE6,
                               double phasePatternOffsetE6,
                               const std::vector<std::vector<double>>& phaseOffsetS,
                               const Sdx::AntennaPatternType& phaseOffsetTypeS,
                               double phasePatternOffsetS,
                               const std::vector<std::vector<double>>& phaseOffsetC,
                               const Sdx::AntennaPatternType& phaseOffsetTypeC,
                               double phasePatternOffsetC,
                               double x,
                               double y,
                               double z,
                               double yaw,
                               double pitch,
                               double roll,
                               const std::string& name) :
    CommandResult(CmdName, TargetId)
  {

    setGainL1(gainL1);
    setGainTypeL1(gainTypeL1);
    setGainOffsetL1(gainOffsetL1);
    setGainL2(gainL2);
    setGainTypeL2(gainTypeL2);
    setGainOffsetL2(gainOffsetL2);
    setGainL5(gainL5);
    setGainTypeL5(gainTypeL5);
    setGainOffsetL5(gainOffsetL5);
    setGainE6(gainE6);
    setGainTypeE6(gainTypeE6);
    setGainOffsetE6(gainOffsetE6);
    setGainS(gainS);
    setGainTypeS(gainTypeS);
    setGainOffsetS(gainOffsetS);
    setGainC(gainC);
    setGainTypeC(gainTypeC);
    setGainOffsetC(gainOffsetC);
    setPhaseOffsetL1(phaseOffsetL1);
    setPhaseOffsetTypeL1(phaseOffsetTypeL1);
    setPhasePatternOffsetL1(phasePatternOffsetL1);
    setPhaseOffsetL2(phaseOffsetL2);
    setPhaseOffsetTypeL2(phaseOffsetTypeL2);
    setPhasePatternOffsetL2(phasePatternOffsetL2);
    setPhaseOffsetL5(phaseOffsetL5);
    setPhaseOffsetTypeL5(phaseOffsetTypeL5);
    setPhasePatternOffsetL5(phasePatternOffsetL5);
    setPhaseOffsetE6(phaseOffsetE6);
    setPhaseOffsetTypeE6(phaseOffsetTypeE6);
    setPhasePatternOffsetE6(phasePatternOffsetE6);
    setPhaseOffsetS(phaseOffsetS);
    setPhaseOffsetTypeS(phaseOffsetTypeS);
    setPhasePatternOffsetS(phasePatternOffsetS);
    setPhaseOffsetC(phaseOffsetC);
    setPhaseOffsetTypeC(phaseOffsetTypeC);
    setPhasePatternOffsetC(phasePatternOffsetC);
    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setName(name);
  }

  GetVehicleAntennaModelResult(CommandBasePtr relatedCommand,
                               const std::vector<std::vector<double>>& gainL1,
                               const Sdx::AntennaPatternType& gainTypeL1,
                               double gainOffsetL1,
                               const std::vector<std::vector<double>>& gainL2,
                               const Sdx::AntennaPatternType& gainTypeL2,
                               double gainOffsetL2,
                               const std::vector<std::vector<double>>& gainL5,
                               const Sdx::AntennaPatternType& gainTypeL5,
                               double gainOffsetL5,
                               const std::vector<std::vector<double>>& gainE6,
                               const Sdx::AntennaPatternType& gainTypeE6,
                               double gainOffsetE6,
                               const std::vector<std::vector<double>>& gainS,
                               const Sdx::AntennaPatternType& gainTypeS,
                               double gainOffsetS,
                               const std::vector<std::vector<double>>& gainC,
                               const Sdx::AntennaPatternType& gainTypeC,
                               double gainOffsetC,
                               const std::vector<std::vector<double>>& phaseOffsetL1,
                               const Sdx::AntennaPatternType& phaseOffsetTypeL1,
                               double phasePatternOffsetL1,
                               const std::vector<std::vector<double>>& phaseOffsetL2,
                               const Sdx::AntennaPatternType& phaseOffsetTypeL2,
                               double phasePatternOffsetL2,
                               const std::vector<std::vector<double>>& phaseOffsetL5,
                               const Sdx::AntennaPatternType& phaseOffsetTypeL5,
                               double phasePatternOffsetL5,
                               const std::vector<std::vector<double>>& phaseOffsetE6,
                               const Sdx::AntennaPatternType& phaseOffsetTypeE6,
                               double phasePatternOffsetE6,
                               const std::vector<std::vector<double>>& phaseOffsetS,
                               const Sdx::AntennaPatternType& phaseOffsetTypeS,
                               double phasePatternOffsetS,
                               const std::vector<std::vector<double>>& phaseOffsetC,
                               const Sdx::AntennaPatternType& phaseOffsetTypeC,
                               double phasePatternOffsetC,
                               double x,
                               double y,
                               double z,
                               double yaw,
                               double pitch,
                               double roll,
                               const std::string& name) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setGainL1(gainL1);
    setGainTypeL1(gainTypeL1);
    setGainOffsetL1(gainOffsetL1);
    setGainL2(gainL2);
    setGainTypeL2(gainTypeL2);
    setGainOffsetL2(gainOffsetL2);
    setGainL5(gainL5);
    setGainTypeL5(gainTypeL5);
    setGainOffsetL5(gainOffsetL5);
    setGainE6(gainE6);
    setGainTypeE6(gainTypeE6);
    setGainOffsetE6(gainOffsetE6);
    setGainS(gainS);
    setGainTypeS(gainTypeS);
    setGainOffsetS(gainOffsetS);
    setGainC(gainC);
    setGainTypeC(gainTypeC);
    setGainOffsetC(gainOffsetC);
    setPhaseOffsetL1(phaseOffsetL1);
    setPhaseOffsetTypeL1(phaseOffsetTypeL1);
    setPhasePatternOffsetL1(phasePatternOffsetL1);
    setPhaseOffsetL2(phaseOffsetL2);
    setPhaseOffsetTypeL2(phaseOffsetTypeL2);
    setPhasePatternOffsetL2(phasePatternOffsetL2);
    setPhaseOffsetL5(phaseOffsetL5);
    setPhaseOffsetTypeL5(phaseOffsetTypeL5);
    setPhasePatternOffsetL5(phasePatternOffsetL5);
    setPhaseOffsetE6(phaseOffsetE6);
    setPhaseOffsetTypeE6(phaseOffsetTypeE6);
    setPhasePatternOffsetE6(phasePatternOffsetE6);
    setPhaseOffsetS(phaseOffsetS);
    setPhaseOffsetTypeS(phaseOffsetTypeS);
    setPhasePatternOffsetS(phasePatternOffsetS);
    setPhaseOffsetC(phaseOffsetC);
    setPhaseOffsetTypeC(phaseOffsetTypeC);
    setPhasePatternOffsetC(phasePatternOffsetC);
    setX(x);
    setY(y);
    setZ(z);
    setYaw(yaw);
    setPitch(pitch);
    setRoll(roll);
    setName(name);
  }

  static GetVehicleAntennaModelResultPtr create(const std::vector<std::vector<double>>& gainL1,
                                                const Sdx::AntennaPatternType& gainTypeL1,
                                                double gainOffsetL1,
                                                const std::vector<std::vector<double>>& gainL2,
                                                const Sdx::AntennaPatternType& gainTypeL2,
                                                double gainOffsetL2,
                                                const std::vector<std::vector<double>>& gainL5,
                                                const Sdx::AntennaPatternType& gainTypeL5,
                                                double gainOffsetL5,
                                                const std::vector<std::vector<double>>& gainE6,
                                                const Sdx::AntennaPatternType& gainTypeE6,
                                                double gainOffsetE6,
                                                const std::vector<std::vector<double>>& gainS,
                                                const Sdx::AntennaPatternType& gainTypeS,
                                                double gainOffsetS,
                                                const std::vector<std::vector<double>>& gainC,
                                                const Sdx::AntennaPatternType& gainTypeC,
                                                double gainOffsetC,
                                                const std::vector<std::vector<double>>& phaseOffsetL1,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeL1,
                                                double phasePatternOffsetL1,
                                                const std::vector<std::vector<double>>& phaseOffsetL2,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeL2,
                                                double phasePatternOffsetL2,
                                                const std::vector<std::vector<double>>& phaseOffsetL5,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeL5,
                                                double phasePatternOffsetL5,
                                                const std::vector<std::vector<double>>& phaseOffsetE6,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeE6,
                                                double phasePatternOffsetE6,
                                                const std::vector<std::vector<double>>& phaseOffsetS,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeS,
                                                double phasePatternOffsetS,
                                                const std::vector<std::vector<double>>& phaseOffsetC,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeC,
                                                double phasePatternOffsetC,
                                                double x,
                                                double y,
                                                double z,
                                                double yaw,
                                                double pitch,
                                                double roll,
                                                const std::string& name)
  {
    return std::make_shared<GetVehicleAntennaModelResult>(gainL1,
                                                          gainTypeL1,
                                                          gainOffsetL1,
                                                          gainL2,
                                                          gainTypeL2,
                                                          gainOffsetL2,
                                                          gainL5,
                                                          gainTypeL5,
                                                          gainOffsetL5,
                                                          gainE6,
                                                          gainTypeE6,
                                                          gainOffsetE6,
                                                          gainS,
                                                          gainTypeS,
                                                          gainOffsetS,
                                                          gainC,
                                                          gainTypeC,
                                                          gainOffsetC,
                                                          phaseOffsetL1,
                                                          phaseOffsetTypeL1,
                                                          phasePatternOffsetL1,
                                                          phaseOffsetL2,
                                                          phaseOffsetTypeL2,
                                                          phasePatternOffsetL2,
                                                          phaseOffsetL5,
                                                          phaseOffsetTypeL5,
                                                          phasePatternOffsetL5,
                                                          phaseOffsetE6,
                                                          phaseOffsetTypeE6,
                                                          phasePatternOffsetE6,
                                                          phaseOffsetS,
                                                          phaseOffsetTypeS,
                                                          phasePatternOffsetS,
                                                          phaseOffsetC,
                                                          phaseOffsetTypeC,
                                                          phasePatternOffsetC,
                                                          x,
                                                          y,
                                                          z,
                                                          yaw,
                                                          pitch,
                                                          roll,
                                                          name);
  }

  static GetVehicleAntennaModelResultPtr create(CommandBasePtr relatedCommand,
                                                const std::vector<std::vector<double>>& gainL1,
                                                const Sdx::AntennaPatternType& gainTypeL1,
                                                double gainOffsetL1,
                                                const std::vector<std::vector<double>>& gainL2,
                                                const Sdx::AntennaPatternType& gainTypeL2,
                                                double gainOffsetL2,
                                                const std::vector<std::vector<double>>& gainL5,
                                                const Sdx::AntennaPatternType& gainTypeL5,
                                                double gainOffsetL5,
                                                const std::vector<std::vector<double>>& gainE6,
                                                const Sdx::AntennaPatternType& gainTypeE6,
                                                double gainOffsetE6,
                                                const std::vector<std::vector<double>>& gainS,
                                                const Sdx::AntennaPatternType& gainTypeS,
                                                double gainOffsetS,
                                                const std::vector<std::vector<double>>& gainC,
                                                const Sdx::AntennaPatternType& gainTypeC,
                                                double gainOffsetC,
                                                const std::vector<std::vector<double>>& phaseOffsetL1,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeL1,
                                                double phasePatternOffsetL1,
                                                const std::vector<std::vector<double>>& phaseOffsetL2,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeL2,
                                                double phasePatternOffsetL2,
                                                const std::vector<std::vector<double>>& phaseOffsetL5,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeL5,
                                                double phasePatternOffsetL5,
                                                const std::vector<std::vector<double>>& phaseOffsetE6,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeE6,
                                                double phasePatternOffsetE6,
                                                const std::vector<std::vector<double>>& phaseOffsetS,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeS,
                                                double phasePatternOffsetS,
                                                const std::vector<std::vector<double>>& phaseOffsetC,
                                                const Sdx::AntennaPatternType& phaseOffsetTypeC,
                                                double phasePatternOffsetC,
                                                double x,
                                                double y,
                                                double z,
                                                double yaw,
                                                double pitch,
                                                double roll,
                                                const std::string& name)
  {
    return std::make_shared<GetVehicleAntennaModelResult>(relatedCommand,
                                                          gainL1,
                                                          gainTypeL1,
                                                          gainOffsetL1,
                                                          gainL2,
                                                          gainTypeL2,
                                                          gainOffsetL2,
                                                          gainL5,
                                                          gainTypeL5,
                                                          gainOffsetL5,
                                                          gainE6,
                                                          gainTypeE6,
                                                          gainOffsetE6,
                                                          gainS,
                                                          gainTypeS,
                                                          gainOffsetS,
                                                          gainC,
                                                          gainTypeC,
                                                          gainOffsetC,
                                                          phaseOffsetL1,
                                                          phaseOffsetTypeL1,
                                                          phasePatternOffsetL1,
                                                          phaseOffsetL2,
                                                          phaseOffsetTypeL2,
                                                          phasePatternOffsetL2,
                                                          phaseOffsetL5,
                                                          phaseOffsetTypeL5,
                                                          phasePatternOffsetL5,
                                                          phaseOffsetE6,
                                                          phaseOffsetTypeE6,
                                                          phasePatternOffsetE6,
                                                          phaseOffsetS,
                                                          phaseOffsetTypeS,
                                                          phasePatternOffsetS,
                                                          phaseOffsetC,
                                                          phaseOffsetTypeC,
                                                          phasePatternOffsetC,
                                                          x,
                                                          y,
                                                          z,
                                                          yaw,
                                                          pitch,
                                                          roll,
                                                          name);
  }

  static GetVehicleAntennaModelResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleAntennaModelResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainL1"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeL1"]) &&
           parse_json<double>::is_valid(m_values["GainOffsetL1"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainL2"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeL2"]) &&
           parse_json<double>::is_valid(m_values["GainOffsetL2"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainL5"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeL5"]) &&
           parse_json<double>::is_valid(m_values["GainOffsetL5"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainE6"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeE6"]) &&
           parse_json<double>::is_valid(m_values["GainOffsetE6"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainS"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeS"]) &&
           parse_json<double>::is_valid(m_values["GainOffsetS"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["GainC"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["GainTypeC"]) &&
           parse_json<double>::is_valid(m_values["GainOffsetC"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetL1"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeL1"]) &&
           parse_json<double>::is_valid(m_values["PhasePatternOffsetL1"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetL2"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeL2"]) &&
           parse_json<double>::is_valid(m_values["PhasePatternOffsetL2"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetL5"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeL5"]) &&
           parse_json<double>::is_valid(m_values["PhasePatternOffsetL5"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetE6"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeE6"]) &&
           parse_json<double>::is_valid(m_values["PhasePatternOffsetE6"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetS"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeS"]) &&
           parse_json<double>::is_valid(m_values["PhasePatternOffsetS"]) &&
           parse_json<std::vector<std::vector<double>>>::is_valid(m_values["PhaseOffsetC"]) &&
           parse_json<Sdx::AntennaPatternType>::is_valid(m_values["PhaseOffsetTypeC"]) &&
           parse_json<double>::is_valid(m_values["PhasePatternOffsetC"]) &&
           parse_json<double>::is_valid(m_values["X"]) && parse_json<double>::is_valid(m_values["Y"]) &&
           parse_json<double>::is_valid(m_values["Z"]) && parse_json<double>::is_valid(m_values["Yaw"]) &&
           parse_json<double>::is_valid(m_values["Pitch"]) && parse_json<double>::is_valid(m_values["Roll"]) &&
           parse_json<std::string>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"GainL1",
                                                 "GainTypeL1",
                                                 "GainOffsetL1",
                                                 "GainL2",
                                                 "GainTypeL2",
                                                 "GainOffsetL2",
                                                 "GainL5",
                                                 "GainTypeL5",
                                                 "GainOffsetL5",
                                                 "GainE6",
                                                 "GainTypeE6",
                                                 "GainOffsetE6",
                                                 "GainS",
                                                 "GainTypeS",
                                                 "GainOffsetS",
                                                 "GainC",
                                                 "GainTypeC",
                                                 "GainOffsetC",
                                                 "PhaseOffsetL1",
                                                 "PhaseOffsetTypeL1",
                                                 "PhasePatternOffsetL1",
                                                 "PhaseOffsetL2",
                                                 "PhaseOffsetTypeL2",
                                                 "PhasePatternOffsetL2",
                                                 "PhaseOffsetL5",
                                                 "PhaseOffsetTypeL5",
                                                 "PhasePatternOffsetL5",
                                                 "PhaseOffsetE6",
                                                 "PhaseOffsetTypeE6",
                                                 "PhasePatternOffsetE6",
                                                 "PhaseOffsetS",
                                                 "PhaseOffsetTypeS",
                                                 "PhasePatternOffsetS",
                                                 "PhaseOffsetC",
                                                 "PhaseOffsetTypeC",
                                                 "PhasePatternOffsetC",
                                                 "X",
                                                 "Y",
                                                 "Z",
                                                 "Yaw",
                                                 "Pitch",
                                                 "Roll",
                                                 "Name"};
    return names;
  }

  std::vector<std::vector<double>> gainL1() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainL1"]);
  }

  void setGainL1(const std::vector<std::vector<double>>& gainL1)
  {
    m_values.AddMember("GainL1",
                       parse_json<std::vector<std::vector<double>>>::format(gainL1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType gainTypeL1() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeL1"]);
  }

  void setGainTypeL1(const Sdx::AntennaPatternType& gainTypeL1)
  {
    m_values.AddMember("GainTypeL1",
                       parse_json<Sdx::AntennaPatternType>::format(gainTypeL1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double gainOffsetL1() const { return parse_json<double>::parse(m_values["GainOffsetL1"]); }

  void setGainOffsetL1(double gainOffsetL1)
  {
    m_values.AddMember("GainOffsetL1",
                       parse_json<double>::format(gainOffsetL1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> gainL2() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainL2"]);
  }

  void setGainL2(const std::vector<std::vector<double>>& gainL2)
  {
    m_values.AddMember("GainL2",
                       parse_json<std::vector<std::vector<double>>>::format(gainL2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType gainTypeL2() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeL2"]);
  }

  void setGainTypeL2(const Sdx::AntennaPatternType& gainTypeL2)
  {
    m_values.AddMember("GainTypeL2",
                       parse_json<Sdx::AntennaPatternType>::format(gainTypeL2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double gainOffsetL2() const { return parse_json<double>::parse(m_values["GainOffsetL2"]); }

  void setGainOffsetL2(double gainOffsetL2)
  {
    m_values.AddMember("GainOffsetL2",
                       parse_json<double>::format(gainOffsetL2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> gainL5() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainL5"]);
  }

  void setGainL5(const std::vector<std::vector<double>>& gainL5)
  {
    m_values.AddMember("GainL5",
                       parse_json<std::vector<std::vector<double>>>::format(gainL5, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType gainTypeL5() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeL5"]);
  }

  void setGainTypeL5(const Sdx::AntennaPatternType& gainTypeL5)
  {
    m_values.AddMember("GainTypeL5",
                       parse_json<Sdx::AntennaPatternType>::format(gainTypeL5, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double gainOffsetL5() const { return parse_json<double>::parse(m_values["GainOffsetL5"]); }

  void setGainOffsetL5(double gainOffsetL5)
  {
    m_values.AddMember("GainOffsetL5",
                       parse_json<double>::format(gainOffsetL5, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> gainE6() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainE6"]);
  }

  void setGainE6(const std::vector<std::vector<double>>& gainE6)
  {
    m_values.AddMember("GainE6",
                       parse_json<std::vector<std::vector<double>>>::format(gainE6, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType gainTypeE6() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeE6"]);
  }

  void setGainTypeE6(const Sdx::AntennaPatternType& gainTypeE6)
  {
    m_values.AddMember("GainTypeE6",
                       parse_json<Sdx::AntennaPatternType>::format(gainTypeE6, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double gainOffsetE6() const { return parse_json<double>::parse(m_values["GainOffsetE6"]); }

  void setGainOffsetE6(double gainOffsetE6)
  {
    m_values.AddMember("GainOffsetE6",
                       parse_json<double>::format(gainOffsetE6, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> gainS() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainS"]);
  }

  void setGainS(const std::vector<std::vector<double>>& gainS)
  {
    m_values.AddMember("GainS",
                       parse_json<std::vector<std::vector<double>>>::format(gainS, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType gainTypeS() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeS"]);
  }

  void setGainTypeS(const Sdx::AntennaPatternType& gainTypeS)
  {
    m_values.AddMember("GainTypeS",
                       parse_json<Sdx::AntennaPatternType>::format(gainTypeS, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double gainOffsetS() const { return parse_json<double>::parse(m_values["GainOffsetS"]); }

  void setGainOffsetS(double gainOffsetS)
  {
    m_values.AddMember("GainOffsetS",
                       parse_json<double>::format(gainOffsetS, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> gainC() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["GainC"]);
  }

  void setGainC(const std::vector<std::vector<double>>& gainC)
  {
    m_values.AddMember("GainC",
                       parse_json<std::vector<std::vector<double>>>::format(gainC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType gainTypeC() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["GainTypeC"]);
  }

  void setGainTypeC(const Sdx::AntennaPatternType& gainTypeC)
  {
    m_values.AddMember("GainTypeC",
                       parse_json<Sdx::AntennaPatternType>::format(gainTypeC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double gainOffsetC() const { return parse_json<double>::parse(m_values["GainOffsetC"]); }

  void setGainOffsetC(double gainOffsetC)
  {
    m_values.AddMember("GainOffsetC",
                       parse_json<double>::format(gainOffsetC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> phaseOffsetL1() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetL1"]);
  }

  void setPhaseOffsetL1(const std::vector<std::vector<double>>& phaseOffsetL1)
  {
    m_values.AddMember("PhaseOffsetL1",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffsetL1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType phaseOffsetTypeL1() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeL1"]);
  }

  void setPhaseOffsetTypeL1(const Sdx::AntennaPatternType& phaseOffsetTypeL1)
  {
    m_values.AddMember("PhaseOffsetTypeL1",
                       parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeL1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phasePatternOffsetL1() const { return parse_json<double>::parse(m_values["PhasePatternOffsetL1"]); }

  void setPhasePatternOffsetL1(double phasePatternOffsetL1)
  {
    m_values.AddMember("PhasePatternOffsetL1",
                       parse_json<double>::format(phasePatternOffsetL1, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> phaseOffsetL2() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetL2"]);
  }

  void setPhaseOffsetL2(const std::vector<std::vector<double>>& phaseOffsetL2)
  {
    m_values.AddMember("PhaseOffsetL2",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffsetL2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType phaseOffsetTypeL2() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeL2"]);
  }

  void setPhaseOffsetTypeL2(const Sdx::AntennaPatternType& phaseOffsetTypeL2)
  {
    m_values.AddMember("PhaseOffsetTypeL2",
                       parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeL2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phasePatternOffsetL2() const { return parse_json<double>::parse(m_values["PhasePatternOffsetL2"]); }

  void setPhasePatternOffsetL2(double phasePatternOffsetL2)
  {
    m_values.AddMember("PhasePatternOffsetL2",
                       parse_json<double>::format(phasePatternOffsetL2, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> phaseOffsetL5() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetL5"]);
  }

  void setPhaseOffsetL5(const std::vector<std::vector<double>>& phaseOffsetL5)
  {
    m_values.AddMember("PhaseOffsetL5",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffsetL5, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType phaseOffsetTypeL5() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeL5"]);
  }

  void setPhaseOffsetTypeL5(const Sdx::AntennaPatternType& phaseOffsetTypeL5)
  {
    m_values.AddMember("PhaseOffsetTypeL5",
                       parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeL5, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phasePatternOffsetL5() const { return parse_json<double>::parse(m_values["PhasePatternOffsetL5"]); }

  void setPhasePatternOffsetL5(double phasePatternOffsetL5)
  {
    m_values.AddMember("PhasePatternOffsetL5",
                       parse_json<double>::format(phasePatternOffsetL5, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> phaseOffsetE6() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetE6"]);
  }

  void setPhaseOffsetE6(const std::vector<std::vector<double>>& phaseOffsetE6)
  {
    m_values.AddMember("PhaseOffsetE6",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffsetE6, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType phaseOffsetTypeE6() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeE6"]);
  }

  void setPhaseOffsetTypeE6(const Sdx::AntennaPatternType& phaseOffsetTypeE6)
  {
    m_values.AddMember("PhaseOffsetTypeE6",
                       parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeE6, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phasePatternOffsetE6() const { return parse_json<double>::parse(m_values["PhasePatternOffsetE6"]); }

  void setPhasePatternOffsetE6(double phasePatternOffsetE6)
  {
    m_values.AddMember("PhasePatternOffsetE6",
                       parse_json<double>::format(phasePatternOffsetE6, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> phaseOffsetS() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetS"]);
  }

  void setPhaseOffsetS(const std::vector<std::vector<double>>& phaseOffsetS)
  {
    m_values.AddMember("PhaseOffsetS",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffsetS, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType phaseOffsetTypeS() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeS"]);
  }

  void setPhaseOffsetTypeS(const Sdx::AntennaPatternType& phaseOffsetTypeS)
  {
    m_values.AddMember("PhaseOffsetTypeS",
                       parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeS, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phasePatternOffsetS() const { return parse_json<double>::parse(m_values["PhasePatternOffsetS"]); }

  void setPhasePatternOffsetS(double phasePatternOffsetS)
  {
    m_values.AddMember("PhasePatternOffsetS",
                       parse_json<double>::format(phasePatternOffsetS, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<std::vector<double>> phaseOffsetC() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["PhaseOffsetC"]);
  }

  void setPhaseOffsetC(const std::vector<std::vector<double>>& phaseOffsetC)
  {
    m_values.AddMember("PhaseOffsetC",
                       parse_json<std::vector<std::vector<double>>>::format(phaseOffsetC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  Sdx::AntennaPatternType phaseOffsetTypeC() const
  {
    return parse_json<Sdx::AntennaPatternType>::parse(m_values["PhaseOffsetTypeC"]);
  }

  void setPhaseOffsetTypeC(const Sdx::AntennaPatternType& phaseOffsetTypeC)
  {
    m_values.AddMember("PhaseOffsetTypeC",
                       parse_json<Sdx::AntennaPatternType>::format(phaseOffsetTypeC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double phasePatternOffsetC() const { return parse_json<double>::parse(m_values["PhasePatternOffsetC"]); }

  void setPhasePatternOffsetC(double phasePatternOffsetC)
  {
    m_values.AddMember("PhasePatternOffsetC",
                       parse_json<double>::format(phasePatternOffsetC, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double x() const { return parse_json<double>::parse(m_values["X"]); }

  void setX(double x)
  {
    m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double y() const { return parse_json<double>::parse(m_values["Y"]); }

  void setY(double y)
  {
    m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double z() const { return parse_json<double>::parse(m_values["Z"]); }

  void setZ(double z)
  {
    m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double yaw() const { return parse_json<double>::parse(m_values["Yaw"]); }

  void setYaw(double yaw)
  {
    m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double pitch() const { return parse_json<double>::parse(m_values["Pitch"]); }

  void setPitch(double pitch)
  {
    m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double roll() const { return parse_json<double>::parse(m_values["Roll"]); }

  void setRoll(double roll)
  {
    m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string name() const { return parse_json<std::string>::parse(m_values["Name"]); }

  void setName(const std::string& name)
  {
    m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaModelResult);
} // namespace Cmd
} // namespace Sdx
