#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the SV Data Update Mode.
    ///
    /// 
    ///

    class GetSVDataUpdateMode;
    typedef std::shared_ptr<GetSVDataUpdateMode> GetSVDataUpdateModePtr;
    
    
    class GetSVDataUpdateMode : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSVDataUpdateMode";
      inline static const char* const Documentation = "Get the SV Data Update Mode.";
      inline static const char* const TargetId = "";



          GetSVDataUpdateMode()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetSVDataUpdateModePtr create()
          {
            return std::make_shared<GetSVDataUpdateMode>();
          }

      static GetSVDataUpdateModePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSVDataUpdateMode>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetSVDataUpdateMode);
  }
}

