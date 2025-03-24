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
/// Set the GIVEI for a ionospheric grid point
///
/// Name            Type            Description
/// --------------- --------------- -------------------------------
/// Band            int             The ionospheric grid band index
/// Point           int             The IGP index
/// GiveI           int             The GIVEI at the IGP
/// ServiceProvider optional string The service provider (optional)
///

class SetIonoGridGIVEI;
typedef std::shared_ptr<SetIonoGridGIVEI> SetIonoGridGIVEIPtr;

class SetIonoGridGIVEI : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIonoGridGIVEI";
  inline static const char* const Documentation = "Set the GIVEI for a ionospheric grid point\n"
                                                  "\n"
                                                  "Name            Type            Description\n"
                                                  "--------------- --------------- -------------------------------\n"
                                                  "Band            int             The ionospheric grid band index\n"
                                                  "Point           int             The IGP index\n"
                                                  "GiveI           int             The GIVEI at the IGP\n"
                                                  "ServiceProvider optional string The service provider (optional)";
  inline static const char* const TargetId = "";

  SetIonoGridGIVEI() : CommandBase(CmdName, TargetId) {}

  SetIonoGridGIVEI(int band, int point, int giveI, const std::optional<std::string>& serviceProvider = {}) :
    CommandBase(CmdName, TargetId)
  {

    setBand(band);
    setPoint(point);
    setGiveI(giveI);
    setServiceProvider(serviceProvider);
  }

  static SetIonoGridGIVEIPtr create(int band,
                                    int point,
                                    int giveI,
                                    const std::optional<std::string>& serviceProvider = {})
  {
    return std::make_shared<SetIonoGridGIVEI>(band, point, giveI, serviceProvider);
  }

  static SetIonoGridGIVEIPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIonoGridGIVEI>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetIonoGridGIVEI);
} // namespace Cmd
} // namespace Sdx
