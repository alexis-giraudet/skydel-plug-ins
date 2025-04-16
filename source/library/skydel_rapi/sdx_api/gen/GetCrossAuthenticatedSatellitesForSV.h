#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the list of satellites that are cross-authenticated by the specified satellite.
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------------
    /// SvId int  The satellite's SV ID (use 0 to apply on all Galileo's satellites).
    ///

    class GetCrossAuthenticatedSatellitesForSV;
    typedef std::shared_ptr<GetCrossAuthenticatedSatellitesForSV> GetCrossAuthenticatedSatellitesForSVPtr;
    
    
    class GetCrossAuthenticatedSatellitesForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetCrossAuthenticatedSatellitesForSV";
      inline static const char* const Documentation = "Get the list of satellites that are cross-authenticated by the specified satellite.\n"      "\n"      "Name Type Description\n"      "---- ---- -------------------------------------------------------------------\n"      "SvId int  The satellite's SV ID (use 0 to apply on all Galileo's satellites).";
      inline static const char* const TargetId = "";



          GetCrossAuthenticatedSatellitesForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetCrossAuthenticatedSatellitesForSV(int svId)
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
          }


          static GetCrossAuthenticatedSatellitesForSVPtr create(int svId)
          {
            return std::make_shared<GetCrossAuthenticatedSatellitesForSV>(svId);
          }

      static GetCrossAuthenticatedSatellitesForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCrossAuthenticatedSatellitesForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetCrossAuthenticatedSatellitesForSV);
  }
}

