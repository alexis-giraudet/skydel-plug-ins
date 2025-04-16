#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get next almanac upload time relative to simulation start time.
    ///
    /// 
    ///

    class GetAlmanacInitialUploadTimeOffset;
    typedef std::shared_ptr<GetAlmanacInitialUploadTimeOffset> GetAlmanacInitialUploadTimeOffsetPtr;
    
    
    class GetAlmanacInitialUploadTimeOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetAlmanacInitialUploadTimeOffset";
      inline static const char* const Documentation = "Get next almanac upload time relative to simulation start time.";
      inline static const char* const TargetId = "";



          GetAlmanacInitialUploadTimeOffset()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetAlmanacInitialUploadTimeOffsetPtr create()
          {
            return std::make_shared<GetAlmanacInitialUploadTimeOffset>();
          }

      static GetAlmanacInitialUploadTimeOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAlmanacInitialUploadTimeOffset>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetAlmanacInitialUploadTimeOffset);
  }
}

