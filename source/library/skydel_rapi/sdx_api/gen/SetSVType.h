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
    /// Set the type of a SV.
    /// Satellite SV ID accepted values (0 for all SVs):
    /// QZSS 1..10
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// System string Only "QZSS" supported.
    /// SvId   int    Satellite SV ID, see command description for accepted values.
    /// SvType string Type of the SV. QZSS: "BlockI", "BlockII".
    ///

    class SetSVType;
    typedef std::shared_ptr<SetSVType> SetSVTypePtr;
    
    
    class SetSVType : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSVType";
      inline static const char* const Documentation = "Set the type of a SV.\n"      "Satellite SV ID accepted values (0 for all SVs):\n"      "QZSS 1..10\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------\n"      "System string Only \"QZSS\" supported.\n"      "SvId   int    Satellite SV ID, see command description for accepted values.\n"      "SvType string Type of the SV. QZSS: \"BlockI\", \"BlockII\".";
      inline static const char* const TargetId = "";



          SetSVType()
            : CommandBase(CmdName, TargetId)
          {}

          SetSVType(const std::string& system, int svId, const std::string& svType)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setSvType(svType);
          }


          static SetSVTypePtr create(const std::string& system, int svId, const std::string& svType)
          {
            return std::make_shared<SetSVType>(system, svId, svType);
          }

      static SetSVTypePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSVType>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["SvType"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "SvType"}; 
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



          std::string svType() const
          {
            return parse_json<std::string>::parse(m_values["SvType"]);
          }

          void setSvType(const std::string& svType)
          {
            m_values.AddMember("SvType", parse_json<std::string>::format(svType, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetSVType);
  }
}

