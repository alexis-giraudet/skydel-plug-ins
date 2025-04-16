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
    /// Result of GetGpsSignalHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32
    /// Health      int             Signal health 0..31
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsSignalHealthForSVResult;
    typedef std::shared_ptr<GetGpsSignalHealthForSVResult> GetGpsSignalHealthForSVResultPtr;
    
    
    class GetGpsSignalHealthForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGpsSignalHealthForSVResult";
      inline static const char* const Documentation = "Result of GetGpsSignalHealthForSV.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite's SV ID 1..32\n"      "Health      int             Signal health 0..31\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetGpsSignalHealthForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGpsSignalHealthForSVResult(int svId, int health, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setHealth(health);
            setDataSetName(dataSetName);
          }

          GetGpsSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setHealth(health);
            setDataSetName(dataSetName);
          }



          static GetGpsSignalHealthForSVResultPtr create(int svId, int health, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsSignalHealthForSVResult>(svId, health, dataSetName);
          }

          static GetGpsSignalHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsSignalHealthForSVResult>(relatedCommand, svId, health, dataSetName);
          }

      static GetGpsSignalHealthForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpsSignalHealthForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["Health"])
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



          int health() const
          {
            return parse_json<int>::parse(m_values["Health"]);
          }

          void setHealth(int health)
          {
            m_values.AddMember("Health", parse_json<int>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetGpsSignalHealthForSVResult);
  }
}

