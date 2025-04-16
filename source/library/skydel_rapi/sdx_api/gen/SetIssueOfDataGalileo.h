#pragma once

#include <memory>
#include <optional>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)
///
/// Name          Type          Description
/// ------------- ------------- ---------------------------------------------------------
/// Navigation    int           Issue of data, navigation
/// Almanac       int           Issue of data, almanac
/// OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True
///

class SetIssueOfDataGalileo;
typedef std::shared_ptr<SetIssueOfDataGalileo> SetIssueOfDataGalileoPtr;

class SetIssueOfDataGalileo : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIssueOfDataGalileo";
  inline static const char* const Documentation =
    "Set Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)\n"
    "\n"
    "Name          Type          Description\n"
    "------------- ------------- ---------------------------------------------------------\n"
    "Navigation    int           Issue of data, navigation\n"
    "Almanac       int           Issue of data, almanac\n"
    "OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True";
  inline static const char* const TargetId = "";

  SetIssueOfDataGalileo() : CommandBase(CmdName, TargetId) {}

  SetIssueOfDataGalileo(int navigation, int almanac, const std::optional<bool>& overrideRinex = {}) :
    CommandBase(CmdName, TargetId)
  {

    setNavigation(navigation);
    setAlmanac(almanac);
    setOverrideRinex(overrideRinex);
  }

  static SetIssueOfDataGalileoPtr create(int navigation, int almanac, const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<SetIssueOfDataGalileo>(navigation, almanac, overrideRinex);
  }

  static SetIssueOfDataGalileoPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIssueOfDataGalileo>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Navigation"]) &&
           parse_json<int>::is_valid(m_values["Almanac"]) &&
           parse_json<std::optional<bool>>::is_valid(m_values["OverrideRinex"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Navigation", "Almanac", "OverrideRinex"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int navigation() const { return parse_json<int>::parse(m_values["Navigation"]); }

  void setNavigation(int navigation)
  {
    m_values.AddMember("Navigation",
                       parse_json<int>::format(navigation, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int almanac() const { return parse_json<int>::parse(m_values["Almanac"]); }

  void setAlmanac(int almanac)
  {
    m_values.AddMember("Almanac", parse_json<int>::format(almanac, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(SetIssueOfDataGalileo);
} // namespace Cmd
} // namespace Sdx
