#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the simulation duration.
    ///
    /// 
    ///

    class GetDuration;
    typedef std::shared_ptr<GetDuration> GetDurationPtr;
    
    
    class GetDuration : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetDuration";
      inline static const char* const Documentation = "Get the simulation duration.";
      inline static const char* const TargetId = "";



          GetDuration()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetDurationPtr create()
          {
            return std::make_shared<GetDuration>();
          }

      static GetDurationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetDuration>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetDuration);
  }
}

