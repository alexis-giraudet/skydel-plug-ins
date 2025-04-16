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
    /// Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get various boolean parameters in the QZSS ephemeris
    /// 
    ///   ParamName
    /// "IscL1CaAvailable"
    /// "IscL2CAvailable"
    /// "IscL5I5Available"
    /// "IscL5Q5Available"
    /// "IscL1CPAvailable"
    /// "IscL1CDAvailable"
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphBoolParamForSV;
    typedef std::shared_ptr<GetQzssEphBoolParamForSV> GetQzssEphBoolParamForSVPtr;
    
    
    class GetQzssEphBoolParamForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetQzssEphBoolParamForSV";
      inline static const char* const Documentation = "Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"      "\n"      "Get various boolean parameters in the QZSS ephemeris\n"      "\n"      "  ParamName\n"      "\"IscL1CaAvailable\"\n"      "\"IscL2CAvailable\"\n"      "\"IscL5I5Available\"\n"      "\"IscL5Q5Available\"\n"      "\"IscL1CPAvailable\"\n"      "\"IscL1CDAvailable\"\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites\n"      "ParamName   string          Parameter name (see table above for accepted names)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command GetQzssEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";



          GetQzssEphBoolParamForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetQzssEphBoolParamForSV(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setParamName(paramName);
            setDataSetName(dataSetName);
          }


          static GetQzssEphBoolParamForSVPtr create(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetQzssEphBoolParamForSV>(svId, paramName, dataSetName);
          }

      static GetQzssEphBoolParamForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetQzssEphBoolParamForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "ParamName", "DataSetName"}; 
        return names; 
      }
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



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



          std::string paramName() const
          {
            return parse_json<std::string>::parse(m_values["ParamName"]);
          }

          void setParamName(const std::string& paramName)
          {
            m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetQzssEphBoolParamForSV);
  }
}

