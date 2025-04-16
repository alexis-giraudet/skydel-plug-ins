#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get data set assignation for the specified constellation.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetType string "Almanac", "Ephemeris" or "Orbit"
    ///

    class GetDataSetAssignation;
    typedef std::shared_ptr<GetDataSetAssignation> GetDataSetAssignationPtr;
    
    
    class GetDataSetAssignation : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetDataSetAssignation";
      inline static const char* const Documentation = "Get data set assignation for the specified constellation.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -------------------------------------------------------\n"      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "DataSetType string \"Almanac\", \"Ephemeris\" or \"Orbit\"";
      inline static const char* const TargetId = "";



          GetDataSetAssignation()
            : CommandBase(CmdName, TargetId)
          {}

          GetDataSetAssignation(const std::string& system, const std::string& dataSetType)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setDataSetType(dataSetType);
          }


          static GetDataSetAssignationPtr create(const std::string& system, const std::string& dataSetType)
          {
            return std::make_shared<GetDataSetAssignation>(system, dataSetType);
          }

      static GetDataSetAssignationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetDataSetAssignation>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::string>::is_valid(m_values["DataSetType"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "DataSetType"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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

    };
    REGISTER_COMMAND_TO_FACTORY(GetDataSetAssignation);
  }
}

