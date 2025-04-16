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
    /// Swaps 2 SBAS service message region group.
    ///
    /// Name            Type   Description
    /// --------------- ------ ---------------------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// FirstId         string Unique identifier of the SBAS service message region group to swap with SecondId.
    /// SecondId        string Unique identifier of the SBAS service message region group to swap with FirstId.
    ///

    class SwapSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<SwapSbasServiceMessageRegionGroup> SwapSbasServiceMessageRegionGroupPtr;
    
    
    class SwapSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SwapSbasServiceMessageRegionGroup";
      inline static const char* const Documentation = "Swaps 2 SBAS service message region group.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ ---------------------------------------------------------------------------------\n"      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"      "FirstId         string Unique identifier of the SBAS service message region group to swap with SecondId.\n"      "SecondId        string Unique identifier of the SBAS service message region group to swap with FirstId.";
      inline static const char* const TargetId = "";



          SwapSbasServiceMessageRegionGroup()
            : CommandBase(CmdName, TargetId)
          {}

          SwapSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& firstId, const std::string& secondId)
            : CommandBase(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setFirstId(firstId);
            setSecondId(secondId);
          }


          static SwapSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, const std::string& firstId, const std::string& secondId)
          {
            return std::make_shared<SwapSbasServiceMessageRegionGroup>(serviceProvider, firstId, secondId);
          }

      static SwapSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SwapSbasServiceMessageRegionGroup>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                  && parse_json<std::string>::is_valid(m_values["FirstId"])
                  && parse_json<std::string>::is_valid(m_values["SecondId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider", "FirstId", "SecondId"}; 
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



          std::string firstId() const
          {
            return parse_json<std::string>::parse(m_values["FirstId"]);
          }

          void setFirstId(const std::string& firstId)
          {
            m_values.AddMember("FirstId", parse_json<std::string>::format(firstId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string secondId() const
          {
            return parse_json<std::string>::parse(m_values["SecondId"]);
          }

          void setSecondId(const std::string& secondId)
          {
            m_values.AddMember("SecondId", parse_json<std::string>::format(secondId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SwapSbasServiceMessageRegionGroup);
  }
}

