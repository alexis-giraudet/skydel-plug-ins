#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the SBAS message update interval.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------
    /// Message int  The message type.
    ///

    class GetSbasMessageUpdateInterval;
    typedef std::shared_ptr<GetSbasMessageUpdateInterval> GetSbasMessageUpdateIntervalPtr;
    
    
    class GetSbasMessageUpdateInterval : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSbasMessageUpdateInterval";
      inline static const char* const Documentation = "Get the SBAS message update interval.\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------\n"      "Message int  The message type.";
      inline static const char* const TargetId = "";



          GetSbasMessageUpdateInterval()
            : CommandBase(CmdName, TargetId)
          {}

          GetSbasMessageUpdateInterval(int message)
            : CommandBase(CmdName, TargetId)
          {

            setMessage(message);
          }


          static GetSbasMessageUpdateIntervalPtr create(int message)
          {
            return std::make_shared<GetSbasMessageUpdateInterval>(message);
          }

      static GetSbasMessageUpdateIntervalPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSbasMessageUpdateInterval>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Message"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Message"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          int message() const
          {
            return parse_json<int>::parse(m_values["Message"]);
          }

          void setMessage(int message)
          {
            m_values.AddMember("Message", parse_json<int>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSbasMessageUpdateInterval);
  }
}

