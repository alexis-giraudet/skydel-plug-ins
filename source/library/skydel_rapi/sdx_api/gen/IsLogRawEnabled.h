#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if raw data logging is enabled.
    ///
    /// 
    ///

    class IsLogRawEnabled;
    typedef std::shared_ptr<IsLogRawEnabled> IsLogRawEnabledPtr;
    
    
    class IsLogRawEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsLogRawEnabled";
      inline static const char* const Documentation = "Tells if raw data logging is enabled.";
      inline static const char* const TargetId = "";



          IsLogRawEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsLogRawEnabledPtr create()
          {
            return std::make_shared<IsLogRawEnabled>();
          }

      static IsLogRawEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsLogRawEnabled>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsLogRawEnabled);
  }
}

