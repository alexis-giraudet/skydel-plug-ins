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
    /// Get Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------
    /// ServiceProvider string The service provider
    ///

    class GetIonoGridMaskAll;
    typedef std::shared_ptr<GetIonoGridMaskAll> GetIonoGridMaskAllPtr;
    
    
    class GetIonoGridMaskAll : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIonoGridMaskAll";
      inline static const char* const Documentation = "Get Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ --------------------\n"      "ServiceProvider string The service provider";
      inline static const char* const TargetId = "";



          GetIonoGridMaskAll()
            : CommandBase(CmdName, TargetId)
          {}

          GetIonoGridMaskAll(const std::string& serviceProvider)
            : CommandBase(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
          }


          static GetIonoGridMaskAllPtr create(const std::string& serviceProvider)
          {
            return std::make_shared<GetIonoGridMaskAll>(serviceProvider);
          }

      static GetIonoGridMaskAllPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoGridMaskAll>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(GetIonoGridMaskAll);
  }
}

