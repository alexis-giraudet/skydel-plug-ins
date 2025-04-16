#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Rate logging of raw data
    ///
    /// 
    ///

    class GetLogRawRate;
    typedef std::shared_ptr<GetLogRawRate> GetLogRawRatePtr;
    
    
    class GetLogRawRate : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetLogRawRate";
      inline static const char* const Documentation = "Get Rate logging of raw data";
      inline static const char* const TargetId = "";



          GetLogRawRate()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetLogRawRatePtr create()
          {
            return std::make_shared<GetLogRawRate>();
          }

      static GetLogRawRatePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetLogRawRate>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetLogRawRate);
  }
}

