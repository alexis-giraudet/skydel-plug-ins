#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the flag for a ionospheric grid point in the SBAS message 18 mask
///
/// Name            Type   Description
/// --------------- ------ -------------------------------
/// ServiceProvider string The service provider
/// Band            int    The ionospheric grid band index
/// Point           int    The IGP index
///

class GetIonoGridMask;
typedef std::shared_ptr<GetIonoGridMask> GetIonoGridMaskPtr;

class GetIonoGridMask : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIonoGridMask";
  inline static const char* const Documentation =
    "Get the flag for a ionospheric grid point in the SBAS message 18 mask\n"
    "\n"
    "Name            Type   Description\n"
    "--------------- ------ -------------------------------\n"
    "ServiceProvider string The service provider\n"
    "Band            int    The ionospheric grid band index\n"
    "Point           int    The IGP index";
  inline static const char* const TargetId = "";

  GetIonoGridMask() : CommandBase(CmdName, TargetId) {}

  GetIonoGridMask(const std::string& serviceProvider, int band, int point) : CommandBase(CmdName, TargetId)
  {

    setServiceProvider(serviceProvider);
    setBand(band);
    setPoint(point);
  }

  static GetIonoGridMaskPtr create(const std::string& serviceProvider, int band, int point)
  {
    return std::make_shared<GetIonoGridMask>(serviceProvider, band, point);
  }

  static GetIonoGridMaskPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetIonoGridMask>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["ServiceProvider"]) &&
           parse_json<int>::is_valid(m_values["Band"]) && parse_json<int>::is_valid(m_values["Point"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"ServiceProvider", "Band", "Point"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string serviceProvider() const { return parse_json<std::string>::parse(m_values["ServiceProvider"]); }

  void setServiceProvider(const std::string& serviceProvider)
  {
    m_values.AddMember("ServiceProvider",
                       parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()),
                       m_values.GetAllocator());
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
};
REGISTER_COMMAND_TO_FACTORY(GetIonoGridMask);
} // namespace Cmd
} // namespace Sdx
