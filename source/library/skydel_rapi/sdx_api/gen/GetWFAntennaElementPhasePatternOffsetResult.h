#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetWFAntennaElementPhasePatternOffset.
///
/// Name        Type   Description
/// ----------- ------ -------------------------------------------------------------------------
/// PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]
/// Element     int    One-based index for element in antenna.
///

class GetWFAntennaElementPhasePatternOffsetResult;
typedef std::shared_ptr<GetWFAntennaElementPhasePatternOffsetResult> GetWFAntennaElementPhasePatternOffsetResultPtr;

class GetWFAntennaElementPhasePatternOffsetResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetWFAntennaElementPhasePatternOffsetResult";
  inline static const char* const Documentation =
    "Result of GetWFAntennaElementPhasePatternOffset.\n"
    "\n"
    "Name        Type   Description\n"
    "----------- ------ -------------------------------------------------------------------------\n"
    "PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]\n"
    "Element     int    One-based index for element in antenna.";
  inline static const char* const TargetId = "";

  GetWFAntennaElementPhasePatternOffsetResult() : CommandResult(CmdName, TargetId) {}

  GetWFAntennaElementPhasePatternOffsetResult(double phaseOffset, int element) : CommandResult(CmdName, TargetId)
  {

    setPhaseOffset(phaseOffset);
    setElement(element);
  }

  GetWFAntennaElementPhasePatternOffsetResult(CommandBasePtr relatedCommand, double phaseOffset, int element) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setPhaseOffset(phaseOffset);
    setElement(element);
  }

  static GetWFAntennaElementPhasePatternOffsetResultPtr create(double phaseOffset, int element)
  {
    return std::make_shared<GetWFAntennaElementPhasePatternOffsetResult>(phaseOffset, element);
  }

  static GetWFAntennaElementPhasePatternOffsetResultPtr create(CommandBasePtr relatedCommand,
                                                               double phaseOffset,
                                                               int element)
  {
    return std::make_shared<GetWFAntennaElementPhasePatternOffsetResult>(relatedCommand, phaseOffset, element);
  }

  static GetWFAntennaElementPhasePatternOffsetResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetWFAntennaElementPhasePatternOffsetResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["PhaseOffset"]) &&
           parse_json<int>::is_valid(m_values["Element"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"PhaseOffset", "Element"};
    return names;
  }

  double phaseOffset() const { return parse_json<double>::parse(m_values["PhaseOffset"]); }

  void setPhaseOffset(double phaseOffset)
  {
    m_values.AddMember("PhaseOffset",
                       parse_json<double>::format(phaseOffset, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int element() const { return parse_json<int>::parse(m_values["Element"]); }

  void setElement(int element)
  {
    m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetWFAntennaElementPhasePatternOffsetResult);
} // namespace Cmd
} // namespace Sdx
