#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set engine latency.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------
    /// Latency int  Engine latency in msec
    ///

    class SetEngineLatency;
    typedef std::shared_ptr<SetEngineLatency> SetEngineLatencyPtr;
    
    
    class SetEngineLatency : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetEngineLatency";
      inline static const char* const Documentation = "Set engine latency.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------\n"      "Latency int  Engine latency in msec";
      inline static const char* const TargetId = "";



          SetEngineLatency()
            : CommandBase(CmdName, TargetId)
          {}

          SetEngineLatency(int latency)
            : CommandBase(CmdName, TargetId)
          {

            setLatency(latency);
          }


          static SetEngineLatencyPtr create(int latency)
          {
            return std::make_shared<SetEngineLatency>(latency);
          }

      static SetEngineLatencyPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetEngineLatency>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Latency"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Latency"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
          }


          int latency() const
          {
            return parse_json<int>::parse(m_values["Latency"]);
          }

          void setLatency(int latency)
          {
            m_values.AddMember("Latency", parse_json<int>::format(latency, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetEngineLatency);
  }
}

