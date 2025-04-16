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
    /// Get Add an augmentation to the L1S navigation messages.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------------------
    /// Id   string Unique identifier of the augmentation.
    ///

    class GetQzssL1SAugmentation;
    typedef std::shared_ptr<GetQzssL1SAugmentation> GetQzssL1SAugmentationPtr;
    
    
    class GetQzssL1SAugmentation : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetQzssL1SAugmentation";
      inline static const char* const Documentation = "Get Add an augmentation to the L1S navigation messages.\n"      "\n"      "Name Type   Description\n"      "---- ------ --------------------------------------\n"      "Id   string Unique identifier of the augmentation.";
      inline static const char* const TargetId = "";



          GetQzssL1SAugmentation()
            : CommandBase(CmdName, TargetId)
          {}

          GetQzssL1SAugmentation(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static GetQzssL1SAugmentationPtr create(const std::string& id)
          {
            return std::make_shared<GetQzssL1SAugmentation>(id);
          }

      static GetQzssL1SAugmentationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetQzssL1SAugmentation>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetQzssL1SAugmentation);
  }
}

