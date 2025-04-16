#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
///
/// Name      Type Description
/// --------- ---- ------------------------
/// Clock     int  Issue of data, clock
/// Ephemeris int  Issue of data, ephemeris
///

class SetIssueOfDataBeiDou;
typedef std::shared_ptr<SetIssueOfDataBeiDou> SetIssueOfDataBeiDouPtr;

class SetIssueOfDataBeiDou : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIssueOfDataBeiDou";
  inline static const char* const Documentation =
    "Set BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)\n"
    "\n"
    "Name      Type Description\n"
    "--------- ---- ------------------------\n"
    "Clock     int  Issue of data, clock\n"
    "Ephemeris int  Issue of data, ephemeris";
  inline static const char* const TargetId = "";

  SetIssueOfDataBeiDou() : CommandBase(CmdName, TargetId) {}

  SetIssueOfDataBeiDou(int clock, int ephemeris) : CommandBase(CmdName, TargetId)
  {

    setClock(clock);
    setEphemeris(ephemeris);
  }

  static SetIssueOfDataBeiDouPtr create(int clock, int ephemeris)
  {
    return std::make_shared<SetIssueOfDataBeiDou>(clock, ephemeris);
  }

  static SetIssueOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIssueOfDataBeiDou>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Clock"]) &&
           parse_json<int>::is_valid(m_values["Ephemeris"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Clock", "Ephemeris"};
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
};
REGISTER_COMMAND_TO_FACTORY(SetIssueOfDataBeiDou);
} // namespace Cmd
} // namespace Sdx
