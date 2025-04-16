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
    /// Removes a QZSS L1S augmentation.
    ///
    /// Name Type   Description
    /// ---- ------ ----------------------------------------------
    /// Id   string Unique identifier (see SetQzssL1SAugmentation)
    ///

    class RemoveQzssL1SAugmentation;
    typedef std::shared_ptr<RemoveQzssL1SAugmentation> RemoveQzssL1SAugmentationPtr;
    
    
    class RemoveQzssL1SAugmentation : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveQzssL1SAugmentation";
      inline static const char* const Documentation = "Removes a QZSS L1S augmentation.\n"      "\n"      "Name Type   Description\n"      "---- ------ ----------------------------------------------\n"      "Id   string Unique identifier (see SetQzssL1SAugmentation)";
      inline static const char* const TargetId = "";



          RemoveQzssL1SAugmentation()
            : CommandBase(CmdName, TargetId)
          {}

          RemoveQzssL1SAugmentation(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static RemoveQzssL1SAugmentationPtr create(const std::string& id)
          {
            return std::make_shared<RemoveQzssL1SAugmentation>(id);
          }

      static RemoveQzssL1SAugmentationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveQzssL1SAugmentation>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(RemoveQzssL1SAugmentation);
  }
}

