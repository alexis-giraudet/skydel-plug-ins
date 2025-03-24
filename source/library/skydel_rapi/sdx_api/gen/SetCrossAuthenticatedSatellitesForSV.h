#pragma once

#include <memory>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the list of satellites that are cross-authenticated by the specified satellite.
///
/// Name     Type      Description
/// -------- --------- -------------------------------------------------------------------
/// SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).
/// SvIdList array int A list of the cross-authenticated satellites' SV IDs.
///

class SetCrossAuthenticatedSatellitesForSV;
typedef std::shared_ptr<SetCrossAuthenticatedSatellitesForSV> SetCrossAuthenticatedSatellitesForSVPtr;

class SetCrossAuthenticatedSatellitesForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "SetCrossAuthenticatedSatellitesForSV";
  inline static const char* const Documentation =
    "Set the list of satellites that are cross-authenticated by the specified satellite.\n"
    "\n"
    "Name     Type      Description\n"
    "-------- --------- -------------------------------------------------------------------\n"
    "SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).\n"
    "SvIdList array int A list of the cross-authenticated satellites' SV IDs.";
  inline static const char* const TargetId = "";

  SetCrossAuthenticatedSatellitesForSV() : CommandBase(CmdName, TargetId) {}

  SetCrossAuthenticatedSatellitesForSV(int svId, const std::vector<int>& svIdList) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setSvIdList(svIdList);
  }

  static SetCrossAuthenticatedSatellitesForSVPtr create(int svId, const std::vector<int>& svIdList)
  {
    return std::make_shared<SetCrossAuthenticatedSatellitesForSV>(svId, svIdList);
  }

  static SetCrossAuthenticatedSatellitesForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetCrossAuthenticatedSatellitesForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["SvIdList"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "SvIdList"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::vector<int> svIdList() const { return parse_json<std::vector<int>>::parse(m_values["SvIdList"]); }

  void setSvIdList(const std::vector<int>& svIdList)
  {
    m_values.AddMember("SvIdList",
                       parse_json<std::vector<int>>::format(svIdList, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetCrossAuthenticatedSatellitesForSV);
} // namespace Cmd
} // namespace Sdx
