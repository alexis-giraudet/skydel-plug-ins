#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns whether the vehicle trajectory was completed.
    /// For fixed, circular and earth-orbiting spacecraft, this will always return false.
    /// For track playback and vehicle simulation, this will return true once the vehicle will reach the last position in the track/route.
    /// The value is unreliable for HIL trajectories.
    ///
    /// 
    ///

    class IsTrajectoryCompleted;
    typedef std::shared_ptr<IsTrajectoryCompleted> IsTrajectoryCompletedPtr;
    
    
    class IsTrajectoryCompleted : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsTrajectoryCompleted";
      inline static const char* const Documentation = "Returns whether the vehicle trajectory was completed.\n"      "For fixed, circular and earth-orbiting spacecraft, this will always return false.\n"      "For track playback and vehicle simulation, this will return true once the vehicle will reach the last position in the track/route.\n"      "The value is unreliable for HIL trajectories.";
      inline static const char* const TargetId = "";



          IsTrajectoryCompleted()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsTrajectoryCompletedPtr create()
          {
            return std::make_shared<IsTrajectoryCompleted>();
          }

      static IsTrajectoryCompletedPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsTrajectoryCompleted>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsTrajectoryCompleted);
  }
}

