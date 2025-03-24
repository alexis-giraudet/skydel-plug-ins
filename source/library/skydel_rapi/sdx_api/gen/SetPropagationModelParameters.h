#pragma once

#include <map>
#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"
#include "gen/PropagationModelType.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the parameters for the propagation model.
///
/// Name           Type                 Description
/// -------------- -------------------- ------------------------------------------------------------------------
/// Model          PropagationModelType The type of propagation model to edit.
/// ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.
///

class SetPropagationModelParameters;
typedef std::shared_ptr<SetPropagationModelParameters> SetPropagationModelParametersPtr;

class SetPropagationModelParameters : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPropagationModelParameters";
  inline static const char* const Documentation =
    "Set the parameters for the propagation model.\n"
    "\n"
    "Name           Type                 Description\n"
    "-------------- -------------------- ------------------------------------------------------------------------\n"
    "Model          PropagationModelType The type of propagation model to edit.\n"
    "ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.";
  inline static const char* const TargetId = "";

  SetPropagationModelParameters() : CommandBase(CmdName, TargetId) {}

  SetPropagationModelParameters(const Sdx::PropagationModelType& model,
                                const std::map<std::string, double>& paramValueDict) :
    CommandBase(CmdName, TargetId)
  {

    setModel(model);
    setParamValueDict(paramValueDict);
  }

  static SetPropagationModelParametersPtr create(const Sdx::PropagationModelType& model,
                                                 const std::map<std::string, double>& paramValueDict)
  {
    return std::make_shared<SetPropagationModelParameters>(model, paramValueDict);
  }

  static SetPropagationModelParametersPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetPropagationModelParameters>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"]) &&
           parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Model", "ParamValueDict"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  Sdx::PropagationModelType model() const { return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]); }

  void setModel(const Sdx::PropagationModelType& model)
  {
    m_values.AddMember("Model",
                       parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::map<std::string, double> paramValueDict() const
  {
    return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
  }

  void setParamValueDict(const std::map<std::string, double>& paramValueDict)
  {
    m_values.AddMember("ParamValueDict",
                       parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPropagationModelParameters);
} // namespace Cmd
} // namespace Sdx
