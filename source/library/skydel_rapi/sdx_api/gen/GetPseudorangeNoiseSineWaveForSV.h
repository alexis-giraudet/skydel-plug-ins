#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the satellite pseudorange noise sine wave attributes.
///
/// Name     Type   Description
/// -------- ------ --------------------------------------------------------------------------
/// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// SvId     int    The satellite's SV ID
/// SineWave int    Sine wave number (0 or 1)
///

class GetPseudorangeNoiseSineWaveForSV;
typedef std::shared_ptr<GetPseudorangeNoiseSineWaveForSV> GetPseudorangeNoiseSineWaveForSVPtr;

class GetPseudorangeNoiseSineWaveForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPseudorangeNoiseSineWaveForSV";
  inline static const char* const Documentation =
    "Get the satellite pseudorange noise sine wave attributes.\n"
    "\n"
    "Name     Type   Description\n"
    "-------- ------ --------------------------------------------------------------------------\n"
    "System   string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId     int    The satellite's SV ID\n"
    "SineWave int    Sine wave number (0 or 1)";
  inline static const char* const TargetId = "";

  GetPseudorangeNoiseSineWaveForSV() : CommandBase(CmdName, TargetId) {}

  GetPseudorangeNoiseSineWaveForSV(const std::string& system, int svId, int sineWave) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setSineWave(sineWave);
  }

  static GetPseudorangeNoiseSineWaveForSVPtr create(const std::string& system, int svId, int sineWave)
  {
    return std::make_shared<GetPseudorangeNoiseSineWaveForSV>(system, svId, sineWave);
  }

  static GetPseudorangeNoiseSineWaveForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPseudorangeNoiseSineWaveForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<int>::is_valid(m_values["SineWave"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "SineWave"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int sineWave() const { return parse_json<int>::parse(m_values["SineWave"]); }

  void setSineWave(int sineWave)
  {
    m_values.AddMember("SineWave", parse_json<int>::format(sineWave, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetPseudorangeNoiseSineWaveForSV);
} // namespace Cmd
} // namespace Sdx
