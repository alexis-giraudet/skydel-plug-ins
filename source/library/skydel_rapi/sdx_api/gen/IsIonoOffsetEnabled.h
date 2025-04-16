#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the ionospheric offsets grid should be applied to the ionosphere
    ///
    /// 
    ///

    class IsIonoOffsetEnabled;
    typedef std::shared_ptr<IsIonoOffsetEnabled> IsIonoOffsetEnabledPtr;
    
    
    class IsIonoOffsetEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsIonoOffsetEnabled";
      inline static const char* const Documentation = "Get whether the ionospheric offsets grid should be applied to the ionosphere";
      inline static const char* const TargetId = "";



          IsIonoOffsetEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsIonoOffsetEnabledPtr create()
          {
            return std::make_shared<IsIonoOffsetEnabled>();
          }

      static IsIonoOffsetEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsIonoOffsetEnabled>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsIonoOffsetEnabled);
  }
}

