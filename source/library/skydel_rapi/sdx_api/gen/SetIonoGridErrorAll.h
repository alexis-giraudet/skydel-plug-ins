#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name Type               Description
    /// ---- ------------------ -----------------------------------------------------------------------
    /// Grid array array double Array containing each band, each band is an array containing the errors
    ///

    class SetIonoGridErrorAll;
    typedef std::shared_ptr<SetIonoGridErrorAll> SetIonoGridErrorAllPtr;
    
    
    class SetIonoGridErrorAll : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIonoGridErrorAll";
      inline static const char* const Documentation = "Set Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.\n"      "\n"      "Name Type               Description\n"      "---- ------------------ -----------------------------------------------------------------------\n"      "Grid array array double Array containing each band, each band is an array containing the errors";
      inline static const char* const TargetId = "";



          SetIonoGridErrorAll()
            : CommandBase(CmdName, TargetId)
          {}

          SetIonoGridErrorAll(const std::vector<std::vector<double>>& grid)
            : CommandBase(CmdName, TargetId)
          {

            setGrid(grid);
          }


          static SetIonoGridErrorAllPtr create(const std::vector<std::vector<double>>& grid)
          {
            return std::make_shared<SetIonoGridErrorAll>(grid);
          }

      static SetIonoGridErrorAllPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIonoGridErrorAll>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Grid"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Grid"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::vector<std::vector<double>> grid() const
          {
            return parse_json<std::vector<std::vector<double>>>::parse(m_values["Grid"]);
          }

          void setGrid(const std::vector<std::vector<double>>& grid)
          {
            m_values.AddMember("Grid", parse_json<std::vector<std::vector<double>>>::format(grid, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetIonoGridErrorAll);
  }
}

