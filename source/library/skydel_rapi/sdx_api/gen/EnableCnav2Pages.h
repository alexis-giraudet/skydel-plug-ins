#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the enabled L1C CNAV2 pages
    ///
    /// Name     Type      Description
    /// -------- --------- -----------------
    /// Messages array int The enabled pages
    ///

    class EnableCnav2Pages;
    typedef std::shared_ptr<EnableCnav2Pages> EnableCnav2PagesPtr;
    
    
    class EnableCnav2Pages : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableCnav2Pages";
      inline static const char* const Documentation = "Set the enabled L1C CNAV2 pages\n"      "\n"      "Name     Type      Description\n"      "-------- --------- -----------------\n"      "Messages array int The enabled pages";
      inline static const char* const TargetId = "";



          EnableCnav2Pages()
            : CommandBase(CmdName, TargetId)
          {}

          EnableCnav2Pages(const std::vector<int>& messages)
            : CommandBase(CmdName, TargetId)
          {

            setMessages(messages);
          }


          static EnableCnav2PagesPtr create(const std::vector<int>& messages)
          {
            return std::make_shared<EnableCnav2Pages>(messages);
          }

      static EnableCnav2PagesPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableCnav2Pages>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(EnableCnav2Pages);
  }
}

