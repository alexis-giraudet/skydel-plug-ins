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
/// Get all the message modification event's IDs for this navigation message family and SV ID.
///
/// Name         Type   Description
/// ------------ ------
/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// NavMsgFamily string Navigation message family key, accepted values : "GPS_LNAV", "GPS_CNAV", "GPS_CNAV2",
/// "GLONASS_NAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_CNAV1", "BEIDOU_CNAV2", "QZSS_LNAV",
/// "QZSS_SLAS", "NAVIC_NAV" and "SBAS_NAV" SvId         int    The satellite's SV ID
///

class GetAllMessageModificationIdsForNavMsgFamily;
typedef std::shared_ptr<GetAllMessageModificationIdsForNavMsgFamily> GetAllMessageModificationIdsForNavMsgFamilyPtr;

class GetAllMessageModificationIdsForNavMsgFamily : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAllMessageModificationIdsForNavMsgFamily";
  inline static const char* const Documentation =
    "Get all the message modification event's IDs for this navigation message family and SV ID.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "NavMsgFamily string Navigation message family key, accepted values : \"GPS_LNAV\", \"GPS_CNAV\", \"GPS_CNAV2\", \"GLONASS_NAV\", \"GALILEO_FNAV\", \"GALILEO_INAV\", \"BEIDOU_D1_NAV\", \"BEIDOU_CNAV1\", \"BEIDOU_CNAV2\", \"QZSS_LNAV\", \"QZSS_SLAS\", \"NAVIC_NAV\" and \"SBAS_NAV\"\n"
    "SvId         int    The satellite's SV ID";
  inline static const char* const TargetId = "";

  GetAllMessageModificationIdsForNavMsgFamily() : CommandBase(CmdName, TargetId) {}

  GetAllMessageModificationIdsForNavMsgFamily(const std::string& navMsgFamily, int svId) :
    CommandBase(CmdName, TargetId)
  {

    setNavMsgFamily(navMsgFamily);
    setSvId(svId);
  }

  static GetAllMessageModificationIdsForNavMsgFamilyPtr create(const std::string& navMsgFamily, int svId)
  {
    return std::make_shared<GetAllMessageModificationIdsForNavMsgFamily>(navMsgFamily, svId);
  }

  static GetAllMessageModificationIdsForNavMsgFamilyPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllMessageModificationIdsForNavMsgFamily>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["NavMsgFamily"]) &&
           parse_json<int>::is_valid(m_values["SvId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"NavMsgFamily", "SvId"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string navMsgFamily() const { return parse_json<std::string>::parse(m_values["NavMsgFamily"]); }

  void setNavMsgFamily(const std::string& navMsgFamily)
  {
    m_values.AddMember("NavMsgFamily",
                       parse_json<std::string>::format(navMsgFamily, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetAllMessageModificationIdsForNavMsgFamily);
} // namespace Cmd
} // namespace Sdx
