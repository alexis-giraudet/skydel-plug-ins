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
    /// Result of GetGpsEphBoolParamForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..32, or use 0 to apply new value to all satellites
    /// ParamName   string          Parameter name (see table above for accepted names)
    /// Val         bool            Parameter value (see table above for unit)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsEphBoolParamForSVResult;
    typedef std::shared_ptr<GetGpsEphBoolParamForSVResult> GetGpsEphBoolParamForSVResultPtr;
    
    
    class GetGpsEphBoolParamForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGpsEphBoolParamForSVResult";
      inline static const char* const Documentation = "Result of GetGpsEphBoolParamForSV.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..32, or use 0 to apply new value to all satellites\n"      "ParamName   string          Parameter name (see table above for accepted names)\n"      "Val         bool            Parameter value (see table above for unit)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetGpsEphBoolParamForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGpsEphBoolParamForSVResult(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetGpsEphBoolParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }



          static GetGpsEphBoolParamForSVResultPtr create(int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsEphBoolParamForSVResult>(svId, paramName, val, dataSetName);
          }

          static GetGpsEphBoolParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsEphBoolParamForSVResult>(relatedCommand, svId, paramName, val, dataSetName);
          }

      static GetGpsEphBoolParamForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpsEphBoolParamForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && parse_json<bool>::is_valid(m_values["Val"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "ParamName", "Val", "DataSetName"}; 
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



          std::string paramName() const
          {
            return parse_json<std::string>::parse(m_values["ParamName"]);
          }

          void setParamName(const std::string& paramName)
          {
            m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool val() const
          {
            return parse_json<bool>::parse(m_values["Val"]);
          }

          void setVal(bool val)
          {
            m_values.AddMember("Val", parse_json<bool>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetGpsEphBoolParamForSVResult);
  }
}

