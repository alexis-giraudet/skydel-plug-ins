#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether the ionospheric offsets grid should be used for SBAS corrections in message 26
    ///
    /// 
    ///

    class IsDelayAppliedInSbas;
    typedef std::shared_ptr<IsDelayAppliedInSbas> IsDelayAppliedInSbasPtr;
    
    
    class IsDelayAppliedInSbas : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsDelayAppliedInSbas";
      inline static const char* const Documentation = "Get whether the ionospheric offsets grid should be used for SBAS corrections in message 26";
      inline static const char* const TargetId = "";



          IsDelayAppliedInSbas()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsDelayAppliedInSbasPtr create()
          {
            return std::make_shared<IsDelayAppliedInSbas>();
          }

      static IsDelayAppliedInSbasPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsDelayAppliedInSbas>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsDelayAppliedInSbas);
  }
}

