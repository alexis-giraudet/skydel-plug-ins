#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set streaming buffer size.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------------
    /// Size int  Streaming buffer size in msec
    ///

    class SetStreamingBuffer;
    typedef std::shared_ptr<SetStreamingBuffer> SetStreamingBufferPtr;
    
    
    class SetStreamingBuffer : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetStreamingBuffer";
      inline static const char* const Documentation = "Set streaming buffer size.\n"      "\n"      "Name Type Description\n"      "---- ---- -----------------------------\n"      "Size int  Streaming buffer size in msec";
      inline static const char* const TargetId = "";



          SetStreamingBuffer()
            : CommandBase(CmdName, TargetId)
          {}

          SetStreamingBuffer(int size)
            : CommandBase(CmdName, TargetId)
          {

            setSize(size);
          }


          static SetStreamingBufferPtr create(int size)
          {
            return std::make_shared<SetStreamingBuffer>(size);
          }

      static SetStreamingBufferPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetStreamingBuffer>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Size"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Size"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
          }


          int size() const
          {
            return parse_json<int>::parse(m_values["Size"]);
          }

          void setSize(int size)
          {
            m_values.AddMember("Size", parse_json<int>::format(size, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetStreamingBuffer);
  }
}

