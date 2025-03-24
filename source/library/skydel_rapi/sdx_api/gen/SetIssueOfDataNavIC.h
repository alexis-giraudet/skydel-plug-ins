#pragma once

#include <memory>
#include <optional>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set NavIC Issue of data, Ephemeris and Clock (IODEC)
///
/// Name              Type          Description
/// ----------------- ------------- -------------------------------------------------------
/// EphemerisAndClock int           Issue of data, ephemeris and clock
/// OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True
///

class SetIssueOfDataNavIC;
typedef std::shared_ptr<SetIssueOfDataNavIC> SetIssueOfDataNavICPtr;

class SetIssueOfDataNavIC : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIssueOfDataNavIC";
  inline static const char* const Documentation =
    "Set NavIC Issue of data, Ephemeris and Clock (IODEC)\n"
    "\n"
    "Name              Type          Description\n"
    "----------------- ------------- -------------------------------------------------------\n"
    "EphemerisAndClock int           Issue of data, ephemeris and clock\n"
    "OverrideRinex     optional bool If the IODEC overrides the RINEX IODEC, default is True";
  inline static const char* const TargetId = "";

  SetIssueOfDataNavIC() : CommandBase(CmdName, TargetId) {}

  SetIssueOfDataNavIC(int ephemerisAndClock, const std::optional<bool>& overrideRinex = {}) :
    CommandBase(CmdName, TargetId)
  {

    setEphemerisAndClock(ephemerisAndClock);
    setOverrideRinex(overrideRinex);
  }

  static SetIssueOfDataNavICPtr create(int ephemerisAndClock, const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<SetIssueOfDataNavIC>(ephemerisAndClock, overrideRinex);
  }

  static SetIssueOfDataNavICPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIssueOfDataNavIC>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["EphemerisAndClock"]) &&
           parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"EphemerisAndClock", "OverrideRinex"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int ephemerisAndClock() const { return parse_json<int>::parse(m_values["EphemerisAndClock"]); }

  void setEphemerisAndClock(int ephemerisAndClock)
  {
    m_values.AddMember("EphemerisAndClock",
                       parse_json<int>::format(ephemerisAndClock, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<bool> overrideRinex() const
  {
    return parse_json<std::optional<bool>>::parse(m_values["OverrideRinex"]);
  }

  void setOverrideRinex(const std::optional<bool>& overrideRinex)
  {
    m_values.AddMember("OverrideRinex",
                       parse_json<std::optional<bool>>::format(overrideRinex, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetIssueOfDataNavIC);
} // namespace Cmd
} // namespace Sdx
