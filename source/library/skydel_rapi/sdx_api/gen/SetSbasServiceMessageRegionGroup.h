#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include "gen/SbasServiceMessageRegion.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set (or Modify) a SBAS service message region group.
    ///
    /// Name            Type                           Description
    /// --------------- ------------------------------ ---------------------------------------------------------------------------------
    /// ServiceProvider string                         Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].
    /// PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].
    /// Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].
    /// Id              string                         Unique identifier of the SBAS service message region group.
    ///

    class SetSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<SetSbasServiceMessageRegionGroup> SetSbasServiceMessageRegionGroupPtr;
    
    
    class SetSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSbasServiceMessageRegionGroup";
      inline static const char* const Documentation = "Set (or Modify) a SBAS service message region group.\n"      "\n"      "Name            Type                           Description\n"      "--------------- ------------------------------ ---------------------------------------------------------------------------------\n"      "ServiceProvider string                         Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"      "DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].\n"      "PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].\n"      "Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].\n"      "Id              string                         Unique identifier of the SBAS service message region group.";
      inline static const char* const TargetId = "";



          SetSbasServiceMessageRegionGroup()
            : CommandBase(CmdName, TargetId)
          {}

          SetSbasServiceMessageRegionGroup(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setDeltaUdrei(deltaUdrei);
            setPriorityCode(priorityCode);
            setRegions(regions);
            setId(id);
          }


          static SetSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id)
          {
            return std::make_shared<SetSbasServiceMessageRegionGroup>(serviceProvider, deltaUdrei, priorityCode, regions, id);
          }

      static SetSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSbasServiceMessageRegionGroup>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetSbasServiceMessageRegionGroup);
  }
}

