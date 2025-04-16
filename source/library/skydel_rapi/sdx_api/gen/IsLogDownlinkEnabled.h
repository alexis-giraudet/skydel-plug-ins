#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if downlink data Logging is enabled
    ///
    /// 
    ///

    class IsLogDownlinkEnabled;
    typedef std::shared_ptr<IsLogDownlinkEnabled> IsLogDownlinkEnabledPtr;
    
    
    class IsLogDownlinkEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsLogDownlinkEnabled";
      inline static const char* const Documentation = "Tells if downlink data Logging is enabled";
      inline static const char* const TargetId = "";



          IsLogDownlinkEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsLogDownlinkEnabledPtr create()
          {
            return std::make_shared<IsLogDownlinkEnabled>();
          }

      static IsLogDownlinkEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsLogDownlinkEnabled>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsLogDownlinkEnabled);
  }
}

