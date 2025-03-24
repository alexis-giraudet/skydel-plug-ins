#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetSbasEphemerisReferenceTimeForSV.
///
/// Name Type     Description
/// ---- -------- ---------------------------------------------------------------
/// SvId int      The satellite's SV ID.
/// Time datetime GPS date and time (it is the GPS time expressed in UTC format).
///

class GetSbasEphemerisReferenceTimeForSVResult;
typedef std::shared_ptr<GetSbasEphemerisReferenceTimeForSVResult> GetSbasEphemerisReferenceTimeForSVResultPtr;

class GetSbasEphemerisReferenceTimeForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetSbasEphemerisReferenceTimeForSVResult";
  inline static const char* const Documentation =
    "Result of GetSbasEphemerisReferenceTimeForSV.\n"
    "\n"
    "Name Type     Description\n"
    "---- -------- ---------------------------------------------------------------\n"
    "SvId int      The satellite's SV ID.\n"
    "Time datetime GPS date and time (it is the GPS time expressed in UTC format).";
  inline static const char* const TargetId = "";

  GetSbasEphemerisReferenceTimeForSVResult() : CommandResult(CmdName, TargetId) {}

  GetSbasEphemerisReferenceTimeForSVResult(int svId, const Sdx::DateTime& time) : CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setTime(time);
  }

  GetSbasEphemerisReferenceTimeForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::DateTime& time) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setTime(time);
  }

  static GetSbasEphemerisReferenceTimeForSVResultPtr create(int svId, const Sdx::DateTime& time)
  {
    return std::make_shared<GetSbasEphemerisReferenceTimeForSVResult>(svId, time);
  }

  static GetSbasEphemerisReferenceTimeForSVResultPtr create(CommandBasePtr relatedCommand,
                                                            int svId,
                                                            const Sdx::DateTime& time)
  {
    return std::make_shared<GetSbasEphemerisReferenceTimeForSVResult>(relatedCommand, svId, time);
  }

  static GetSbasEphemerisReferenceTimeForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasEphemerisReferenceTimeForSVResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetSbasEphemerisReferenceTimeForSVResult);
} // namespace Cmd
} // namespace Sdx
