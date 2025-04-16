#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetDataSetAssignation.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetType string "Almanac", "Ephemeris" or "Orbit"
    /// DataSetName string The name of the assigned data set.
    ///

    class GetDataSetAssignationResult;
    typedef std::shared_ptr<GetDataSetAssignationResult> GetDataSetAssignationResultPtr;
    
    
    class GetDataSetAssignationResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetDataSetAssignationResult";
      inline static const char* const Documentation = "Result of GetDataSetAssignation.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -------------------------------------------------------\n"      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "DataSetType string \"Almanac\", \"Ephemeris\" or \"Orbit\"\n"      "DataSetName string The name of the assigned data set.";
      inline static const char* const TargetId = "";



          GetDataSetAssignationResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetDataSetAssignationResult(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setDataSetType(dataSetType);
            setDataSetName(dataSetName);
          }

          GetDataSetAssignationResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setDataSetType(dataSetType);
            setDataSetName(dataSetName);
          }



          static GetDataSetAssignationResultPtr create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
          {
            return std::make_shared<GetDataSetAssignationResult>(system, dataSetType, dataSetName);
          }

          static GetDataSetAssignationResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
          {
            return std::make_shared<GetDataSetAssignationResult>(relatedCommand, system, dataSetType, dataSetName);
          }

      static GetDataSetAssignationResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetDataSetAssignationResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::string>::is_valid(m_values["DataSetType"])
                  && parse_json<std::string>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "DataSetType", "DataSetName"}; 
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



          std::string dataSetType() const
          {
            return parse_json<std::string>::parse(m_values["DataSetType"]);
          }

          void setDataSetType(const std::string& dataSetType)
          {
            m_values.AddMember("DataSetType", parse_json<std::string>::format(dataSetType, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string dataSetName() const
          {
            return parse_json<std::string>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::string& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetDataSetAssignationResult);
  }
}

