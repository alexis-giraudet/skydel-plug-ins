#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the delay of the NMEA serial port logging.
    ///
    /// 
    ///

    class GetNmeaLoggerSerialPortDelay;
    typedef std::shared_ptr<GetNmeaLoggerSerialPortDelay> GetNmeaLoggerSerialPortDelayPtr;
    
    
    class GetNmeaLoggerSerialPortDelay : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetNmeaLoggerSerialPortDelay";
      inline static const char* const Documentation = "Get the delay of the NMEA serial port logging.";
      inline static const char* const TargetId = "";



          GetNmeaLoggerSerialPortDelay()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetNmeaLoggerSerialPortDelayPtr create()
          {
            return std::make_shared<GetNmeaLoggerSerialPortDelay>();
          }

      static GetNmeaLoggerSerialPortDelayPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetNmeaLoggerSerialPortDelay>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetNmeaLoggerSerialPortDelay);
  }
}

