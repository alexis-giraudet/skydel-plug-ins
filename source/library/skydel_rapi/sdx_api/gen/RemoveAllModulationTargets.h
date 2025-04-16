#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove all modulation targets.
    ///
    /// 
    ///

    class RemoveAllModulationTargets;
    typedef std::shared_ptr<RemoveAllModulationTargets> RemoveAllModulationTargetsPtr;
    
    
    class RemoveAllModulationTargets : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveAllModulationTargets";
      inline static const char* const Documentation = "Remove all modulation targets.";
      inline static const char* const TargetId = "";



          RemoveAllModulationTargets()
            : CommandBase(CmdName, TargetId)
          {

          }


          static RemoveAllModulationTargetsPtr create()
          {
            return std::make_shared<RemoveAllModulationTargets>();
          }

      static RemoveAllModulationTargetsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveAllModulationTargets>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(RemoveAllModulationTargets);
  }
}

