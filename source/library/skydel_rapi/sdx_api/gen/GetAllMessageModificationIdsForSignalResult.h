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
/// Result of GetAllMessageModificationIdsForSignal.
///
/// Name Type         Description
/// ---- ------------ -------------------------------------------------------------------------
/// Ids  array string List of event IDs which will modify the navigation message for this SV ID
///

class GetAllMessageModificationIdsForSignalResult;
typedef std::shared_ptr<GetAllMessageModificationIdsForSignalResult> GetAllMessageModificationIdsForSignalResultPtr;

class GetAllMessageModificationIdsForSignalResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllMessageModificationIdsForSignalResult";
  inline static const char* const Documentation =
    "Result of GetAllMessageModificationIdsForSignal.\n"
    "\n"
    "Name Type         Description\n"
    "---- ------------ -------------------------------------------------------------------------\n"
    "Ids  array string List of event IDs which will modify the navigation message for this SV ID";
  inline static const char* const TargetId = "";

  GetAllMessageModificationIdsForSignalResult() : CommandResult(CmdName, TargetId) {}

  GetAllMessageModificationIdsForSignalResult(const std::vector<std::string>& ids) : CommandResult(CmdName, TargetId)
  {

    setIds(ids);
  }

  GetAllMessageModificationIdsForSignalResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIds(ids);
  }

  static GetAllMessageModificationIdsForSignalResultPtr create(const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllMessageModificationIdsForSignalResult>(ids);
  }

  static GetAllMessageModificationIdsForSignalResultPtr create(CommandBasePtr relatedCommand,
                                                               const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllMessageModificationIdsForSignalResult>(relatedCommand, ids);
  }

  static GetAllMessageModificationIdsForSignalResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllMessageModificationIdsForSignalResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAllMessageModificationIdsForSignalResult);
} // namespace Cmd
} // namespace Sdx
