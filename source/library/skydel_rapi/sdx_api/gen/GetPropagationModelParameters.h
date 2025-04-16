#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/PropagationModelType.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the parameters for the propagation model.
    ///
    /// Name       Type                 Description
    /// ---------- -------------------- ------------------------------------------------------------------------
    /// Model      PropagationModelType The type of propagation model to edit.
    /// ParamArray array string         The propagation model parameters. Leave blank to restore default values.
    ///

    class GetPropagationModelParameters;
    typedef std::shared_ptr<GetPropagationModelParameters> GetPropagationModelParametersPtr;
    
    
    class GetPropagationModelParameters : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetPropagationModelParameters";
      inline static const char* const Documentation = "Get the parameters for the propagation model.\n"      "\n"      "Name       Type                 Description\n"      "---------- -------------------- ------------------------------------------------------------------------\n"      "Model      PropagationModelType The type of propagation model to edit.\n"      "ParamArray array string         The propagation model parameters. Leave blank to restore default values.";
      inline static const char* const TargetId = "";



          GetPropagationModelParameters()
            : CommandBase(CmdName, TargetId)
          {}

          GetPropagationModelParameters(const Sdx::PropagationModelType& model, const std::vector<std::string>& paramArray)
            : CommandBase(CmdName, TargetId)
          {

            setModel(model);
            setParamArray(paramArray);
          }


          static GetPropagationModelParametersPtr create(const Sdx::PropagationModelType& model, const std::vector<std::string>& paramArray)
          {
            return std::make_shared<GetPropagationModelParameters>(model, paramArray);
          }

      static GetPropagationModelParametersPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPropagationModelParameters>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
                  && parse_json<std::vector<std::string>>::is_valid(m_values["ParamArray"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Model", "ParamArray"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          Sdx::PropagationModelType model() const
          {
            return parse_json<Sdx::PropagationModelType>::parse(m_values["Model"]);
          }

          void setModel(const Sdx::PropagationModelType& model)
          {
            m_values.AddMember("Model", parse_json<Sdx::PropagationModelType>::format(model, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<std::string> paramArray() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["ParamArray"]);
          }

          void setParamArray(const std::vector<std::string>& paramArray)
          {
            m_values.AddMember("ParamArray", parse_json<std::vector<std::string>>::format(paramArray, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPropagationModelParameters);
  }
}

