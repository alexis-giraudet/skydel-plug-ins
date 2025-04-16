#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Calibrate a pilot output
///
/// Name         Type   Description
/// ------------ ------ ---------------------------------------------------
/// OutputIdx    int    RF Output index (zero-based)
/// Power        double Power (dB), relative to transmitter reference power
/// Time         double Code time offset in second
/// CarrierPhase double Carrier phase offset in radians
///

class CalibratePilotOutput;
typedef std::shared_ptr<CalibratePilotOutput> CalibratePilotOutputPtr;

class CalibratePilotOutput : public CommandBase
{
public:
  inline static const char* const CmdName = "CalibratePilotOutput";
  inline static const char* const Documentation =
    "Calibrate a pilot output\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ ---------------------------------------------------\n"
    "OutputIdx    int    RF Output index (zero-based)\n"
    "Power        double Power (dB), relative to transmitter reference power\n"
    "Time         double Code time offset in second\n"
    "CarrierPhase double Carrier phase offset in radians";
  inline static const char* const TargetId = "";

  CalibratePilotOutput() : CommandBase(CmdName, TargetId) {}

  CalibratePilotOutput(int outputIdx, double power, double time, double carrierPhase) : CommandBase(CmdName, TargetId)
  {

    setOutputIdx(outputIdx);
    setPower(power);
    setTime(time);
    setCarrierPhase(carrierPhase);
  }

  static CalibratePilotOutputPtr create(int outputIdx, double power, double time, double carrierPhase)
  {
    return std::make_shared<CalibratePilotOutput>(outputIdx, power, time, carrierPhase);
  }

  static CalibratePilotOutputPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<CalibratePilotOutput>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["OutputIdx"]) &&
           parse_json<double>::is_valid(m_values["Power"]) && parse_json<double>::is_valid(m_values["Time"]) &&
           parse_json<double>::is_valid(m_values["CarrierPhase"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"OutputIdx", "Power", "Time", "CarrierPhase"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }

  int outputIdx() const { return parse_json<int>::parse(m_values["OutputIdx"]); }

  void setOutputIdx(int outputIdx)
  {
    m_values.AddMember("OutputIdx",
                       parse_json<int>::format(outputIdx, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double power() const { return parse_json<double>::parse(m_values["Power"]); }

  void setPower(double power)
  {
    m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double time() const { return parse_json<double>::parse(m_values["Time"]); }

  void setTime(double time)
  {
    m_values.AddMember("Time", parse_json<double>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double carrierPhase() const { return parse_json<double>::parse(m_values["CarrierPhase"]); }

  void setCarrierPhase(double carrierPhase)
  {
    m_values.AddMember("CarrierPhase",
                       parse_json<double>::format(carrierPhase, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(CalibratePilotOutput);
} // namespace Cmd
} // namespace Sdx
