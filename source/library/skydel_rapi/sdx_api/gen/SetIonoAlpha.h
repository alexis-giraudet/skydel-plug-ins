#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the GPS ionospheric Alpha coefficient
/// Alpha 0 is in seconds
/// Alpha 1 is in seconds/semicircle
/// Alpha 2 is in seconds/semicircle^2
/// Alpha 3 is in seconds/semicircle^3
///
/// Name  Type   Description
/// ----- ------ ------------------------
/// Index int    Coefficient index [0..3]
/// Val   double Coefficient value
///

class SetIonoAlpha;
typedef std::shared_ptr<SetIonoAlpha> SetIonoAlphaPtr;

class SetIonoAlpha : public CommandBase
{
public:
  inline static const char* const CmdName = "SetIonoAlpha";
  inline static const char* const Documentation = "Set the GPS ionospheric Alpha coefficient\n"
                                                  "Alpha 0 is in seconds\n"
                                                  "Alpha 1 is in seconds/semicircle\n"
                                                  "Alpha 2 is in seconds/semicircle^2\n"
                                                  "Alpha 3 is in seconds/semicircle^3\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------\n"
                                                  "Index int    Coefficient index [0..3]\n"
                                                  "Val   double Coefficient value";
  inline static const char* const TargetId = "";

  SetIonoAlpha() : CommandBase(CmdName, TargetId) {}

  SetIonoAlpha(int index, double val) : CommandBase(CmdName, TargetId)
  {

    setIndex(index);
    setVal(val);
  }

  static SetIonoAlphaPtr create(int index, double val) { return std::make_shared<SetIonoAlpha>(index, val); }

  static SetIonoAlphaPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetIonoAlpha>(ptr); }

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
REGISTER_COMMAND_TO_FACTORY(SetIonoAlpha);
} // namespace Cmd
} // namespace Sdx
