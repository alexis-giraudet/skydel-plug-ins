#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIonoGridGIVEIAll.
///
/// Name            Type            Description
/// --------------- --------------- ----------------------------------------------------------------------
/// Grid            array array int Array containing each band, each band is an array containing the GIVEI
/// ServiceProvider optional string The service provider (optional)
///

class GetIonoGridGIVEIAllResult;
typedef std::shared_ptr<GetIonoGridGIVEIAllResult> GetIonoGridGIVEIAllResultPtr;

class GetIonoGridGIVEIAllResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIonoGridGIVEIAllResult";
  inline static const char* const Documentation =
    "Result of GetIonoGridGIVEIAll.\n"
    "\n"
    "Name            Type            Description\n"
    "--------------- --------------- ----------------------------------------------------------------------\n"
    "Grid            array array int Array containing each band, each band is an array containing the GIVEI\n"
    "ServiceProvider optional string The service provider (optional)";
  inline static const char* const TargetId = "";

  GetIonoGridGIVEIAllResult() : CommandResult(CmdName, TargetId) {}

  GetIonoGridGIVEIAllResult(const std::vector<std::vector<int>>& grid,
                            const std::optional<std::string>& serviceProvider = {}) :
    CommandResult(CmdName, TargetId)
  {

    setGrid(grid);
    setServiceProvider(serviceProvider);
  }

  GetIonoGridGIVEIAllResult(CommandBasePtr relatedCommand,
                            const std::vector<std::vector<int>>& grid,
                            const std::optional<std::string>& serviceProvider = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setGrid(grid);
    setServiceProvider(serviceProvider);
  }

  static GetIonoGridGIVEIAllResultPtr create(const std::vector<std::vector<int>>& grid,
                                             const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<GetIonoGridGIVEIAllResult>(grid, serviceProvider);
  }

  static GetIonoGridGIVEIAllResultPtr create(CommandBasePtr relatedCommand,
                                             const std::vector<std::vector<int>>& grid,
                                             const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<GetIonoGridGIVEIAllResult>(relatedCommand, grid, serviceProvider);
  }

  static GetIonoGridGIVEIAllResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridGIVEIAllResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::vector<int>>>::is_valid(m_values["Grid"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Grid", "ServiceProvider"};
    return names;
  }

  std::vector<std::vector<int>> grid() const
  {
    return parse_json<std::vector<std::vector<int>>>::parse(m_values["Grid"]);
  }

  void setGrid(const std::vector<std::vector<int>>& grid)
  {
    m_values.AddMember("Grid",
                       parse_json<std::vector<std::vector<int>>>::format(grid, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<std::string> serviceProvider() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
  }

  void setServiceProvider(const std::optional<std::string>& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIonoGridGIVEIAllResult);
} // namespace Cmd
} // namespace Sdx
