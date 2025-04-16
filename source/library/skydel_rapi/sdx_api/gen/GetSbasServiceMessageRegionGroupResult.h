#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/SbasServiceMessageRegion.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasServiceMessageRegionGroup.
    ///
    /// Name            Type                           Description
    /// --------------- ------------------------------ ---------------------------------------------------------------------------------
    /// ServiceProvider string                         Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].
    /// PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].
    /// Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].
    /// Id              string                         Unique identifier of the SBAS service message region group.
    ///

    class GetSbasServiceMessageRegionGroupResult;
    typedef std::shared_ptr<GetSbasServiceMessageRegionGroupResult> GetSbasServiceMessageRegionGroupResultPtr;
    
    
    class GetSbasServiceMessageRegionGroupResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSbasServiceMessageRegionGroupResult";
      inline static const char* const Documentation = "Result of GetSbasServiceMessageRegionGroup.\n"      "\n"      "Name            Type                           Description\n"      "--------------- ------------------------------ ---------------------------------------------------------------------------------\n"      "ServiceProvider string                         Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"      "DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].\n"      "PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].\n"      "Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].\n"      "Id              string                         Unique identifier of the SBAS service message region group.";
      inline static const char* const TargetId = "";



          GetSbasServiceMessageRegionGroupResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSbasServiceMessageRegionGroupResult(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setDeltaUdrei(deltaUdrei);
            setPriorityCode(priorityCode);
            setRegions(regions);
            setId(id);
          }

          GetSbasServiceMessageRegionGroupResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setServiceProvider(serviceProvider);
            setDeltaUdrei(deltaUdrei);
            setPriorityCode(priorityCode);
            setRegions(regions);
            setId(id);
          }



          static GetSbasServiceMessageRegionGroupResultPtr create(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
          {
            return std::make_shared<GetSbasServiceMessageRegionGroupResult>(serviceProvider, deltaUdrei, priorityCode, regions, id);
          }

          static GetSbasServiceMessageRegionGroupResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
          {
            return std::make_shared<GetSbasServiceMessageRegionGroupResult>(relatedCommand, serviceProvider, deltaUdrei, priorityCode, regions, id);
          }

      static GetSbasServiceMessageRegionGroupResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSbasServiceMessageRegionGroupResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                  && parse_json<int>::is_valid(m_values["DeltaUdrei"])
                  && parse_json<int>::is_valid(m_values["PriorityCode"])
                  && parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::is_valid(m_values["Regions"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider", "DeltaUdrei", "PriorityCode", "Regions", "Id"}; 
        return names; 
      }
      


          std::string serviceProvider() const
          {
            return parse_json<std::string>::parse(m_values["ServiceProvider"]);
          }

          void setServiceProvider(const std::string& serviceProvider)
          {
            m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int deltaUdrei() const
          {
            return parse_json<int>::parse(m_values["DeltaUdrei"]);
          }

          void setDeltaUdrei(int deltaUdrei)
          {
            m_values.AddMember("DeltaUdrei", parse_json<int>::format(deltaUdrei, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int priorityCode() const
          {
            return parse_json<int>::parse(m_values["PriorityCode"]);
          }

          void setPriorityCode(int priorityCode)
          {
            m_values.AddMember("PriorityCode", parse_json<int>::format(priorityCode, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<Sdx::SbasServiceMessageRegion> regions() const
          {
            return parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::parse(m_values["Regions"]);
          }

          void setRegions(const std::vector<Sdx::SbasServiceMessageRegion>& regions)
          {
            m_values.AddMember("Regions", parse_json<std::vector<Sdx::SbasServiceMessageRegion>>::format(regions, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetSbasServiceMessageRegionGroupResult);
  }
}

