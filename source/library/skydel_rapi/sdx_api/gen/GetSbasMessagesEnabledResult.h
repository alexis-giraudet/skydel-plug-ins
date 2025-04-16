#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasMessagesEnabled.
    ///
    /// Name     Type      Description
    /// -------- --------- --------------------
    /// Messages array int The enabled messages
    ///

    class GetSbasMessagesEnabledResult;
    typedef std::shared_ptr<GetSbasMessagesEnabledResult> GetSbasMessagesEnabledResultPtr;
    
    
    class GetSbasMessagesEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSbasMessagesEnabledResult";
      inline static const char* const Documentation = "Result of GetSbasMessagesEnabled.\n"      "\n"      "Name     Type      Description\n"      "-------- --------- --------------------\n"      "Messages array int The enabled messages";
      inline static const char* const TargetId = "";



          GetSbasMessagesEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSbasMessagesEnabledResult(const std::vector<int>& messages)
            : CommandResult(CmdName, TargetId)
          {

            setMessages(messages);
          }

          GetSbasMessagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setMessages(messages);
          }



          static GetSbasMessagesEnabledResultPtr create(const std::vector<int>& messages)
          {
            return std::make_shared<GetSbasMessagesEnabledResult>(messages);
          }

          static GetSbasMessagesEnabledResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& messages)
          {
            return std::make_shared<GetSbasMessagesEnabledResult>(relatedCommand, messages);
          }

      static GetSbasMessagesEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSbasMessagesEnabledResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<int>>::is_valid(m_values["Messages"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Messages"}; 
        return names; 
      }
      


          std::vector<int> messages() const
          {
            return parse_json<std::vector<int>>::parse(m_values["Messages"]);
          }

          void setMessages(const std::vector<int>& messages)
          {
            m_values.AddMember("Messages", parse_json<std::vector<int>>::format(messages, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSbasMessagesEnabledResult);
  }
}

