#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).
///
/// Name  Type Description
/// ----- ---- ---------------------------------------------------------------
/// Index int  Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
///

class GetEffectiveIonisationLevelCoefficient;
typedef std::shared_ptr<GetEffectiveIonisationLevelCoefficient> GetEffectiveIonisationLevelCoefficientPtr;

class GetEffectiveIonisationLevelCoefficient : public CommandBase
{
public:
  inline static const char* const CmdName = "GetEffectiveIonisationLevelCoefficient";
  inline static const char* const Documentation =
    "Get the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).\n"
    "\n"
    "Name  Type Description\n"
    "----- ---- ---------------------------------------------------------------\n"
    "Index int  Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.";
  inline static const char* const TargetId = "";

  GetEffectiveIonisationLevelCoefficient() : CommandBase(CmdName, TargetId) {}

  GetEffectiveIonisationLevelCoefficient(int index) : CommandBase(CmdName, TargetId) { setIndex(index); }

  static GetEffectiveIonisationLevelCoefficientPtr create(int index)
  {
    return std::make_shared<GetEffectiveIonisationLevelCoefficient>(index);
  }

  static GetEffectiveIonisationLevelCoefficientPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetEffectiveIonisationLevelCoefficient>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Index"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Index"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int index() const { return parse_json<int>::parse(m_values["Index"]); }

  void setIndex(int index)
  {
    m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetEffectiveIonisationLevelCoefficient);
} // namespace Cmd
} // namespace Sdx
