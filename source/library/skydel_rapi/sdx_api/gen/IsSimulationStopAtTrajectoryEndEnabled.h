#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes
    ///
    /// 
    ///

    class IsSimulationStopAtTrajectoryEndEnabled;
    typedef std::shared_ptr<IsSimulationStopAtTrajectoryEndEnabled> IsSimulationStopAtTrajectoryEndEnabledPtr;
    
    
    class IsSimulationStopAtTrajectoryEndEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSimulationStopAtTrajectoryEndEnabled";
      inline static const char* const Documentation = "Get simulation automatic stop when the vehicle reaches trajectory end enabled or disabled. Only effective with Tracks and Routes";
      inline static const char* const TargetId = "";



          IsSimulationStopAtTrajectoryEndEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsSimulationStopAtTrajectoryEndEnabledPtr create()
          {
            return std::make_shared<IsSimulationStopAtTrajectoryEndEnabled>();
          }

      static IsSimulationStopAtTrajectoryEndEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSimulationStopAtTrajectoryEndEnabled>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsSimulationStopAtTrajectoryEndEnabled);
  }
}

