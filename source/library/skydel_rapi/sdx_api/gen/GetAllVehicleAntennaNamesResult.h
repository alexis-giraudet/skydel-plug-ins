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
    /// Result of GetAllVehicleAntennaNames.
    ///
    /// Name         Type         Description
    /// ------------ ------------ -----------------------------
    /// AntennaNames array string A list of antenna model names
    ///

    class GetAllVehicleAntennaNamesResult;
    typedef std::shared_ptr<GetAllVehicleAntennaNamesResult> GetAllVehicleAntennaNamesResultPtr;
    
    
    class GetAllVehicleAntennaNamesResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetAllVehicleAntennaNamesResult";
      inline static const char* const Documentation = "Result of GetAllVehicleAntennaNames.\n"      "\n"      "Name         Type         Description\n"      "------------ ------------ -----------------------------\n"      "AntennaNames array string A list of antenna model names";
      inline static const char* const TargetId = "";



          GetAllVehicleAntennaNamesResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetAllVehicleAntennaNamesResult(const std::vector<std::string>& antennaNames)
            : CommandResult(CmdName, TargetId)
          {

            setAntennaNames(antennaNames);
          }

          GetAllVehicleAntennaNamesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setAntennaNames(antennaNames);
          }



          static GetAllVehicleAntennaNamesResultPtr create(const std::vector<std::string>& antennaNames)
          {
            return std::make_shared<GetAllVehicleAntennaNamesResult>(antennaNames);
          }

          static GetAllVehicleAntennaNamesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames)
          {
            return std::make_shared<GetAllVehicleAntennaNamesResult>(relatedCommand, antennaNames);
          }

      static GetAllVehicleAntennaNamesResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllVehicleAntennaNamesResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaNames"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"AntennaNames"}; 
        return names; 
      }
      


          std::vector<std::string> antennaNames() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["AntennaNames"]);
          }

          void setAntennaNames(const std::vector<std::string>& antennaNames)
          {
            m_values.AddMember("AntennaNames", parse_json<std::vector<std::string>>::format(antennaNames, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetAllVehicleAntennaNamesResult);
  }
}

