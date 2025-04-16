#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Arm the simulation. Simulation may or may not arm depending on the current state of the simulator.
    ///
    /// 
    ///

    class Arm;
    typedef std::shared_ptr<Arm> ArmPtr;
    
    
    class Arm : public CommandBase
    {
    public:
      inline static const char* const CmdName = "Arm";
      inline static const char* const Documentation = "Arm the simulation. Simulation may or may not arm depending on the current state of the simulator.";
      inline static const char* const TargetId = "";



          Arm()
            : CommandBase(CmdName, TargetId)
          {

          }


          static ArmPtr create()
          {
            return std::make_shared<Arm>();
          }

      static ArmPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<Arm>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(Arm);
  }
}

