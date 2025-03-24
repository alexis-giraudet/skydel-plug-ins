#pragma once

#include <memory>
#include <optional>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetAgeOfDataBeiDou.
///
/// Name          Type          Description
/// ------------- ------------- ---------------------------------------------------
/// Clock         int           Age of data, clock
/// Ephemeris     int           Age of data, ephemeris
/// OverrideRinex optional bool If the AOD overrides the RINEX AOD, default is True
///

class GetAgeOfDataBeiDouResult;
typedef std::shared_ptr<GetAgeOfDataBeiDouResult> GetAgeOfDataBeiDouResultPtr;

class GetAgeOfDataBeiDouResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAgeOfDataBeiDouResult";
  inline static const char* const Documentation =
    "Result of GetAgeOfDataBeiDou.\n"
    "\n"
    "Name          Type          Description\n"
    "------------- ------------- ---------------------------------------------------\n"
    "Clock         int           Age of data, clock\n"
    "Ephemeris     int           Age of data, ephemeris\n"
    "OverrideRinex optional bool If the AOD overrides the RINEX AOD, default is True";
  inline static const char* const TargetId = "";

  GetAgeOfDataBeiDouResult() : CommandResult(CmdName, TargetId) {}

  GetAgeOfDataBeiDouResult(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {}) :
    CommandResult(CmdName, TargetId)
  {

    setClock(clock);
    setEphemeris(ephemeris);
    setOverrideRinex(overrideRinex);
  }

  GetAgeOfDataBeiDouResult(CommandBasePtr relatedCommand,
                           int clock,
                           int ephemeris,
                           const std::optional<bool>& overrideRinex = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setClock(clock);
    setEphemeris(ephemeris);
    setOverrideRinex(overrideRinex);
  }

  static GetAgeOfDataBeiDouResultPtr create(int clock, int ephemeris, const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<GetAgeOfDataBeiDouResult>(clock, ephemeris, overrideRinex);
  }

  static GetAgeOfDataBeiDouResultPtr create(CommandBasePtr relatedCommand,
                                            int clock,
                                            int ephemeris,
                                            const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<GetAgeOfDataBeiDouResult>(relatedCommand, clock, ephemeris, overrideRinex);
  }

  static GetAgeOfDataBeiDouResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAgeOfDataBeiDouResult>(ptr);
  }

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
REGISTER_COMMAND_TO_FACTORY(GetAgeOfDataBeiDouResult);
} // namespace Cmd
} // namespace Sdx
