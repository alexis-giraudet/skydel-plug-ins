#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).
///
/// Name  Type   Description
/// ----- ------ ---------------------------------------------------------------
/// Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.
/// Val   double Coefficient value.
///

class SetEffectiveIonisationLevelCoefficient;
typedef std::shared_ptr<SetEffectiveIonisationLevelCoefficient> SetEffectiveIonisationLevelCoefficientPtr;

class SetEffectiveIonisationLevelCoefficient : public CommandBase
{
public:
  inline static const char* const CmdName = "SetEffectiveIonisationLevelCoefficient";
  inline static const char* const Documentation =
    "Set the effective ionisation level coefficient for the 1st, 2nd or 3rd order, (ai0 , ai1 , ai2).\n"
    "\n"
    "Name  Type   Description\n"
    "----- ------ ---------------------------------------------------------------\n"
    "Index int    Coefficient index, 0, 1 or 2 for ai0, ai1 and ai2 respectively.\n"
    "Val   double Coefficient value.";
  inline static const char* const TargetId = "";

  SetEffectiveIonisationLevelCoefficient() : CommandBase(CmdName, TargetId) {}

  SetEffectiveIonisationLevelCoefficient(int index, double val) : CommandBase(CmdName, TargetId)
  {

    setIndex(index);
    setVal(val);
  }

  static SetEffectiveIonisationLevelCoefficientPtr create(int index, double val)
  {
    return std::make_shared<SetEffectiveIonisationLevelCoefficient>(index, val);
  }

  static SetEffectiveIonisationLevelCoefficientPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetEffectiveIonisationLevelCoefficient>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Index"]) &&
           parse_json<double>::is_valid(m_values["Val"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Index", "Val"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int index() const { return parse_json<int>::parse(m_values["Index"]); }

  void setIndex(int index)
  {
    m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
  }

  double val() const { return parse_json<double>::parse(m_values["Val"]); }

  void setVal(double val)
  {
    m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetEffectiveIonisationLevelCoefficient);
} // namespace Cmd
} // namespace Sdx
