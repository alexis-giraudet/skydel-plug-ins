#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetOsnmaMacLtId.
///
/// Name    Type Description
/// ------- ----
/// ---------------------------------------------------------------------------------------------------------------------------
/// MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36,
/// 37, 38, 39, 40 and 41.
///              Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.
///

class GetOsnmaMacLtIdResult;
typedef std::shared_ptr<GetOsnmaMacLtIdResult> GetOsnmaMacLtIdResultPtr;

class GetOsnmaMacLtIdResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetOsnmaMacLtIdResult";
  inline static const char* const Documentation =
    "Result of GetOsnmaMacLtId.\n"
    "\n"
    "Name    Type Description\n"
    "------- ---- ---------------------------------------------------------------------------------------------------------------------------\n"
    "MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.\n"
    "             Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.";
  inline static const char* const TargetId = "";

  GetOsnmaMacLtIdResult() : CommandResult(CmdName, TargetId) {}

  GetOsnmaMacLtIdResult(int macLtId) : CommandResult(CmdName, TargetId) { setMacLtId(macLtId); }

  GetOsnmaMacLtIdResult(CommandBasePtr relatedCommand, int macLtId) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setMacLtId(macLtId);
  }

  static GetOsnmaMacLtIdResultPtr create(int macLtId) { return std::make_shared<GetOsnmaMacLtIdResult>(macLtId); }

  static GetOsnmaMacLtIdResultPtr create(CommandBasePtr relatedCommand, int macLtId)
  {
    return std::make_shared<GetOsnmaMacLtIdResult>(relatedCommand, macLtId);
  }

  static GetOsnmaMacLtIdResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetOsnmaMacLtIdResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["MacLtId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"MacLtId"};
    return names;
  }

  int macLtId() const { return parse_json<int>::parse(m_values["MacLtId"]); }

  void setMacLtId(int macLtId)
  {
    m_values.AddMember("MacLtId", parse_json<int>::format(macLtId, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetOsnmaMacLtIdResult);
} // namespace Cmd
} // namespace Sdx
