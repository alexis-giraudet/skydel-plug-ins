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
    /// Get infos about the GPS CNAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToGpsCNav;
    typedef std::shared_ptr<GetMessageModificationToGpsCNav> GetMessageModificationToGpsCNavPtr;
    
    
    class GetMessageModificationToGpsCNav : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetMessageModificationToGpsCNav";
      inline static const char* const Documentation = "Get infos about the GPS CNAV message modification with this ID.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Unique identifier of the event";
      inline static const char* const TargetId = "";



          GetMessageModificationToGpsCNav()
            : CommandBase(CmdName, TargetId)
          {}

          GetMessageModificationToGpsCNav(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static GetMessageModificationToGpsCNavPtr create(const std::string& id)
          {
            return std::make_shared<GetMessageModificationToGpsCNav>(id);
          }

      static GetMessageModificationToGpsCNavPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetMessageModificationToGpsCNav>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetMessageModificationToGpsCNav);
  }
}

