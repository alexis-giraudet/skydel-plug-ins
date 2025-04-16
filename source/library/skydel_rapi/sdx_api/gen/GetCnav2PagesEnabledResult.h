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
    /// Result of GetCnav2PagesEnabled.
    ///
    /// Name     Type      Description
    /// -------- --------- -----------------
    /// Messages array int The enabled pages
    ///

    class GetCnav2PagesEnabledResult;
    typedef std::shared_ptr<GetCnav2PagesEnabledResult> GetCnav2PagesEnabledResultPtr;
    
    
    class GetCnav2PagesEnabledResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetCnav2PagesEnabledResult";
      inline static const char* const Documentation = "Result of GetCnav2PagesEnabled.\n"      "\n"      "Name     Type      Description\n"      "-------- --------- -----------------\n"      "Messages array int The enabled pages";
      inline static const char* const TargetId = "";



          GetCnav2PagesEnabledResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetCnav2PagesEnabledResult(const std::vector<int>& messages)
            : CommandResult(CmdName, TargetId)
          {

            setMessages(messages);
          }

          GetCnav2PagesEnabledResult(CommandBasePtr relatedCommand, const std::vector<int>& messages)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setMessages(messages);
          }



          static GetCnav2PagesEnabledResultPtr create(const std::vector<int>& messages)
          {
            return std::make_shared<GetCnav2PagesEnabledResult>(messages);
          }

          static GetCnav2PagesEnabledResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& messages)
          {
            return std::make_shared<GetCnav2PagesEnabledResult>(relatedCommand, messages);
          }

      static GetCnav2PagesEnabledResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCnav2PagesEnabledResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetCnav2PagesEnabledResult);
  }
}

