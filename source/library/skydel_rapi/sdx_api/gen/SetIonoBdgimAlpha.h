#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)
///
/// Name  Type   Description
/// ----- ------ ------------------------
/// Index int    Coefficient index [1..9]
/// Val   double Coefficient value
///

class SetIonoBdgimAlpha;
typedef std::shared_ptr<SetIonoBdgimAlpha> SetIonoBdgimAlphaPtr;

class SetIonoBdgimAlpha : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIonoBdgimAlpha";
  inline static const char* const Documentation = "Set the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------\n"
                                                  "Index int    Coefficient index [1..9]\n"
                                                  "Val   double Coefficient value";
  inline static const char* const TargetId = "";

  SetIonoBdgimAlpha() : CommandBase(CmdName, TargetId) {}

  SetIonoBdgimAlpha(int index, double val) : CommandBase(CmdName, TargetId)
  {

    setIndex(index);
    setVal(val);
  }

  static SetIonoBdgimAlphaPtr create(int index, double val) { return std::make_shared<SetIonoBdgimAlpha>(index, val); }

  static SetIonoBdgimAlphaPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetIonoBdgimAlpha>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(SetIonoBdgimAlpha);
} // namespace Cmd
} // namespace Sdx
