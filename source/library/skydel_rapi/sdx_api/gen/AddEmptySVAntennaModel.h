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
    /// Create an empty space vehicle antenna model.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// Name   string SV antenna model name
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class AddEmptySVAntennaModel;
    typedef std::shared_ptr<AddEmptySVAntennaModel> AddEmptySVAntennaModelPtr;
    
    
    class AddEmptySVAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "AddEmptySVAntennaModel";
      inline static const char* const Documentation = "Create an empty space vehicle antenna model.\n"      "\n"      "Name   Type   Description\n"      "------ ------ --------------------------------------------------------------------------\n"      "Name   string SV antenna model name\n"      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
      inline static const char* const TargetId = "";



          AddEmptySVAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          AddEmptySVAntennaModel(const std::string& name, const std::string& system)
            : CommandBase(CmdName, TargetId)
          {

            setName(name);
            setSystem(system);
          }


          static AddEmptySVAntennaModelPtr create(const std::string& name, const std::string& system)
          {
            return std::make_shared<AddEmptySVAntennaModel>(name, system);
          }

      static AddEmptySVAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<AddEmptySVAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Name"])
                  && parse_json<std::string>::is_valid(m_values["System"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Name", "System"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string name() const
          {
            return parse_json<std::string>::parse(m_values["Name"]);
          }

          void setName(const std::string& name)
          {
            m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(AddEmptySVAntennaModel);
  }
}

