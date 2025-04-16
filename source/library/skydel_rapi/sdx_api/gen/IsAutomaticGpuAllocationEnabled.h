#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Indicates whether GPUs are automatically allocated to outputs.
    ///
    /// 
    ///

    class IsAutomaticGpuAllocationEnabled;
    typedef std::shared_ptr<IsAutomaticGpuAllocationEnabled> IsAutomaticGpuAllocationEnabledPtr;
    
    
    class IsAutomaticGpuAllocationEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsAutomaticGpuAllocationEnabled";
      inline static const char* const Documentation = "Indicates whether GPUs are automatically allocated to outputs.";
      inline static const char* const TargetId = "";



          IsAutomaticGpuAllocationEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsAutomaticGpuAllocationEnabledPtr create()
          {
            return std::make_shared<IsAutomaticGpuAllocationEnabled>();
          }

      static IsAutomaticGpuAllocationEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsAutomaticGpuAllocationEnabled>(ptr);
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
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(IsAutomaticGpuAllocationEnabled);
  }
}

