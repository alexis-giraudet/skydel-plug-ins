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
    /// Get the type of a SV.
    /// Satellite SV ID accepted values:
    /// QZSS 1..10
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// System string Only "QZSS" supported.
    /// SvId   int    Satellite SV ID, see command description for accepted values.
    ///

    class GetSVType;
    typedef std::shared_ptr<GetSVType> GetSVTypePtr;
    
    
    class GetSVType : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSVType";
      inline static const char* const Documentation = "Get the type of a SV.\n"      "Satellite SV ID accepted values:\n"      "QZSS 1..10\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------\n"      "System string Only \"QZSS\" supported.\n"      "SvId   int    Satellite SV ID, see command description for accepted values.";
      inline static const char* const TargetId = "";



          GetSVType()
            : CommandBase(CmdName, TargetId)
          {}

          GetSVType(const std::string& system, int svId)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
          }


          static GetSVTypePtr create(const std::string& system, int svId)
          {
            return std::make_shared<GetSVType>(system, svId);
          }

      static GetSVTypePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSVType>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSVType);
  }
}

