#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get ionospheric model
    ///
    /// 
    ///

    class GetIonoModel;
    typedef std::shared_ptr<GetIonoModel> GetIonoModelPtr;
    
    
    class GetIonoModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIonoModel";
      inline static const char* const Documentation = "Get ionospheric model";
      inline static const char* const TargetId = "";



          GetIonoModel()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetIonoModelPtr create()
          {
            return std::make_shared<GetIonoModel>();
          }

      static GetIonoModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoModel>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetIonoModel);
  }
}

