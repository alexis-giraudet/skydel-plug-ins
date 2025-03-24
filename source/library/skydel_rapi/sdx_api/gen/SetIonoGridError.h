#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the error offset for a ionospheric grid point
///
/// Name  Type   Description
/// ----- ------ -------------------------------
/// Band  int    The ionospheric grid band index
/// Point int    The IGP index
/// Error double The error offset at the IGP
///

class SetIonoGridError;
typedef std::shared_ptr<SetIonoGridError> SetIonoGridErrorPtr;

class SetIonoGridError : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIonoGridError";
  inline static const char* const Documentation = "Set the error offset for a ionospheric grid point\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ -------------------------------\n"
                                                  "Band  int    The ionospheric grid band index\n"
                                                  "Point int    The IGP index\n"
                                                  "Error double The error offset at the IGP";
  inline static const char* const TargetId = "";

  SetIonoGridError() : CommandBase(CmdName, TargetId) {}

  SetIonoGridError(int band, int point, double error) : CommandBase(CmdName, TargetId)
  {

    setBand(band);
    setPoint(point);
    setError(error);
  }

  static SetIonoGridErrorPtr create(int band, int point, double error)
  {
    return std::make_shared<SetIonoGridError>(band, point, error);
  }

  static SetIonoGridErrorPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIonoGridError>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Band"]) &&
           parse_json<int>::is_valid(m_values["Point"]) && parse_json<double>::is_valid(m_values["Error"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Band", "Point", "Error"};
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

  double error() const { return parse_json<double>::parse(m_values["Error"]); }

  void setError(double error)
  {
    m_values.AddMember("Error", parse_json<double>::format(error, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetIonoGridError);
} // namespace Cmd
} // namespace Sdx
