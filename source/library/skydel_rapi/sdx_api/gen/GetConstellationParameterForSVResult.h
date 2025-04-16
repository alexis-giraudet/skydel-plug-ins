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
    /// Result of GetConstellationParameterForSV.
    ///
    /// Name        Type                  Description
    /// ----------- --------------------- -------------------------------------------------------------------------------------------
    /// System      string                "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR".
    /// SvId        int                   The Satellite SV ID, or use 0 to apply new value to all satellites.
    /// ParamName   string                Parameter name (see table above for accepted names).
    /// Val         double or int or bool Parameter value (see table above for unit and type).
    /// DataSetName optional string       Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetConstellationParameterForSVResult;
    typedef std::shared_ptr<GetConstellationParameterForSVResult> GetConstellationParameterForSVResultPtr;
    
    
    class GetConstellationParameterForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetConstellationParameterForSVResult";
      inline static const char* const Documentation = "Result of GetConstellationParameterForSV.\n"      "\n"      "Name        Type                  Description\n"      "----------- --------------------- -------------------------------------------------------------------------------------------\n"      "System      string                \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\".\n"      "SvId        int                   The Satellite SV ID, or use 0 to apply new value to all satellites.\n"      "ParamName   string                Parameter name (see table above for accepted names).\n"      "Val         double or int or bool Parameter value (see table above for unit and type).\n"      "DataSetName optional string       Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetConstellationParameterForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, int val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, int val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetConstellationParameterForSVResult(const std::string& system, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetConstellationParameterForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setSvId(svId);
            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }



          static GetConstellationParameterForSVResultPtr create(const std::string& system, int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetConstellationParameterForSVResult>(system, svId, paramName, val, dataSetName);
          }

          static GetConstellationParameterForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, double val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetConstellationParameterForSVResult>(relatedCommand, system, svId, paramName, val, dataSetName);
          }


          static GetConstellationParameterForSVResultPtr create(const std::string& system, int svId, const std::string& paramName, int val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetConstellationParameterForSVResult>(system, svId, paramName, val, dataSetName);
          }

          static GetConstellationParameterForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, int val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetConstellationParameterForSVResult>(relatedCommand, system, svId, paramName, val, dataSetName);
          }


          static GetConstellationParameterForSVResultPtr create(const std::string& system, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetConstellationParameterForSVResult>(system, svId, paramName, val, dataSetName);
          }

          static GetConstellationParameterForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& paramName, bool val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetConstellationParameterForSVResult>(relatedCommand, system, svId, paramName, val, dataSetName);
          }

      static GetConstellationParameterForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetConstellationParameterForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && (parse_json<double>::is_valid(m_values["Val"]) || parse_json<int>::is_valid(m_values["Val"]) || parse_json<bool>::is_valid(m_values["Val"]))
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId", "ParamName", "Val", "DataSetName"}; 
        return names; 
      }
      


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
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



          template<typename Type>
          Type val() const
          {
            return parse_json<Type>::parse(m_values["Val"]);
          }

          template<typename Type>
          void setVal(Type val)
          {
            m_values.AddMember("Val", parse_json<Type>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetConstellationParameterForSVResult);
  }
}

