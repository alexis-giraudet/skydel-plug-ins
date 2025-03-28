#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIonoGridError.
///
/// Name  Type   Description
/// ----- ------ -------------------------------
/// Band  int    The ionospheric grid band index
/// Point int    The IGP index
/// Error double The error offset at the IGP
///

class GetIonoGridErrorResult;
typedef std::shared_ptr<GetIonoGridErrorResult> GetIonoGridErrorResultPtr;

class GetIonoGridErrorResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIonoGridErrorResult";
  inline static const char* const Documentation = "Result of GetIonoGridError.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ -------------------------------\n"
                                                  "Band  int    The ionospheric grid band index\n"
                                                  "Point int    The IGP index\n"
                                                  "Error double The error offset at the IGP";
  inline static const char* const TargetId = "";

  GetIonoGridErrorResult() : CommandResult(CmdName, TargetId) {}

  GetIonoGridErrorResult(int band, int point, double error) : CommandResult(CmdName, TargetId)
  {

    setBand(band);
    setPoint(point);
    setError(error);
  }

  GetIonoGridErrorResult(CommandBasePtr relatedCommand, int band, int point, double error) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setBand(band);
    setPoint(point);
    setError(error);
  }

  static GetIonoGridErrorResultPtr create(int band, int point, double error)
  {
    return std::make_shared<GetIonoGridErrorResult>(band, point, error);
  }

  static GetIonoGridErrorResultPtr create(CommandBasePtr relatedCommand, int band, int point, double error)
  {
    return std::make_shared<GetIonoGridErrorResult>(relatedCommand, band, point, error);
  }

  static GetIonoGridErrorResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoGridErrorResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIonoGridErrorResult);
} // namespace Cmd
} // namespace Sdx
