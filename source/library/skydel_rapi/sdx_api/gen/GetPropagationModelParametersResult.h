#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/PropagationModelType.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPropagationModelParameters.
    ///
    /// Name           Type                 Description
    /// -------------- -------------------- ------------------------------------------------------------------------
    /// Model          PropagationModelType The type of propagation model to edit.
    /// ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.
    ///

    class GetPropagationModelParametersResult;
    typedef std::shared_ptr<GetPropagationModelParametersResult> GetPropagationModelParametersResultPtr;
    
    
    class GetPropagationModelParametersResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetPropagationModelParametersResult";
      inline static const char* const Documentation = "Result of GetPropagationModelParameters.\n"      "\n"      "Name           Type                 Description\n"      "-------------- -------------------- ------------------------------------------------------------------------\n"      "Model          PropagationModelType The type of propagation model to edit.\n"      "ParamValueDict dict string:double   The propagation model parameters. Leave blank to restore default values.";
      inline static const char* const TargetId = "";



          GetPropagationModelParametersResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetPropagationModelParametersResult(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
            : CommandResult(CmdName, TargetId)
          {

            setModel(model);
            setParamValueDict(paramValueDict);
          }

          GetPropagationModelParametersResult(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setModel(model);
            setParamValueDict(paramValueDict);
          }



          static GetPropagationModelParametersResultPtr create(const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
          {
            return std::make_shared<GetPropagationModelParametersResult>(model, paramValueDict);
          }

          static GetPropagationModelParametersResultPtr create(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model, const std::map<std::string, double>& paramValueDict)
          {
            return std::make_shared<GetPropagationModelParametersResult>(relatedCommand, model, paramValueDict);
          }

      static GetPropagationModelParametersResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPropagationModelParametersResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
                  && parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Model", "ParamValueDict"}; 
        return names; 
      }
      


          Sdx::PropagationModelType model() const
          {
            return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
          }

          void setModel(const Sdx::PropagationModelType& model)
          {
            m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::map<std::string, double> paramValueDict() const
          {
            return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
          }

          void setParamValueDict(const std::map<std::string, double>& paramValueDict)
          {
            m_values.AddMember("ParamValueDict", parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPropagationModelParametersResult);
  }
}

