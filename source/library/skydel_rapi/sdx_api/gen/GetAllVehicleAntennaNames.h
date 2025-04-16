#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of all vehicle antenna names
    ///
    /// 
    ///

    class GetAllVehicleAntennaNames;
    typedef std::shared_ptr<GetAllVehicleAntennaNames> GetAllVehicleAntennaNamesPtr;
    
    
    class GetAllVehicleAntennaNames : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetAllVehicleAntennaNames";
      inline static const char* const Documentation = "Get a list of all vehicle antenna names";
      inline static const char* const TargetId = "";



          GetAllVehicleAntennaNames()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetAllVehicleAntennaNamesPtr create()
          {
            return std::make_shared<GetAllVehicleAntennaNames>();
          }

      static GetAllVehicleAntennaNamesPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllVehicleAntennaNames>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetAllVehicleAntennaNames);
  }
}

