#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Pause vehicle motion during simulation.
    ///
    /// 
    ///

    class Pause;
    typedef std::shared_ptr<Pause> PausePtr;
    
    
    class Pause : public CommandBase
    {
    public:
      inline static const char* const CmdName = "Pause";
      inline static const char* const Documentation = "Pause vehicle motion during simulation.";
      inline static const char* const TargetId = "";



          Pause()
            : CommandBase(CmdName, TargetId)
          {

          }


          static PausePtr create()
          {
            return std::make_shared<Pause>();
          }

      static PausePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<Pause>(ptr);
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
            return EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(Pause);
  }
}

