#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the time interval of the Raw Data logging.
    ///
    /// 
    ///

    class GetRawDataLoggingInterval;
    typedef std::shared_ptr<GetRawDataLoggingInterval> GetRawDataLoggingIntervalPtr;
    
    
    class GetRawDataLoggingInterval : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetRawDataLoggingInterval";
      inline static const char* const Documentation = "Get the time interval of the Raw Data logging.";
      inline static const char* const TargetId = "";



          GetRawDataLoggingInterval()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetRawDataLoggingIntervalPtr create()
          {
            return std::make_shared<GetRawDataLoggingInterval>();
          }

      static GetRawDataLoggingIntervalPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetRawDataLoggingInterval>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetRawDataLoggingInterval);
  }
}

