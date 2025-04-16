#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name            Type             Description
    /// --------------- ---------------- ----------------------------------------------------------------------
    /// ServiceProvider string           The service provider
    /// Grid            array array bool Array containing each band, each band is an array containing the flags
    ///

    class SetIonoGridMaskAll;
    typedef std::shared_ptr<SetIonoGridMaskAll> SetIonoGridMaskAllPtr;
    
    
    class SetIonoGridMaskAll : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIonoGridMaskAll";
      inline static const char* const Documentation = "Set Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.\n"      "\n"      "Name            Type             Description\n"      "--------------- ---------------- ----------------------------------------------------------------------\n"      "ServiceProvider string           The service provider\n"      "Grid            array array bool Array containing each band, each band is an array containing the flags";
      inline static const char* const TargetId = "";



          SetIonoGridMaskAll()
            : CommandBase(CmdName, TargetId)
          {}

          SetIonoGridMaskAll(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
            : CommandBase(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setGrid(grid);
          }


          static SetIonoGridMaskAllPtr create(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
          {
            return std::make_shared<SetIonoGridMaskAll>(serviceProvider, grid);
          }

      static SetIonoGridMaskAllPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIonoGridMaskAll>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                  && parse_json<std::vector<std::vector<bool>>>::is_valid(m_values["Grid"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider", "Grid"}; 
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



          std::vector<std::vector<bool>> grid() const
          {
            return parse_json<std::vector<std::vector<bool>>>::parse(m_values["Grid"]);
          }

          void setGrid(const std::vector<std::vector<bool>>& grid)
          {
            m_values.AddMember("Grid", parse_json<std::vector<std::vector<bool>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetIonoGridMaskAll);
  }
}

