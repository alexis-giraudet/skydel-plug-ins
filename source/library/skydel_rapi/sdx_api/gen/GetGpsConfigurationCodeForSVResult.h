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
    /// Result of GetGpsConfigurationCodeForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..32
    /// SvConfig    int             SV Config 0..4
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsConfigurationCodeForSVResult;
    typedef std::shared_ptr<GetGpsConfigurationCodeForSVResult> GetGpsConfigurationCodeForSVResultPtr;
    
    
    class GetGpsConfigurationCodeForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGpsConfigurationCodeForSVResult";
      inline static const char* const Documentation = "Result of GetGpsConfigurationCodeForSV.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..32\n"      "SvConfig    int             SV Config 0..4\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetGpsConfigurationCodeForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGpsConfigurationCodeForSVResult(int svId, int svConfig, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setSvConfig(svConfig);
            setDataSetName(dataSetName);
          }

          GetGpsConfigurationCodeForSVResult(CommandBasePtr relatedCommand, int svId, int svConfig, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setSvConfig(svConfig);
            setDataSetName(dataSetName);
          }



          static GetGpsConfigurationCodeForSVResultPtr create(int svId, int svConfig, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsConfigurationCodeForSVResult>(svId, svConfig, dataSetName);
          }

          static GetGpsConfigurationCodeForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int svConfig, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsConfigurationCodeForSVResult>(relatedCommand, svId, svConfig, dataSetName);
          }

      static GetGpsConfigurationCodeForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpsConfigurationCodeForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["SvConfig"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "SvConfig", "DataSetName"}; 
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



          int svConfig() const
          {
            return parse_json<int>::parse(m_values["SvConfig"]);
          }

          void setSvConfig(int svConfig)
          {
            m_values.AddMember("SvConfig", parse_json<int>::format(svConfig, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetGpsConfigurationCodeForSVResult);
  }
}

