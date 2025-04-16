#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get PULSAR X5 health (Health of X5 Signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetPulsarX5HealthForSV;
    typedef std::shared_ptr<GetPulsarX5HealthForSV> GetPulsarX5HealthForSVPtr;
    
    
    class GetPulsarX5HealthForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetPulsarX5HealthForSV";
      inline static const char* const Documentation = "Get PULSAR X5 health (Health of X5 Signal)\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetPulsarX5HealthForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetPulsarX5HealthForSV(int svId, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setDataSetName(dataSetName);
          }


          static GetPulsarX5HealthForSVPtr create(int svId, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetPulsarX5HealthForSV>(svId, dataSetName);
          }

      static GetPulsarX5HealthForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPulsarX5HealthForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::string> dataSetName() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::optional<std::string>& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPulsarX5HealthForSV);
  }
}

