#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Abort the current WaitSimulatorState if any.
    ///
    /// 
    ///

    class AbortWaitSimulatorState;
    typedef std::shared_ptr<AbortWaitSimulatorState> AbortWaitSimulatorStatePtr;
    
    
    class AbortWaitSimulatorState : public CommandBase
    {
    public:
      inline static const char* const CmdName = "AbortWaitSimulatorState";
      inline static const char* const Documentation = "Abort the current WaitSimulatorState if any.";
      inline static const char* const TargetId = "";



          AbortWaitSimulatorState()
            : CommandBase(CmdName, TargetId)
          {

          }


          static AbortWaitSimulatorStatePtr create()
          {
            return std::make_shared<AbortWaitSimulatorState>();
          }

      static AbortWaitSimulatorStatePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<AbortWaitSimulatorState>(ptr);
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
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(AbortWaitSimulatorState);
  }
}

