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
    /// Get the UDREI value transmitted by SBAS for the satellite of the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------
    /// System string "GPS" or "SBAS".
    /// SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).
    ///

    class GetUdreiForSV;
    typedef std::shared_ptr<GetUdreiForSV> GetUdreiForSVPtr;
    
    
    class GetUdreiForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetUdreiForSV";
      inline static const char* const Documentation = "Get the UDREI value transmitted by SBAS for the satellite of the specified constellation.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ---------------------------------------------------------------\n"      "System string \"GPS\" or \"SBAS\".\n"      "SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).";
      inline static const char* const TargetId = "";



          GetUdreiForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetUdreiForSV(const std::string& system, int svId)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
          }


          static GetUdreiForSVPtr create(const std::string& system, int svId)
          {
            return std::make_shared<GetUdreiForSV>(system, svId);
          }

      static GetUdreiForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetUdreiForSV>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetUdreiForSV);
  }
}

