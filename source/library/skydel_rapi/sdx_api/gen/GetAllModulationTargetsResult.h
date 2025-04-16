#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetAllModulationTargets.
///
/// Name Type         Description
/// ---- ------------ ---------------
/// Ids  array string list of all IDs
///

class GetAllModulationTargetsResult;
typedef std::shared_ptr<GetAllModulationTargetsResult> GetAllModulationTargetsResultPtr;

class GetAllModulationTargetsResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllModulationTargetsResult";
  inline static const char* const Documentation = "Result of GetAllModulationTargets.\n"
                                                  "\n"
                                                  "Name Type         Description\n"
                                                  "---- ------------ ---------------\n"
                                                  "Ids  array string list of all IDs";
  inline static const char* const TargetId = "";

  GetAllModulationTargetsResult() : CommandResult(CmdName, TargetId) {}

  GetAllModulationTargetsResult(const std::vector<std::string>& ids) : CommandResult(CmdName, TargetId) { setIds(ids); }

  GetAllModulationTargetsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIds(ids);
  }

  static GetAllModulationTargetsResultPtr create(const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllModulationTargetsResult>(ids);
  }

  static GetAllModulationTargetsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllModulationTargetsResult>(relatedCommand, ids);
  }

  static GetAllModulationTargetsResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllModulationTargetsResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Ids"};
    return names;
  }

  std::vector<std::string> ids() const { return parse_json<std::vector<std::string>>::parse(m_values["Ids"]); }

  void setIds(const std::vector<std::string>& ids)
  {
    m_values.AddMember("Ids",
                       parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetAllModulationTargetsResult);
} // namespace Cmd
} // namespace Sdx
