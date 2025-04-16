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
    /// Set data set assignation for the specified constellation.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetType string "Almanac", "Ephemeris" or "Orbit"
    /// DataSetName string The name of the assigned data set.
    ///

    class SetDataSetAssignation;
    typedef std::shared_ptr<SetDataSetAssignation> SetDataSetAssignationPtr;
    
    
    class SetDataSetAssignation : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetDataSetAssignation";
      inline static const char* const Documentation = "Set data set assignation for the specified constellation.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -------------------------------------------------------\n"      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "DataSetType string \"Almanac\", \"Ephemeris\" or \"Orbit\"\n"      "DataSetName string The name of the assigned data set.";
      inline static const char* const TargetId = "";



          SetDataSetAssignation()
            : CommandBase(CmdName, TargetId)
          {}

          SetDataSetAssignation(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setDataSetType(dataSetType);
            setDataSetName(dataSetName);
          }


          static SetDataSetAssignationPtr create(const std::string& system, const std::string& dataSetType, const std::string& dataSetName)
          {
            return std::make_shared<SetDataSetAssignation>(system, dataSetType, dataSetName);
          }

      static SetDataSetAssignationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetDataSetAssignation>(ptr);
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



          std::string dataSetName() const
          {
            return parse_json<std::string>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::string& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetDataSetAssignation);
  }
}

