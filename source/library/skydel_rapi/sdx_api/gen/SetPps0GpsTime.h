#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the 0th PPS' date time
///
/// Name    Type     Description
/// ------- -------- --------------------------------------------------------------
/// GpsTime datetime GPS date and time (it is the GPS time expressed in UTC format)
///

class SetPps0GpsTime;
typedef std::shared_ptr<SetPps0GpsTime> SetPps0GpsTimePtr;

class SetPps0GpsTime : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPps0GpsTime";
  inline static const char* const Documentation =
    "Set the 0th PPS' date time\n"
    "\n"
    "Name    Type     Description\n"
    "------- -------- --------------------------------------------------------------\n"
    "GpsTime datetime GPS date and time (it is the GPS time expressed in UTC format)";
  inline static const char* const TargetId = "";

  SetPps0GpsTime() : CommandBase(CmdName, TargetId) {}

  SetPps0GpsTime(const Sdx::DateTime& gpsTime) : CommandBase(CmdName, TargetId) { setGpsTime(gpsTime); }

  static SetPps0GpsTimePtr create(const Sdx::DateTime& gpsTime) { return std::make_shared<SetPps0GpsTime>(gpsTime); }

  static SetPps0GpsTimePtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetPps0GpsTime>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::DateTime>::is_valid(m_values["GpsTime"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"GpsTime"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING; }

  Sdx::DateTime gpsTime() const { return parse_json<Sdx::DateTime>::parse(m_values["GpsTime"]); }

  void setGpsTime(const Sdx::DateTime& gpsTime)
  {
    m_values.AddMember("GpsTime",
                       parse_json<Sdx::DateTime>::format(gpsTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPps0GpsTime);
} // namespace Cmd
} // namespace Sdx
