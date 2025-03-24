#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the ephemeris reference time for a SBAS satellite.
///
/// Name Type Description
/// ---- ---- ----------------------
/// SvId int  The satellite's SV ID.
///

class GetSbasEphemerisReferenceTimeForSV;
typedef std::shared_ptr<GetSbasEphemerisReferenceTimeForSV> GetSbasEphemerisReferenceTimeForSVPtr;

class GetSbasEphemerisReferenceTimeForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSbasEphemerisReferenceTimeForSV";
  inline static const char* const Documentation = "Get the ephemeris reference time for a SBAS satellite.\n"
                                                  "\n"
                                                  "Name Type Description\n"
                                                  "---- ---- ----------------------\n"
                                                  "SvId int  The satellite's SV ID.";
  inline static const char* const TargetId = "";

  GetSbasEphemerisReferenceTimeForSV() : CommandBase(CmdName, TargetId) {}

  GetSbasEphemerisReferenceTimeForSV(int svId) : CommandBase(CmdName, TargetId) { setSvId(svId); }

  static GetSbasEphemerisReferenceTimeForSVPtr create(int svId)
  {
    return std::make_shared<GetSbasEphemerisReferenceTimeForSV>(svId);
  }

  static GetSbasEphemerisReferenceTimeForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSbasEphemerisReferenceTimeForSV>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSbasEphemerisReferenceTimeForSV);
} // namespace Cmd
} // namespace Sdx
