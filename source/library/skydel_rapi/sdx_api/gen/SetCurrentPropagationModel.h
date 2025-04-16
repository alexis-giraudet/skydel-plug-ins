#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/PropagationModelType.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the current propagation model.
    ///
    /// Name  Type                 Description
    /// ----- -------------------- ---------------------------------------
    /// Model PropagationModelType The selected type of propagation model.
    ///

    class SetCurrentPropagationModel;
    typedef std::shared_ptr<SetCurrentPropagationModel> SetCurrentPropagationModelPtr;
    
    
    class SetCurrentPropagationModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetCurrentPropagationModel";
      inline static const char* const Documentation = "Set the current propagation model.\n"      "\n"      "Name  Type                 Description\n"      "----- -------------------- ---------------------------------------\n"      "Model PropagationModelType The selected type of propagation model.";
      inline static const char* const TargetId = "";



          SetCurrentPropagationModel()
            : CommandBase(CmdName, TargetId)
          {}

          SetCurrentPropagationModel(const Sdx::PropagationModelType& model)
            : CommandBase(CmdName, TargetId)
          {

            setModel(model);
          }


          static SetCurrentPropagationModelPtr create(const Sdx::PropagationModelType& model)
          {
            return std::make_shared<SetCurrentPropagationModel>(model);
          }

      static SetCurrentPropagationModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetCurrentPropagationModel>(ptr);
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

    };
    REGISTER_COMMAND_TO_FACTORY(SetCurrentPropagationModel);
  }
}

