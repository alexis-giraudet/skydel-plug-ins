#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Rate logging of NMEA data
    ///
    /// 
    ///

    class GetLogNmeaRate;
    typedef std::shared_ptr<GetLogNmeaRate> GetLogNmeaRatePtr;
    
    
    class GetLogNmeaRate : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetLogNmeaRate";
      inline static const char* const Documentation = "Get Rate logging of NMEA data";
      inline static const char* const TargetId = "";



          GetLogNmeaRate()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetLogNmeaRatePtr create()
          {
            return std::make_shared<GetLogNmeaRate>();
          }

      static GetLogNmeaRatePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetLogNmeaRate>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetLogNmeaRate);
  }
}

