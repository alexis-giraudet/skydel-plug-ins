#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssEphBoolParamForEachSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names
    /// Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssEphBoolParamForEachSVResult;
    typedef std::shared_ptr<GetQzssEphBoolParamForEachSVResult> GetQzssEphBoolParamForEachSVResultPtr;
    typedef GetQzssEphBoolParamForEachSVResult GetQzssEphemerisBoolParamsResult;
    typedef std::shared_ptr<GetQzssEphemerisBoolParamsResult> GetQzssEphemerisBoolParamsResultPtr;
    
    class GetQzssEphBoolParamForEachSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetQzssEphBoolParamForEachSVResult";
      inline static const char* const Documentation = "Result of GetQzssEphBoolParamForEachSV.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- --------------------------------------------------------------------------------------------------\n"      "ParamName   string          Refer to SetQzssEphemerisBoolParam for accepted names\n"      "Val         array bool      Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetQzssEphBoolParamForEachSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetQzssEphBoolParamForEachSVResult(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetQzssEphBoolParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }



          static GetQzssEphBoolParamForEachSVResultPtr create(const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetQzssEphBoolParamForEachSVResult>(paramName, val, dataSetName);
          }

          static GetQzssEphBoolParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<bool>& val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetQzssEphBoolParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
          }

      static GetQzssEphBoolParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetQzssEphBoolParamForEachSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
        return names; 
      }
      


          std::string paramName() const
          {
            return parse_json<std::string>::parse(m_values["ParamName"]);
          }

          void setParamName(const std::string& paramName)
          {
            m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<bool> val() const
          {
            return parse_json<std::vector<bool>>::parse(m_values["Val"]);
          }

          void setVal(const std::vector<bool>& val)
          {
            m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetQzssEphBoolParamForEachSVResult);
  }
}

