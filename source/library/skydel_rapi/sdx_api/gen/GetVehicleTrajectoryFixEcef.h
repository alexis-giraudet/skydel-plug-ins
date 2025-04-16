#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get vehicle static position and orientation
    ///
    /// 
    ///

    class GetVehicleTrajectoryFixEcef;
    typedef std::shared_ptr<GetVehicleTrajectoryFixEcef> GetVehicleTrajectoryFixEcefPtr;
    
    
    class GetVehicleTrajectoryFixEcef : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetVehicleTrajectoryFixEcef";
      inline static const char* const Documentation = "Get vehicle static position and orientation";
      inline static const char* const TargetId = "";



          GetVehicleTrajectoryFixEcef()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetVehicleTrajectoryFixEcefPtr create()
          {
            return std::make_shared<GetVehicleTrajectoryFixEcef>();
          }

      static GetVehicleTrajectoryFixEcefPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleTrajectoryFixEcef>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetVehicleTrajectoryFixEcef);
  }
}

