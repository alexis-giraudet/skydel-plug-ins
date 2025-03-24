#pragma once

#include <memory>
#include <optional>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIssueOfDataGalileo.
///
/// Name          Type          Description
/// ------------- ------------- ---------------------------------------------------------
/// Navigation    int           Issue of data, navigation
/// Almanac       int           Issue of data, almanac
/// OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True
///

class GetIssueOfDataGalileoResult;
typedef std::shared_ptr<GetIssueOfDataGalileoResult> GetIssueOfDataGalileoResultPtr;

class GetIssueOfDataGalileoResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIssueOfDataGalileoResult";
  inline static const char* const Documentation =
    "Result of GetIssueOfDataGalileo.\n"
    "\n"
    "Name          Type          Description\n"
    "------------- ------------- ---------------------------------------------------------\n"
    "Navigation    int           Issue of data, navigation\n"
    "Almanac       int           Issue of data, almanac\n"
    "OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True";
  inline static const char* const TargetId = "";

  GetIssueOfDataGalileoResult() : CommandResult(CmdName, TargetId) {}

  GetIssueOfDataGalileoResult(int navigation, int almanac, const std::optional<bool>& overrideRinex = {}) :
    CommandResult(CmdName, TargetId)
  {

    setNavigation(navigation);
    setAlmanac(almanac);
    setOverrideRinex(overrideRinex);
  }

  GetIssueOfDataGalileoResult(CommandBasePtr relatedCommand,
                              int navigation,
                              int almanac,
                              const std::optional<bool>& overrideRinex = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setNavigation(navigation);
    setAlmanac(almanac);
    setOverrideRinex(overrideRinex);
  }

  static GetIssueOfDataGalileoResultPtr create(int navigation,
                                               int almanac,
                                               const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<GetIssueOfDataGalileoResult>(navigation, almanac, overrideRinex);
  }

  static GetIssueOfDataGalileoResultPtr create(CommandBasePtr relatedCommand,
                                               int navigation,
                                               int almanac,
                                               const std::optional<bool>& overrideRinex = {})
  {
    return std::make_shared<GetIssueOfDataGalileoResult>(relatedCommand, navigation, almanac, overrideRinex);
  }

  static GetIssueOfDataGalileoResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIssueOfDataGalileoResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataGalileoResult);
} // namespace Cmd
} // namespace Sdx
