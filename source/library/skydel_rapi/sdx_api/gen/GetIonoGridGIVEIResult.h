#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIonoGridGIVEI.
///
/// Name            Type            Description
/// --------------- --------------- -------------------------------
/// Band            int             The ionospheric grid band index
/// Point           int             The IGP index
/// GiveI           int             The GIVEI at the IGP
/// ServiceProvider optional string The service provider (optional)
///

class GetIonoGridGIVEIResult;
typedef std::shared_ptr<GetIonoGridGIVEIResult> GetIonoGridGIVEIResultPtr;

class GetIonoGridGIVEIResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIonoGridGIVEIResult";
  inline static const char* const Documentation = "Result of GetIonoGridGIVEI.\n"
                                                  "\n"
                                                  "Name            Type            Description\n"
                                                  "--------------- --------------- -------------------------------\n"
                                                  "Band            int             The ionospheric grid band index\n"
                                                  "Point           int             The IGP index\n"
                                                  "GiveI           int             The GIVEI at the IGP\n"
                                                  "ServiceProvider optional string The service provider (optional)";
  inline static const char* const TargetId = "";

  GetIonoGridGIVEIResult() : CommandResult(CmdName, TargetId) {}

  GetIonoGridGIVEIResult(int band, int point, int giveI, const std::optional<std::string>& serviceProvider = {}) :
    CommandResult(CmdName, TargetId)
  {

    setBand(band);
    setPoint(point);
    setGiveI(giveI);
    setServiceProvider(serviceProvider);
  }

  GetIonoGridGIVEIResult(CommandBasePtr relatedCommand,
                         int band,
                         int point,
                         int giveI,
                         const std::optional<std::string>& serviceProvider = {}) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setBand(band);
    setPoint(point);
    setGiveI(giveI);
    setServiceProvider(serviceProvider);
  }

  static GetIonoGridGIVEIResultPtr create(int band,
                                          int point,
                                          int giveI,
                                          const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<GetIonoGridGIVEIResult>(band, point, giveI, serviceProvider);
  }

  static GetIonoGridGIVEIResultPtr create(CommandBasePtr relatedCommand,
                                          int band,
                                          int point,
                                          int giveI,
                                          const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<GetIonoGridGIVEIResult>(relatedCommand, band, point, giveI, serviceProvider);
  }

  static GetIonoGridGIVEIResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridGIVEIResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Band"]) &&
           parse_json<int>::is_valid(m_values["Point"]) && parse_json<int>::is_valid(m_values["GiveI"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "Point", "GiveI", "ServiceProvider"};
    return names;
  }

  int band() const { return parse_json<int>::parse(m_values["Band"]); }

  void setBand(int band)
  {
    m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int point() const { return parse_json<int>::parse(m_values["Point"]); }

  void setPoint(int point)
  {
    m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int giveI() const { return parse_json<int>::parse(m_values["GiveI"]); }

  void setGiveI(int giveI)
  {
    m_values.AddMember("GiveI", parse_json<int>::format(giveI, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(GetIonoGridGIVEIResult);
} // namespace Cmd
} // namespace Sdx
