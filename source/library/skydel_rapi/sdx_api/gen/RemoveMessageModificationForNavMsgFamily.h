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
/// Removes a message modification event for the navigation message family.
///
/// Name         Type   Description
/// ------------ ------
/// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// NavMsgFamily string Navigation message family key, accepted values : "GPS_LNAV", "GPS_CNAV", "GPS_CNAV2",
/// "GLONASS_NAV", "GALILEO_FNAV", "GALILEO_INAV", "BEIDOU_D1_NAV", "BEIDOU_CNAV1", "BEIDOU_CNAV2", "QZSS_LNAV",
/// "QZSS_SLAS", "NAVIC_NAV" and "SBAS_NAV" Id           string Unique identifier
///

class RemoveMessageModificationForNavMsgFamily;
typedef std::shared_ptr<RemoveMessageModificationForNavMsgFamily> RemoveMessageModificationForNavMsgFamilyPtr;

class RemoveMessageModificationForNavMsgFamily : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveMessageModificationForNavMsgFamily";
  inline static const char* const Documentation =
    "Removes a message modification event for the navigation message family.\n"
    "\n"
    "Name         Type   Description\n"
    "------------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "NavMsgFamily string Navigation message family key, accepted values : \"GPS_LNAV\", \"GPS_CNAV\", \"GPS_CNAV2\", \"GLONASS_NAV\", \"GALILEO_FNAV\", \"GALILEO_INAV\", \"BEIDOU_D1_NAV\", \"BEIDOU_CNAV1\", \"BEIDOU_CNAV2\", \"QZSS_LNAV\", \"QZSS_SLAS\", \"NAVIC_NAV\" and \"SBAS_NAV\"\n"
    "Id           string Unique identifier";
  inline static const char* const TargetId = "";

  RemoveMessageModificationForNavMsgFamily() : CommandBase(CmdName, TargetId) {}

  RemoveMessageModificationForNavMsgFamily(const std::string& navMsgFamily, const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setNavMsgFamily(navMsgFamily);
    setId(id);
  }

  static RemoveMessageModificationForNavMsgFamilyPtr create(const std::string& navMsgFamily, const std::string& id)
  {
    return std::make_shared<RemoveMessageModificationForNavMsgFamily>(navMsgFamily, id);
  }

  static RemoveMessageModificationForNavMsgFamilyPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveMessageModificationForNavMsgFamily>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["NavMsgFamily"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"NavMsgFamily", "Id"};
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

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RemoveMessageModificationForNavMsgFamily);
} // namespace Cmd
} // namespace Sdx
