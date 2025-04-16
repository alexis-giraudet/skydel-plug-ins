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
/// Clear all message modification events for this navigation message family.
///
/// Name         Type   Description
/// ------------ ------
/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// NavMsgFamily string Navigation message family key, accepted values : "GPS_LNAV", "GPS_CNAV", "GPS_CNAV2",
/// "GLONASS_NAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_CNAV1", "BEIDOU_CNAV2", "QZSS_LNAV",
/// "QZSS_SLAS", "NAVIC_NAV" and "SBAS_NAV"
///

class ClearAllMessageModificationsForNavMsgFamily;
typedef std::shared_ptr<ClearAllMessageModificationsForNavMsgFamily> ClearAllMessageModificationsForNavMsgFamilyPtr;

class ClearAllMessageModificationsForNavMsgFamily : public CommandBase
{
public:
  inline static const char* const CmdName = "ClearAllMessageModificationsForNavMsgFamily";
  inline static const char* const Documentation =
    "Clear all message modification events for this navigation message family.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "NavMsgFamily string Navigation message family key, accepted values : \"GPS_LNAV\", \"GPS_CNAV\", \"GPS_CNAV2\", \"GLONASS_NAV\", \"GALILEO_FNAV\", \"GALILEO_INAV\", \"BEIDOU_D1_NAV\", \"BEIDOU_CNAV1\", \"BEIDOU_CNAV2\", \"QZSS_LNAV\", \"QZSS_SLAS\", \"NAVIC_NAV\" and \"SBAS_NAV\"";
  inline static const char* const TargetId = "";

  ClearAllMessageModificationsForNavMsgFamily() : CommandBase(CmdName, TargetId) {}

  ClearAllMessageModificationsForNavMsgFamily(const std::string& navMsgFamily) : CommandBase(CmdName, TargetId)
  {

    setNavMsgFamily(navMsgFamily);
  }

  static ClearAllMessageModificationsForNavMsgFamilyPtr create(const std::string& navMsgFamily)
  {
    return std::make_shared<ClearAllMessageModificationsForNavMsgFamily>(navMsgFamily);
  }

  static ClearAllMessageModificationsForNavMsgFamilyPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ClearAllMessageModificationsForNavMsgFamily>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["NavMsgFamily"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"NavMsgFamily"};
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
};
REGISTER_COMMAND_TO_FACTORY(ClearAllMessageModificationsForNavMsgFamily);
} // namespace Cmd
} // namespace Sdx
