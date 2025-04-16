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
    /// Please note the command GetBeiDouEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.
    /// 
    /// Get various boolean parameters in the BeiDou ephemeris
    /// 
    ///   ParamName
    /// "IscB1CdAvailable"
    /// "IscB2adAvailable"
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetBeiDouEphBoolParamForSV;
    typedef std::shared_ptr<GetBeiDouEphBoolParamForSV> GetBeiDouEphBoolParamForSVPtr;
    
    
    class GetBeiDouEphBoolParamForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetBeiDouEphBoolParamForSV";
      inline static const char* const Documentation = "Please note the command GetBeiDouEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.\n"      "\n"      "Get various boolean parameters in the BeiDou ephemeris\n"      "\n"      "  ParamName\n"      "\"IscB1CdAvailable\"\n"      "\"IscB2adAvailable\"\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..35, or use 0 to apply new value to all satellites\n"      "ParamName   string          Parameter name (see table above for accepted names)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command GetBeiDouEphBoolParamForSV is deprecated since 23.11. You may use GetConstellationParameterForSV.";



          GetBeiDouEphBoolParamForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetBeiDouEphBoolParamForSV(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setParamName(paramName);
            setDataSetName(dataSetName);
          }


          static GetBeiDouEphBoolParamForSVPtr create(int svId, const std::string& paramName, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetBeiDouEphBoolParamForSV>(svId, paramName, dataSetName);
          }

      static GetBeiDouEphBoolParamForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetBeiDouEphBoolParamForSV>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetBeiDouEphBoolParamForSV);
  }
}

