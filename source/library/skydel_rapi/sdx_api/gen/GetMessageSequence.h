#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the messages sequence for the signal
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------
    /// Signal string Signal Name ("L2C" for example)
    ///

    class GetMessageSequence;
    typedef std::shared_ptr<GetMessageSequence> GetMessageSequencePtr;
    
    
    class GetMessageSequence : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetMessageSequence";
      inline static const char* const Documentation = "Get the messages sequence for the signal\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------\n"      "Signal string Signal Name (\"L2C\" for example)";
      inline static const char* const TargetId = "";



          GetMessageSequence()
            : CommandBase(CmdName, TargetId)
          {}

          GetMessageSequence(const std::string& signal)
            : CommandBase(CmdName, TargetId)
          {

            setSignal(signal);
          }


          static GetMessageSequencePtr create(const std::string& signal)
          {
            return std::make_shared<GetMessageSequence>(signal);
          }

      static GetMessageSequencePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetMessageSequence>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetMessageSequence);
  }
}

