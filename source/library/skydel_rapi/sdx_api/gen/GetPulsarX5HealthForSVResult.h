#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPulsarX5HealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.
    /// Health      bool            X5 health, false = Signal not operational, true = Signal operational
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetPulsarX5HealthForSVResult;
    typedef std::shared_ptr<GetPulsarX5HealthForSVResult> GetPulsarX5HealthForSVResultPtr;
    
    
    class GetPulsarX5HealthForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetPulsarX5HealthForSVResult";
      inline static const char* const Documentation = "Result of GetPulsarX5HealthForSV.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.\n"      "Health      bool            X5 health, false = Signal not operational, true = Signal operational\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetPulsarX5HealthForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetPulsarX5HealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setHealth(health);
            setDataSetName(dataSetName);
          }

          GetPulsarX5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setHealth(health);
            setDataSetName(dataSetName);
          }



          static GetPulsarX5HealthForSVResultPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetPulsarX5HealthForSVResult>(svId, health, dataSetName);
          }

          static GetPulsarX5HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetPulsarX5HealthForSVResult>(relatedCommand, svId, health, dataSetName);
          }

      static GetPulsarX5HealthForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPulsarX5HealthForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Health"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
        return names; 
      }
      


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool health() const
          {
            return parse_json<bool>::parse(m_values["Health"]);
          }

          void setHealth(bool health)
          {
            m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetPulsarX5HealthForSVResult);
  }
}

