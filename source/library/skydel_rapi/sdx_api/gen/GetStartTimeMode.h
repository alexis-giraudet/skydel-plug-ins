#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the simulation start time mode.
    ///
    /// 
    ///

    class GetStartTimeMode;
    typedef std::shared_ptr<GetStartTimeMode> GetStartTimeModePtr;
    
    
    class GetStartTimeMode : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetStartTimeMode";
      inline static const char* const Documentation = "Get the simulation start time mode.";
      inline static const char* const TargetId = "";



          GetStartTimeMode()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetStartTimeModePtr create()
          {
            return std::make_shared<GetStartTimeMode>();
          }

      static GetStartTimeModePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetStartTimeMode>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetStartTimeMode);
  }
}

