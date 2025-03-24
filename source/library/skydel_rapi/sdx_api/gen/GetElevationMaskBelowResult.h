#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetElevationMaskBelow.
///
/// Name  Type   Description
/// ----- ------ ---------------------------
/// Angle double Elevation mask angle in rad
///

class GetElevationMaskBelowResult;
typedef std::shared_ptr<GetElevationMaskBelowResult> GetElevationMaskBelowResultPtr;

class GetElevationMaskBelowResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetElevationMaskBelowResult";
  inline static const char* const Documentation = "Result of GetElevationMaskBelow.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ---------------------------\n"
                                                  "Angle double Elevation mask angle in rad";
  inline static const char* const TargetId = "";

  GetElevationMaskBelowResult() : CommandResult(CmdName, TargetId) {}

  GetElevationMaskBelowResult(double angle) : CommandResult(CmdName, TargetId) { setAngle(angle); }

  GetElevationMaskBelowResult(CommandBasePtr relatedCommand, double angle) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setAngle(angle);
  }

  static GetElevationMaskBelowResultPtr create(double angle)
  {
    return std::make_shared<GetElevationMaskBelowResult>(angle);
  }

  static GetElevationMaskBelowResultPtr create(CommandBasePtr relatedCommand, double angle)
  {
    return std::make_shared<GetElevationMaskBelowResult>(relatedCommand, angle);
  }

  static GetElevationMaskBelowResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetElevationMaskBelowResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["Angle"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Angle"};
    return names;
  }

  double angle() const { return parse_json<double>::parse(m_values["Angle"]); }

  void setAngle(double angle)
  {
    m_values.AddMember("Angle", parse_json<double>::format(angle, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetElevationMaskBelowResult);
} // namespace Cmd
} // namespace Sdx
