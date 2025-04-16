#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/GpsASFlag.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsAntiSpoofingFlagForSV.
    ///
    /// Name         Type            Description
    /// ------------ --------------- -------------------------------------------------------------------------------------------
    /// SvId         int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// AntiSpoofing GpsASFlag       GPS Anti-Spoofing Flag.
    /// DataSetName  optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsAntiSpoofingFlagForSVResult;
    typedef std::shared_ptr<GetGpsAntiSpoofingFlagForSVResult> GetGpsAntiSpoofingFlagForSVResultPtr;
    
    
    class GetGpsAntiSpoofingFlagForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGpsAntiSpoofingFlagForSVResult";
      inline static const char* const Documentation = "Result of GetGpsAntiSpoofingFlagForSV.\n"      "\n"      "Name         Type            Description\n"      "------------ --------------- -------------------------------------------------------------------------------------------\n"      "SvId         int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.\n"      "AntiSpoofing GpsASFlag       GPS Anti-Spoofing Flag.\n"      "DataSetName  optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetGpsAntiSpoofingFlagForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGpsAntiSpoofingFlagForSVResult(int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setAntiSpoofing(antiSpoofing);
            setDataSetName(dataSetName);
          }

          GetGpsAntiSpoofingFlagForSVResult(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setAntiSpoofing(antiSpoofing);
            setDataSetName(dataSetName);
          }



          static GetGpsAntiSpoofingFlagForSVResultPtr create(int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsAntiSpoofingFlagForSVResult>(svId, antiSpoofing, dataSetName);
          }

          static GetGpsAntiSpoofingFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const Sdx::GpsASFlag& antiSpoofing, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsAntiSpoofingFlagForSVResult>(relatedCommand, svId, antiSpoofing, dataSetName);
          }

      static GetGpsAntiSpoofingFlagForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpsAntiSpoofingFlagForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<Sdx::GpsASFlag>::is_valid(m_values["AntiSpoofing"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "AntiSpoofing", "DataSetName"}; 
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



          Sdx::GpsASFlag antiSpoofing() const
          {
            return parse_json<Sdx::GpsASFlag>::parse(m_values["AntiSpoofing"]);
          }

          void setAntiSpoofing(const Sdx::GpsASFlag& antiSpoofing)
          {
            m_values.AddMember("AntiSpoofing", parse_json<Sdx::GpsASFlag>::format(antiSpoofing, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetGpsAntiSpoofingFlagForSVResult);
  }
}

