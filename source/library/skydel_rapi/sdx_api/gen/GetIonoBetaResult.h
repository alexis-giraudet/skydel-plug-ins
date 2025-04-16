#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetIonoBeta.
///
/// Name  Type   Description
/// ----- ------ ------------------------
/// Index int    Coefficient index [0..3]
/// Val   double Coefficient value
///

class GetIonoBetaResult;
typedef std::shared_ptr<GetIonoBetaResult> GetIonoBetaResultPtr;

class GetIonoBetaResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIonoBetaResult";
  inline static const char* const Documentation = "Result of GetIonoBeta.\n"
                                                  "\n"
                                                  "Name  Type   Description\n"
                                                  "----- ------ ------------------------\n"
                                                  "Index int    Coefficient index [0..3]\n"
                                                  "Val   double Coefficient value";
  inline static const char* const TargetId = "";

  GetIonoBetaResult() : CommandResult(CmdName, TargetId) {}

  GetIonoBetaResult(int index, double val) : CommandResult(CmdName, TargetId)
  {

    setIndex(index);
    setVal(val);
  }

  GetIonoBetaResult(CommandBasePtr relatedCommand, int index, double val) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIndex(index);
    setVal(val);
  }

  static GetIonoBetaResultPtr create(int index, double val) { return std::make_shared<GetIonoBetaResult>(index, val); }

  static GetIonoBetaResultPtr create(CommandBasePtr relatedCommand, int index, double val)
  {
    return std::make_shared<GetIonoBetaResult>(relatedCommand, index, val);
  }

  static GetIonoBetaResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoBetaResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIonoBetaResult);
} // namespace Cmd
} // namespace Sdx
