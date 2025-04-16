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
/// Result of GetAllIntTxID.
///
/// Name Type         Description
/// ---- ------------ ------------------------------------------
/// Ids  array string ID list of all interferences transmitters.
///

class GetAllIntTxIDResult;
typedef std::shared_ptr<GetAllIntTxIDResult> GetAllIntTxIDResultPtr;

class GetAllIntTxIDResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllIntTxIDResult";
  inline static const char* const Documentation = "Result of GetAllIntTxID.\n"
                                                  "\n"
                                                  "Name Type         Description\n"
                                                  "---- ------------ ------------------------------------------\n"
                                                  "Ids  array string ID list of all interferences transmitters.";
  inline static const char* const TargetId = "";

  GetAllIntTxIDResult() : CommandResult(CmdName, TargetId) {}

  GetAllIntTxIDResult(const std::vector<std::string>& ids) : CommandResult(CmdName, TargetId) { setIds(ids); }

  GetAllIntTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIds(ids);
  }

  static GetAllIntTxIDResultPtr create(const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllIntTxIDResult>(ids);
  }

  static GetAllIntTxIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllIntTxIDResult>(relatedCommand, ids);
  }

  static GetAllIntTxIDResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllIntTxIDResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAllIntTxIDResult);
} // namespace Cmd
} // namespace Sdx
