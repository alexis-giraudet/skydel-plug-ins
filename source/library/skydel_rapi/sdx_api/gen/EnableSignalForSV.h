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
/// Enable (or disable) signal for specified satellite.
///
/// Name    Type   Description
/// ------- ------
/// ------------------------------------------------------------------------------------------------------------- Signal
/// string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                      "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
///                                      "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
///                                      "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1",
///                                      "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5"
/// SvId    int    The satellite's SV ID (use 0 for all constellation's satellites)
/// Enabled bool   Signal is enabled when value is True
///

class EnableSignalForSV;
typedef std::shared_ptr<EnableSignalForSV> EnableSignalForSVPtr;

class EnableSignalForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableSignalForSV";
  inline static const char* const Documentation =
    "Enable (or disable) signal for specified satellite.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ -------------------------------------------------------------------------------------------------------------\n"
    "Signal  string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                     \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
    "                                     \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
    "                                     \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
    "                                     \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
    "SvId    int    The satellite's SV ID (use 0 for all constellation's satellites)\n"
    "Enabled bool   Signal is enabled when value is True";
  inline static const char* const TargetId = "";

  EnableSignalForSV() : CommandBase(CmdName, TargetId) {}

  EnableSignalForSV(const std::string& signal, int svId, bool enabled) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setSvId(svId);
    setEnabled(enabled);
  }

  static EnableSignalForSVPtr create(const std::string& signal, int svId, bool enabled)
  {
    return std::make_shared<EnableSignalForSV>(signal, svId, enabled);
  }

  static EnableSignalForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EnableSignalForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<bool>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "SvId", "Enabled"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EnableSignalForSV);
} // namespace Cmd
} // namespace Sdx
