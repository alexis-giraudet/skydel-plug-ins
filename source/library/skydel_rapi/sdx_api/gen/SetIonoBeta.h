#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the GPS ionospheric Beta coefficient
/// Beta 0 is in seconds
/// Beta 1 is in seconds/semicircle
/// Beta 2 is in seconds/semicircle^2
/// Beta 3 is in seconds/semicircle^3
///
/// Name  Type   Description
/// ----- ------ ------------------------
/// Index int    Coefficient index [0..3]
/// Val   double Coefficient value
///

class SetIonoBeta;
typedef std::shared_ptr<SetIonoBeta> SetIonoBetaPtr;

class SetIonoBeta : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIonoBeta";
  inline static const char* const Documentation = "Set the GPS ionospheric Beta coefficient\n"
                                                  "Beta 0 is in seconds\n"
                                                  "Beta 1 is in seconds/semicircle\n"
                                                  "Beta 2 is in seconds/semicircle^2\n"
                                                  "Beta 3 is in seconds/semicircle^3\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------\n"
                                                  "Index int    Coefficient index [0..3]\n"
                                                  "Val   double Coefficient value";
  inline static const char* const TargetId = "";

  SetIonoBeta() : CommandBase(CmdName, TargetId) {}

  SetIonoBeta(int index, double val) : CommandBase(CmdName, TargetId)
  {

    setIndex(index);
    setVal(val);
  }

  static SetIonoBetaPtr create(int index, double val) { return std::make_shared<SetIonoBeta>(index, val); }

  static SetIonoBetaPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIonoBeta>(ptr); }

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
REGISTER_COMMAND_TO_FACTORY(SetIonoBeta);
} // namespace Cmd
} // namespace Sdx
