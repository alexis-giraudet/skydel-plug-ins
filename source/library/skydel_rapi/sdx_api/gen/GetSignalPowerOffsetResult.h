#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSignalPowerOffset.
///
/// Name   Type   Description
/// ------ ------ ----------------------------------------------------------------------------------------------------
/// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                     "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
///                                     "B1", "B2", "B1C", "B2a", "B3I", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C",
///                                     "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
///                                     "PULSARXL", "PULSARX1", "PULSARX5"
/// Offset double Offset in dB (negative value will attenuate signal)
///

class GetSignalPowerOffsetResult;
typedef std::shared_ptr<GetSignalPowerOffsetResult> GetSignalPowerOffsetResultPtr;
typedef GetSignalPowerOffsetResult GetPowerOffsetResult;
typedef std::shared_ptr<GetPowerOffsetResult> GetPowerOffsetResultPtr;

class GetSignalPowerOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSignalPowerOffsetResult";
  inline static const char* const Documentation =
    "Result of GetSignalPowerOffset.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ----------------------------------------------------------------------------------------------------\n"
    "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
    "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\",\n"
    "                                    \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
    "                                    \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
    "Offset double Offset in dB (negative value will attenuate signal)";
  inline static const char* const TargetId = "";

  GetSignalPowerOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetSignalPowerOffsetResult(const std::string& signal, double offset) : CommandResult(CmdName, TargetId)
  {

    setSignal(signal);
    setOffset(offset);
  }

  GetSignalPowerOffsetResult(CommandBasePtr relatedCommand, const std::string& signal, double offset) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSignal(signal);
    setOffset(offset);
  }

  static GetSignalPowerOffsetResultPtr create(const std::string& signal, double offset)
  {
    return std::make_shared<GetSignalPowerOffsetResult>(signal, offset);
  }

  static GetSignalPowerOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, double offset)
  {
    return std::make_shared<GetSignalPowerOffsetResult>(relatedCommand, signal, offset);
  }

  static GetSignalPowerOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSignalPowerOffsetResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<double>::is_valid(m_values["Offset"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Offset"};
    return names;
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  double offset() const { return parse_json<double>::parse(m_values["Offset"]); }

  void setOffset(double offset)
  {
    m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSignalPowerOffsetResult);
} // namespace Cmd
} // namespace Sdx
