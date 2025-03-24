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
/// Set GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
///
/// Name          Type          Description
/// ------------- ------------- ---------------------------------------------------
/// Clock         int           Issue of data, clock
/// Ephemeris     int           Issue of data, ephemeris
/// OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True
///

class SetIssueOfData;
typedef std::shared_ptr<SetIssueOfData> SetIssueOfDataPtr;

class SetIssueOfData : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIssueOfData";
  inline static const char* const Documentation =
    "Set GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)\n"
    "\n"
    "Name          Type          Description\n"
    "------------- ------------- ---------------------------------------------------\n"
    "Clock         int           Issue of data, clock\n"
    "Ephemeris     int           Issue of data, ephemeris\n"
    "OverrideRinex optional bool If the IOD overrides the RINEX IOD, default is True";
  inline static const char* const TargetId = "";

  SetIssueOfData() : CommandBase(CmdName, TargetId) {}

  SetIssueOfData(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {}) :
    CommandBase(CmdName, TargetId)
  {

    setClock(clock);
    setEphemeris(ephemeris);
    setOverrideRinex(overrideRinex);
  }

  static SetIssueOfDataPtr create(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<SetIssueOfData>(clock, ephemeris, overrideRinex);
  }

  static SetIssueOfDataPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIssueOfData>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Clock"]) &&
           parse_json<int>::is_valid(m_values["Ephemeris"]) &&
           parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Clock", "Ephemeris", "OverrideRinex"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int clock() const { return parse_json<int>::parse(m_values["Clock"]); }

  void setClock(int clock)
  {
    m_values.AddMember("Clock", parse_json<int>::format(clock, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int ephemeris() const { return parse_json<int>::parse(m_values["Ephemeris"]); }

  void setEphemeris(int ephemeris)
  {
    m_values.AddMember("Ephemeris",
                       parse_json<int>::format(ephemeris, m_values.GetAllocator()),
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
REGISTER_COMMAND_TO_FACTORY(SetIssueOfData);
} // namespace Cmd
} // namespace Sdx
