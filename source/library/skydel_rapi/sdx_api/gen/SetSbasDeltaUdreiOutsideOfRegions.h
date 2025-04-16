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
    /// Set SBAS delta UDREI outside all the defined regions for this service provider.
    ///
    /// Name            Type   Description
    /// --------------- ------ ----------------------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int    Delta UDREI applicable outside all the defined regions. Accepted range is [0..15].
    ///

    class SetSbasDeltaUdreiOutsideOfRegions;
    typedef std::shared_ptr<SetSbasDeltaUdreiOutsideOfRegions> SetSbasDeltaUdreiOutsideOfRegionsPtr;
    
    
    class SetSbasDeltaUdreiOutsideOfRegions : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSbasDeltaUdreiOutsideOfRegions";
      inline static const char* const Documentation = "Set SBAS delta UDREI outside all the defined regions for this service provider.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ ----------------------------------------------------------------------------------\n"      "ServiceProvider string Service providers, accepts \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\" and \"SDCM\".\n"      "DeltaUdrei      int    Delta UDREI applicable outside all the defined regions. Accepted range is [0..15].";
      inline static const char* const TargetId = "";



          SetSbasDeltaUdreiOutsideOfRegions()
            : CommandBase(CmdName, TargetId)
          {}

          SetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider, int deltaUdrei)
            : CommandBase(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setDeltaUdrei(deltaUdrei);
          }


          static SetSbasDeltaUdreiOutsideOfRegionsPtr create(const std::string& serviceProvider, int deltaUdrei)
          {
            return std::make_shared<SetSbasDeltaUdreiOutsideOfRegions>(serviceProvider, deltaUdrei);
          }

      static SetSbasDeltaUdreiOutsideOfRegionsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSbasDeltaUdreiOutsideOfRegions>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                  && parse_json<int>::is_valid(m_values["DeltaUdrei"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider", "DeltaUdrei"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(SetSbasDeltaUdreiOutsideOfRegions);
  }
}

