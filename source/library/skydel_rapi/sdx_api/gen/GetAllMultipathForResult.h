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
/// Result of GetAllMultipathFor(Signal|SV|System) commands.
///
/// Name Type         Description
/// ---- ------------ ------------------------------------------------------
/// Ids  array string IDs of multipaths for the specified argument in getter
///

class GetAllMultipathForResult;
typedef std::shared_ptr<GetAllMultipathForResult> GetAllMultipathForResultPtr;

class GetAllMultipathForResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllMultipathForResult";
  inline static const char* const Documentation =
    "Result of GetAllMultipathFor(Signal|SV|System) commands.\n"
    "\n"
    "Name Type         Description\n"
    "---- ------------ ------------------------------------------------------\n"
    "Ids  array string IDs of multipaths for the specified argument in getter";
  inline static const char* const TargetId = "";

  GetAllMultipathForResult() : CommandResult(CmdName, TargetId) {}

  GetAllMultipathForResult(const std::vector<std::string>& ids) : CommandResult(CmdName, TargetId) { setIds(ids); }

  GetAllMultipathForResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIds(ids);
  }

  static GetAllMultipathForResultPtr create(const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllMultipathForResult>(ids);
  }

  static GetAllMultipathForResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllMultipathForResult>(relatedCommand, ids);
  }

  static GetAllMultipathForResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllMultipathForResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAllMultipathForResult);
} // namespace Cmd
} // namespace Sdx
