#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the current propagation model.
    ///
    /// 
    ///

    class GetCurrentPropagationModel;
    typedef std::shared_ptr<GetCurrentPropagationModel> GetCurrentPropagationModelPtr;
    
    
    class GetCurrentPropagationModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetCurrentPropagationModel";
      inline static const char* const Documentation = "Get the current propagation model.";
      inline static const char* const TargetId = "";



          GetCurrentPropagationModel()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetCurrentPropagationModelPtr create()
          {
            return std::make_shared<GetCurrentPropagationModel>();
          }

      static GetCurrentPropagationModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCurrentPropagationModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetCurrentPropagationModel);
  }
}

