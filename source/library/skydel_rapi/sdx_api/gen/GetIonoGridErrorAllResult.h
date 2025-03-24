#pragma once

#include <memory>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIonoGridErrorAll.
///
/// Name Type               Description
/// ---- ------------------ -----------------------------------------------------------------------
/// Grid array array double Array containing each band, each band is an array containing the errors
///

class GetIonoGridErrorAllResult;
typedef std::shared_ptr<GetIonoGridErrorAllResult> GetIonoGridErrorAllResultPtr;

class GetIonoGridErrorAllResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIonoGridErrorAllResult";
  inline static const char* const Documentation =
    "Result of GetIonoGridErrorAll.\n"
    "\n"
    "Name Type               Description\n"
    "---- ------------------ -----------------------------------------------------------------------\n"
    "Grid array array double Array containing each band, each band is an array containing the errors";
  inline static const char* const TargetId = "";

  GetIonoGridErrorAllResult() : CommandResult(CmdName, TargetId) {}

  GetIonoGridErrorAllResult(const std::vector<std::vector<double>>& grid) : CommandResult(CmdName, TargetId)
  {

    setGrid(grid);
  }

  GetIonoGridErrorAllResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& grid) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setGrid(grid);
  }

  static GetIonoGridErrorAllResultPtr create(const std::vector<std::vector<double>>& grid)
  {
    return std::make_shared<GetIonoGridErrorAllResult>(grid);
  }

  static GetIonoGridErrorAllResultPtr create(CommandBasePtr relatedCommand,
                                             const std::vector<std::vector<double>>& grid)
  {
    return std::make_shared<GetIonoGridErrorAllResult>(relatedCommand, grid);
  }

  static GetIonoGridErrorAllResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridErrorAllResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Grid"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Grid"};
    return names;
  }

  std::vector<std::vector<double>> grid() const
  {
    return parse_json<std::vector<std::vector<double>>>::parse(m_values["Grid"]);
  }

  void setGrid(const std::vector<std::vector<double>>& grid)
  {
    m_values.AddMember("Grid",
                       parse_json<std::vector<std::vector<double>>>::format(grid, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIonoGridErrorAllResult);
} // namespace Cmd
} // namespace Sdx
