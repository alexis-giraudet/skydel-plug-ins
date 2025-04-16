#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if data received on the HIL API logging is enabled
    ///
    /// 
    ///

    class IsLogHILInputEnabled;
    typedef std::shared_ptr<IsLogHILInputEnabled> IsLogHILInputEnabledPtr;
    
    
    class IsLogHILInputEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsLogHILInputEnabled";
      inline static const char* const Documentation = "Tells if data received on the HIL API logging is enabled";
      inline static const char* const TargetId = "";



          IsLogHILInputEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsLogHILInputEnabledPtr create()
          {
            return std::make_shared<IsLogHILInputEnabled>();
          }

      static IsLogHILInputEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsLogHILInputEnabled>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsLogHILInputEnabled);
  }
}

