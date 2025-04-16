#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDefaultVehicleAntennaModel.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------
    /// Name string Default antenna model name.
    ///

    class GetDefaultVehicleAntennaModelResult;
    typedef std::shared_ptr<GetDefaultVehicleAntennaModelResult> GetDefaultVehicleAntennaModelResultPtr;
    
    
    class GetDefaultVehicleAntennaModelResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetDefaultVehicleAntennaModelResult";
      inline static const char* const Documentation = "Result of GetDefaultVehicleAntennaModel.\n"      "\n"      "Name Type   Description\n"      "---- ------ ---------------------------\n"      "Name string Default antenna model name.";
      inline static const char* const TargetId = "";



          GetDefaultVehicleAntennaModelResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetDefaultVehicleAntennaModelResult(const std::string& name)
            : CommandResult(CmdName, TargetId)
          {

            setName(name);
          }

          GetDefaultVehicleAntennaModelResult(CommandBasePtr relatedCommand, const std::string& name)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setName(name);
          }



          static GetDefaultVehicleAntennaModelResultPtr create(const std::string& name)
          {
            return std::make_shared<GetDefaultVehicleAntennaModelResult>(name);
          }

          static GetDefaultVehicleAntennaModelResultPtr create(CommandBasePtr relatedCommand, const std::string& name)
          {
            return std::make_shared<GetDefaultVehicleAntennaModelResult>(relatedCommand, name);
          }

      static GetDefaultVehicleAntennaModelResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetDefaultVehicleAntennaModelResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Name"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Name"}; 
        return names; 
      }
      


          std::string name() const
          {
            return parse_json<std::string>::parse(m_values["Name"]);
          }

          void setName(const std::string& name)
          {
            m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetDefaultVehicleAntennaModelResult);
  }
}

