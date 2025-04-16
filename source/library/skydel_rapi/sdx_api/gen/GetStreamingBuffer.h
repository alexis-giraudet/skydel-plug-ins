#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get streaming buffer size.
    ///
    /// 
    ///

    class GetStreamingBuffer;
    typedef std::shared_ptr<GetStreamingBuffer> GetStreamingBufferPtr;
    
    
    class GetStreamingBuffer : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetStreamingBuffer";
      inline static const char* const Documentation = "Get streaming buffer size.";
      inline static const char* const TargetId = "";



          GetStreamingBuffer()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetStreamingBufferPtr create()
          {
            return std::make_shared<GetStreamingBuffer>();
          }

      static GetStreamingBufferPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetStreamingBuffer>(ptr);
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
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetStreamingBuffer);
  }
}

