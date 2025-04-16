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
/// Result of GetAllMerkleTreeID.
///
/// Name Type         Description
/// ---- ------------ ----------------------------------------
/// Ids  array string Array of Merkle Trees unique identifiers
///

class GetAllMerkleTreeIDResult;
typedef std::shared_ptr<GetAllMerkleTreeIDResult> GetAllMerkleTreeIDResultPtr;

class GetAllMerkleTreeIDResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetAllMerkleTreeIDResult";
  inline static const char* const Documentation = "Result of GetAllMerkleTreeID.\n"
                                                  "\n"
                                                  "Name Type         Description\n"
                                                  "---- ------------ ----------------------------------------\n"
                                                  "Ids  array string Array of Merkle Trees unique identifiers";
  inline static const char* const TargetId = "";

  GetAllMerkleTreeIDResult() : CommandResult(CmdName, TargetId) {}

  GetAllMerkleTreeIDResult(const std::vector<std::string>& ids) : CommandResult(CmdName, TargetId) { setIds(ids); }

  GetAllMerkleTreeIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIds(ids);
  }

  static GetAllMerkleTreeIDResultPtr create(const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllMerkleTreeIDResult>(ids);
  }

  static GetAllMerkleTreeIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
  {
    return std::make_shared<GetAllMerkleTreeIDResult>(relatedCommand, ids);
  }

  static GetAllMerkleTreeIDResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllMerkleTreeIDResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAllMerkleTreeIDResult);
} // namespace Cmd
} // namespace Sdx
