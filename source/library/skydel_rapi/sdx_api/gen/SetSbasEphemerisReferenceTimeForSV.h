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
/// Set the ephemeris reference time for a SBAS satellite.
///
/// Name Type     Description
/// ---- -------- ---------------------------------------------------------------
/// SvId int      The satellite's SV ID.
/// Time datetime GPS date and time (it is the GPS time expressed in UTC format).
///

class SetSbasEphemerisReferenceTimeForSV;
typedef std::shared_ptr<SetSbasEphemerisReferenceTimeForSV> SetSbasEphemerisReferenceTimeForSVPtr;

class SetSbasEphemerisReferenceTimeForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetSbasEphemerisReferenceTimeForSV";
  inline static const char* const Documentation =
    "Set the ephemeris reference time for a SBAS satellite.\n"
    "\n"
    "Name Type     Description\n"
    "---- -------- ---------------------------------------------------------------\n"
    "SvId int      The satellite's SV ID.\n"
    "Time datetime GPS date and time (it is the GPS time expressed in UTC format).";
  inline static const char* const TargetId = "";

  SetSbasEphemerisReferenceTimeForSV() : CommandBase(CmdName, TargetId) {}

  SetSbasEphemerisReferenceTimeForSV(int svId, const Sdx::DateTime& time) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setTime(time);
  }

  static SetSbasEphemerisReferenceTimeForSVPtr create(int svId, const Sdx::DateTime& time)
  {
    return std::make_shared<SetSbasEphemerisReferenceTimeForSV>(svId, time);
  }

  static SetSbasEphemerisReferenceTimeForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetSbasEphemerisReferenceTimeForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<Sdx::DateTime>::is_valid(m_values["Time"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Time"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  Sdx::DateTime time() const { return parse_json<Sdx::DateTime>::parse(m_values["Time"]); }

  void setTime(const Sdx::DateTime& time)
  {
    m_values.AddMember("Time",
                       parse_json<Sdx::DateTime>::format(time, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetSbasEphemerisReferenceTimeForSV);
} // namespace Cmd
} // namespace Sdx
