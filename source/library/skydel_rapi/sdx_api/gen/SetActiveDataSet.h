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
    /// Set active data set.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetName string The name of the data set to set as active.
    ///

    class SetActiveDataSet;
    typedef std::shared_ptr<SetActiveDataSet> SetActiveDataSetPtr;
    
    
    class SetActiveDataSet : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetActiveDataSet";
      inline static const char* const Documentation = "Set active data set.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -------------------------------------------------------\n"      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "DataSetName string The name of the data set to set as active.";
      inline static const char* const TargetId = "";



          SetActiveDataSet()
            : CommandBase(CmdName, TargetId)
          {}

          SetActiveDataSet(const std::string& system, const std::string& dataSetName)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setDataSetName(dataSetName);
          }


          static SetActiveDataSetPtr create(const std::string& system, const std::string& dataSetName)
          {
            return std::make_shared<SetActiveDataSet>(system, dataSetName);
          }

      static SetActiveDataSetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetActiveDataSet>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::string>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetActiveDataSet);
  }
}

