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
/// Tells if the signal is enabled or disabled for each satellite.
///
/// Name   Type   Description
/// ------ ------
/// ------------------------------------------------------------------------------------------------------------- Signal
/// string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                     "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
///                                     "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
///                                     "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1",
///                                     "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5"
///

class IsSignalEnabledForEachSV;
typedef std::shared_ptr<IsSignalEnabledForEachSV> IsSignalEnabledForEachSVPtr;

class IsSignalEnabledForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsSignalEnabledForEachSV";
  inline static const char* const Documentation =
    "Tells if the signal is enabled or disabled for each satellite.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------------------------------------------------------\n"
    "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                    \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\",\n"
    "                                    \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
    "                                    \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\",\n"
    "                                    \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"";
  inline static const char* const TargetId = "";

  IsSignalEnabledForEachSV() : CommandBase(CmdName, TargetId) {}

  IsSignalEnabledForEachSV(const std::string& signal) : CommandBase(CmdName, TargetId) { setSignal(signal); }

  static IsSignalEnabledForEachSVPtr create(const std::string& signal)
  {
    return std::make_shared<IsSignalEnabledForEachSV>(signal);
  }

  static IsSignalEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSignalEnabledForEachSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsSignalEnabledForEachSV);
} // namespace Cmd
} // namespace Sdx
