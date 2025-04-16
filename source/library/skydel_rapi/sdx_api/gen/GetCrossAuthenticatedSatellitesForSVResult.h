#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetCrossAuthenticatedSatellitesForSV.
    ///
    /// Name     Type      Description
    /// -------- --------- -------------------------------------------------------------------
    /// SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).
    /// SvIdList array int A list of the cross-authenticated satellites' SV IDs.
    ///

    class GetCrossAuthenticatedSatellitesForSVResult;
    typedef std::shared_ptr<GetCrossAuthenticatedSatellitesForSVResult> GetCrossAuthenticatedSatellitesForSVResultPtr;
    
    
    class GetCrossAuthenticatedSatellitesForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetCrossAuthenticatedSatellitesForSVResult";
      inline static const char* const Documentation = "Result of GetCrossAuthenticatedSatellitesForSV.\n"      "\n"      "Name     Type      Description\n"      "-------- --------- -------------------------------------------------------------------\n"      "SvId     int       The satellite's SV ID (use 0 to apply on all Galileo's satellites).\n"      "SvIdList array int A list of the cross-authenticated satellites' SV IDs.";
      inline static const char* const TargetId = "";



          GetCrossAuthenticatedSatellitesForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetCrossAuthenticatedSatellitesForSVResult(int svId, const std::vector<int>& svIdList)
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setSvIdList(svIdList);
          }

          GetCrossAuthenticatedSatellitesForSVResult(CommandBasePtr relatedCommand, int svId, const std::vector<int>& svIdList)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setSvIdList(svIdList);
          }



          static GetCrossAuthenticatedSatellitesForSVResultPtr create(int svId, const std::vector<int>& svIdList)
          {
            return std::make_shared<GetCrossAuthenticatedSatellitesForSVResult>(svId, svIdList);
          }

          static GetCrossAuthenticatedSatellitesForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::vector<int>& svIdList)
          {
            return std::make_shared<GetCrossAuthenticatedSatellitesForSVResult>(relatedCommand, svId, svIdList);
          }

      static GetCrossAuthenticatedSatellitesForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCrossAuthenticatedSatellitesForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::vector<int>>::is_valid(m_values["SvIdList"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "SvIdList"}; 
        return names; 
      }
      


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<int> svIdList() const
          {
            return parse_json<std::vector<int>>::parse(m_values["SvIdList"]);
          }

          void setSvIdList(const std::vector<int>& svIdList)
          {
            m_values.AddMember("SvIdList", parse_json<std::vector<int>>::format(svIdList, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetCrossAuthenticatedSatellitesForSVResult);
  }
}

