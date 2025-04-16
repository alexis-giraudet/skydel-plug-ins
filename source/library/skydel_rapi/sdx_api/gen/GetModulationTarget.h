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
    /// Get a modulation target.
    /// If Id is not set, or if new, a new target is added.
    /// For setter : If the Id is already used, the corresponding target is updated.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------------------------
    /// Id   string Unique identifier automatically set by simulator
    ///

    class GetModulationTarget;
    typedef std::shared_ptr<GetModulationTarget> GetModulationTargetPtr;
    
    
    class GetModulationTarget : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetModulationTarget";
      inline static const char* const Documentation = "Get a modulation target.\n"      "If Id is not set, or if new, a new target is added.\n"      "For setter : If the Id is already used, the corresponding target is updated.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------------------------\n"      "Id   string Unique identifier automatically set by simulator";
      inline static const char* const TargetId = "";



          GetModulationTarget()
            : CommandBase(CmdName, TargetId)
          {}

          GetModulationTarget(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static GetModulationTargetPtr create(const std::string& id)
          {
            return std::make_shared<GetModulationTarget>(id);
          }

      static GetModulationTargetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetModulationTarget>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetModulationTarget);
  }
}

