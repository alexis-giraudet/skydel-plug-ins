#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get earth-orbiting spacecraft trajectory.
    ///
    /// 
    ///

    class GetVehicleTrajectoryOrbit;
    typedef std::shared_ptr<GetVehicleTrajectoryOrbit> GetVehicleTrajectoryOrbitPtr;
    
    
    class GetVehicleTrajectoryOrbit : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetVehicleTrajectoryOrbit";
      inline static const char* const Documentation = "Get earth-orbiting spacecraft trajectory.";
      inline static const char* const TargetId = "";



          GetVehicleTrajectoryOrbit()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetVehicleTrajectoryOrbitPtr create()
          {
            return std::make_shared<GetVehicleTrajectoryOrbit>();
          }

      static GetVehicleTrajectoryOrbitPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleTrajectoryOrbit>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryOrbit);
  }
}

