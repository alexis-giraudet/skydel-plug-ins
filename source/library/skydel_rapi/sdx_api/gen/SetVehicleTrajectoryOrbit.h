#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set earth-orbiting spacecraft trajectory.
///
/// Name              Type     Description
/// ----------------- -------- ---------------------------------------------------------------------
/// Type              string   Trajectory type ("Orbit")
/// Reference         datetime Orbital parameters reference time (UTC)
/// SemiMajorAxis     double   Semi-major axis (meter)
/// Inclination       double   Inclination angle (rad)
/// RightAscension    double   Geographic longitude of the ascending node of the orbital plane (rad)
/// Eccentricity      double   Eccentricity
/// MeanAnomaly       double   Mean anomaly (rad)
/// ArgumentOfPerigee double   Argument of perigee (rad)
///

class SetVehicleTrajectoryOrbit;
typedef std::shared_ptr<SetVehicleTrajectoryOrbit> SetVehicleTrajectoryOrbitPtr;

class SetVehicleTrajectoryOrbit : public CommandBase
{
public:
  inline static const char* const CmdName = "SetVehicleTrajectoryOrbit";
  inline static const char* const Documentation =
    "Set earth-orbiting spacecraft trajectory.\n"
    "\n"
    "Name              Type     Description\n"
    "----------------- -------- ---------------------------------------------------------------------\n"
    "Type              string   Trajectory type (\"Orbit\")\n"
    "Reference         datetime Orbital parameters reference time (UTC)\n"
    "SemiMajorAxis     double   Semi-major axis (meter)\n"
    "Inclination       double   Inclination angle (rad)\n"
    "RightAscension    double   Geographic longitude of the ascending node of the orbital plane (rad)\n"
    "Eccentricity      double   Eccentricity\n"
    "MeanAnomaly       double   Mean anomaly (rad)\n"
    "ArgumentOfPerigee double   Argument of perigee (rad)";
  inline static const char* const TargetId = "";

  SetVehicleTrajectoryOrbit() : CommandBase(CmdName, TargetId) {}

  SetVehicleTrajectoryOrbit(const std::string& type,
                            const Sdx::DateTime& reference,
                            double semiMajorAxis,
                            double inclination,
                            double rightAscension,
                            double eccentricity,
                            double meanAnomaly,
                            double argumentOfPerigee) :
    CommandBase(CmdName, TargetId)
  {

    setType(type);
    setReference(reference);
    setSemiMajorAxis(semiMajorAxis);
    setInclination(inclination);
    setRightAscension(rightAscension);
    setEccentricity(eccentricity);
    setMeanAnomaly(meanAnomaly);
    setArgumentOfPerigee(argumentOfPerigee);
  }

  static SetVehicleTrajectoryOrbitPtr create(const std::string& type,
                                             const Sdx::DateTime& reference,
                                             double semiMajorAxis,
                                             double inclination,
                                             double rightAscension,
                                             double eccentricity,
                                             double meanAnomaly,
                                             double argumentOfPerigee)
  {
    return std::make_shared<SetVehicleTrajectoryOrbit>(type,
                                                       reference,
                                                       semiMajorAxis,
                                                       inclination,
                                                       rightAscension,
                                                       eccentricity,
                                                       meanAnomaly,
                                                       argumentOfPerigee);
  }

  static SetVehicleTrajectoryOrbitPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetVehicleTrajectoryOrbit>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]) &&
           parse_json<Sdx::DateTime>::is_valid(m_values["Reference"]) &&
           parse_json<double>::is_valid(m_values["SemiMajorAxis"]) &&
           parse_json<double>::is_valid(m_values["Inclination"]) &&
           parse_json<double>::is_valid(m_values["RightAscension"]) &&
           parse_json<double>::is_valid(m_values["Eccentricity"]) &&
           parse_json<double>::is_valid(m_values["MeanAnomaly"]) &&
           parse_json<double>::is_valid(m_values["ArgumentOfPerigee"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type",
                                                 "Reference",
                                                 "SemiMajorAxis",
                                                 "Inclination",
                                                 "RightAscension",
                                                 "Eccentricity",
                                                 "MeanAnomaly",
                                                 "ArgumentOfPerigee"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }

  Sdx::DateTime reference() const { return parse_json<Sdx::DateTime>::parse(m_values["Reference"]); }

  void setReference(const Sdx::DateTime& reference)
  {
    m_values.AddMember("Reference",
                       parse_json<Sdx::DateTime>::format(reference, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double semiMajorAxis() const { return parse_json<double>::parse(m_values["SemiMajorAxis"]); }

  void setSemiMajorAxis(double semiMajorAxis)
  {
    m_values.AddMember("SemiMajorAxis",
                       parse_json<double>::format(semiMajorAxis, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double inclination() const { return parse_json<double>::parse(m_values["Inclination"]); }

  void setInclination(double inclination)
  {
    m_values.AddMember("Inclination",
                       parse_json<double>::format(inclination, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double rightAscension() const { return parse_json<double>::parse(m_values["RightAscension"]); }

  void setRightAscension(double rightAscension)
  {
    m_values.AddMember("RightAscension",
                       parse_json<double>::format(rightAscension, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double eccentricity() const { return parse_json<double>::parse(m_values["Eccentricity"]); }

  void setEccentricity(double eccentricity)
  {
    m_values.AddMember("Eccentricity",
                       parse_json<double>::format(eccentricity, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double meanAnomaly() const { return parse_json<double>::parse(m_values["MeanAnomaly"]); }

  void setMeanAnomaly(double meanAnomaly)
  {
    m_values.AddMember("MeanAnomaly",
                       parse_json<double>::format(meanAnomaly, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double argumentOfPerigee() const { return parse_json<double>::parse(m_values["ArgumentOfPerigee"]); }

  void setArgumentOfPerigee(double argumentOfPerigee)
  {
    m_values.AddMember("ArgumentOfPerigee",
                       parse_json<double>::format(argumentOfPerigee, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetVehicleTrajectoryOrbit);
} // namespace Cmd
} // namespace Sdx
