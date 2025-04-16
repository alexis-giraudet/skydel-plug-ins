#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get OSNMA MAC function.
    ///
    /// 
    ///

    class GetOsnmaMacFunction;
    typedef std::shared_ptr<GetOsnmaMacFunction> GetOsnmaMacFunctionPtr;
    
    
    class GetOsnmaMacFunction : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetOsnmaMacFunction";
      inline static const char* const Documentation = "Get OSNMA MAC function.";
      inline static const char* const TargetId = "";



          GetOsnmaMacFunction()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetOsnmaMacFunctionPtr create()
          {
            return std::make_shared<GetOsnmaMacFunction>();
          }

      static GetOsnmaMacFunctionPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetOsnmaMacFunction>(ptr);
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
            return EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetOsnmaMacFunction);
  }
}

