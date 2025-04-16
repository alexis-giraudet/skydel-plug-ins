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
    /// Result of GetUdreiForSV.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------
    /// System string "GPS" or "SBAS".
    /// SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).
    /// Udrei  int    The UDREI value.
    ///

    class GetUdreiForSVResult;
    typedef std::shared_ptr<GetUdreiForSVResult> GetUdreiForSVResultPtr;
    
    
    class GetUdreiForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetUdreiForSVResult";
      inline static const char* const Documentation = "Result of GetUdreiForSV.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ---------------------------------------------------------------\n"      "System string \"GPS\" or \"SBAS\".\n"      "SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).\n"      "Udrei  int    The UDREI value.";
      inline static const char* const TargetId = "";



          GetUdreiForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetUdreiForSVResult(const std::string& system, int svId, int udrei)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setUdrei(udrei);
          }

          GetUdreiForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setUdrei(udrei);
          }



          static GetUdreiForSVResultPtr create(const std::string& system, int svId, int udrei)
          {
            return std::make_shared<GetUdreiForSVResult>(system, svId, udrei);
          }

          static GetUdreiForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei)
          {
            return std::make_shared<GetUdreiForSVResult>(relatedCommand, system, svId, udrei);
          }

      static GetUdreiForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetUdreiForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["Udrei"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "Udrei"}; 
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



          int udrei() const
          {
            return parse_json<int>::parse(m_values["Udrei"]);
          }

          void setUdrei(int udrei)
          {
            m_values.AddMember("Udrei", parse_json<int>::format(udrei, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetUdreiForSVResult);
  }
}

