#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the GIVEI for a ionospheric grid point
///
/// Name            Type            Description
/// --------------- --------------- -------------------------------
/// Band            int             The ionospheric grid band index
/// Point           int             The IGP index
/// ServiceProvider optional string The service provider (optional)
///

class GetIonoGridGIVEI;
typedef std::shared_ptr<GetIonoGridGIVEI> GetIonoGridGIVEIPtr;

class GetIonoGridGIVEI : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIonoGridGIVEI";
  inline static const char* const Documentation = "Get the GIVEI for a ionospheric grid point\n"
                                                  "\n"
                                                  "Name            Type            Description\n"
                                                  "--------------- --------------- -------------------------------\n"
                                                  "Band            int             The ionospheric grid band index\n"
                                                  "Point           int             The IGP index\n"
                                                  "ServiceProvider optional string The service provider (optional)";
  inline static const char* const TargetId = "";

  GetIonoGridGIVEI() : CommandBase(CmdName, TargetId) {}

  GetIonoGridGIVEI(int band, int point, const std::optional<std::string>& serviceProvider = {}) :
    CommandBase(CmdName, TargetId)
  {

    setBand(band);
    setPoint(point);
    setServiceProvider(serviceProvider);
  }

  static GetIonoGridGIVEIPtr create(int band, int point, const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<GetIonoGridGIVEI>(band, point, serviceProvider);
  }

  static GetIonoGridGIVEIPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridGIVEI>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Band"]) &&
           parse_json<int>::is_valid(m_values["Point"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "Point", "ServiceProvider"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(GetIonoGridGIVEI);
} // namespace Cmd
} // namespace Sdx
