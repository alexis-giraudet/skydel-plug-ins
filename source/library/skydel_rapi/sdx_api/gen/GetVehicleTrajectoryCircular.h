#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get vehicle circular trajectory
    ///
    /// 
    ///

    class GetVehicleTrajectoryCircular;
    typedef std::shared_ptr<GetVehicleTrajectoryCircular> GetVehicleTrajectoryCircularPtr;
    
    
    class GetVehicleTrajectoryCircular : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetVehicleTrajectoryCircular";
      inline static const char* const Documentation = "Get vehicle circular trajectory";
      inline static const char* const TargetId = "";



          GetVehicleTrajectoryCircular()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetVehicleTrajectoryCircularPtr create()
          {
            return std::make_shared<GetVehicleTrajectoryCircular>();
          }

      static GetVehicleTrajectoryCircularPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleTrajectoryCircular>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryCircular);
  }
}

