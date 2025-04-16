#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/PropagationModelType.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetCurrentPropagationModel.
    ///
    /// Name  Type                 Description
    /// ----- -------------------- ---------------------------------------
    /// Model PropagationModelType The selected type of propagation model.
    ///

    class GetCurrentPropagationModelResult;
    typedef std::shared_ptr<GetCurrentPropagationModelResult> GetCurrentPropagationModelResultPtr;
    
    
    class GetCurrentPropagationModelResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetCurrentPropagationModelResult";
      inline static const char* const Documentation = "Result of GetCurrentPropagationModel.\n"      "\n"      "Name  Type                 Description\n"      "----- -------------------- ---------------------------------------\n"      "Model PropagationModelType The selected type of propagation model.";
      inline static const char* const TargetId = "";



          GetCurrentPropagationModelResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetCurrentPropagationModelResult(const Sdx::PropagationModelType& model)
            : CommandResult(CmdName, TargetId)
          {

            setModel(model);
          }

          GetCurrentPropagationModelResult(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setModel(model);
          }



          static GetCurrentPropagationModelResultPtr create(const Sdx::PropagationModelType& model)
          {
            return std::make_shared<GetCurrentPropagationModelResult>(model);
          }

          static GetCurrentPropagationModelResultPtr create(CommandBasePtr relatedCommand, const Sdx::PropagationModelType& model)
          {
            return std::make_shared<GetCurrentPropagationModelResult>(relatedCommand, model);
          }

      static GetCurrentPropagationModelResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCurrentPropagationModelResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<Sdx::PropagationModelType>::is_valid(m_values["Model"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Model"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(GetCurrentPropagationModelResult);
  }
}

