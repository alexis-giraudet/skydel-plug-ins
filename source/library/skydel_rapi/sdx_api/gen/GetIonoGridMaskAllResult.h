#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridMaskAll.
    ///
    /// Name            Type             Description
    /// --------------- ---------------- ----------------------------------------------------------------------
    /// ServiceProvider string           The service provider
    /// Grid            array array bool Array containing each band, each band is an array containing the flags
    ///

    class GetIonoGridMaskAllResult;
    typedef std::shared_ptr<GetIonoGridMaskAllResult> GetIonoGridMaskAllResultPtr;
    
    
    class GetIonoGridMaskAllResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIonoGridMaskAllResult";
      inline static const char* const Documentation = "Result of GetIonoGridMaskAll.\n"      "\n"      "Name            Type             Description\n"      "--------------- ---------------- ----------------------------------------------------------------------\n"      "ServiceProvider string           The service provider\n"      "Grid            array array bool Array containing each band, each band is an array containing the flags";
      inline static const char* const TargetId = "";



          GetIonoGridMaskAllResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIonoGridMaskAllResult(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
            : CommandResult(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setGrid(grid);
          }

          GetIonoGridMaskAllResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setServiceProvider(serviceProvider);
            setGrid(grid);
          }



          static GetIonoGridMaskAllResultPtr create(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
          {
            return std::make_shared<GetIonoGridMaskAllResult>(serviceProvider, grid);
          }

          static GetIonoGridMaskAllResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid)
          {
            return std::make_shared<GetIonoGridMaskAllResult>(relatedCommand, serviceProvider, grid);
          }

      static GetIonoGridMaskAllResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoGridMaskAllResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetIonoGridMaskAllResult);
  }
}

