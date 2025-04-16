#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVType.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// System string Only "QZSS" supported.
    /// SvId   int    Satellite SV ID, see command description for accepted values.
    /// SvType string Type of the SV. QZSS: "BlockI", "BlockII".
    ///

    class GetSVTypeResult;
    typedef std::shared_ptr<GetSVTypeResult> GetSVTypeResultPtr;
    
    
    class GetSVTypeResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSVTypeResult";
      inline static const char* const Documentation = "Result of GetSVType.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------\n"      "System string Only \"QZSS\" supported.\n"      "SvId   int    Satellite SV ID, see command description for accepted values.\n"      "SvType string Type of the SV. QZSS: \"BlockI\", \"BlockII\".";
      inline static const char* const TargetId = "";



          GetSVTypeResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSVTypeResult(const std::string& system, int svId, const std::string& svType)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setSvType(svType);
          }

          GetSVTypeResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& svType)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setSvType(svType);
          }



          static GetSVTypeResultPtr create(const std::string& system, int svId, const std::string& svType)
          {
            return std::make_shared<GetSVTypeResult>(system, svId, svType);
          }

          static GetSVTypeResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& svType)
          {
            return std::make_shared<GetSVTypeResult>(relatedCommand, system, svId, svType);
          }

      static GetSVTypeResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSVTypeResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetSVTypeResult);
  }
}

