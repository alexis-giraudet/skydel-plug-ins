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
    /// Copy a space vehicle antenna model.
    ///
    /// Name     Type   Description
    /// -------- ------ --------------------------------------------------------------------------
    /// Name     string Reference space vehicle antenna model name
    /// CopyName string Copy space vehicle antenna model name
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class CopySVAntennaModel;
    typedef std::shared_ptr<CopySVAntennaModel> CopySVAntennaModelPtr;
    
    
    class CopySVAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "CopySVAntennaModel";
      inline static const char* const Documentation = "Copy a space vehicle antenna model.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ --------------------------------------------------------------------------\n"      "Name     string Reference space vehicle antenna model name\n"      "CopyName string Copy space vehicle antenna model name\n"      "System   string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
      inline static const char* const TargetId = "";



          CopySVAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          CopySVAntennaModel(const std::string& name, const std::string& copyName, const std::string& system)
            : CommandBase(CmdName, TargetId)
          {

            setName(name);
            setCopyName(copyName);
            setSystem(system);
          }


          static CopySVAntennaModelPtr create(const std::string& name, const std::string& copyName, const std::string& system)
          {
            return std::make_shared<CopySVAntennaModel>(name, copyName, system);
          }

      static CopySVAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<CopySVAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Name"])
                  && parse_json<std::string>::is_valid(m_values["CopyName"])
                  && parse_json<std::string>::is_valid(m_values["System"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Name", "CopyName", "System"}; 
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



          std::string copyName() const
          {
            return parse_json<std::string>::parse(m_values["CopyName"]);
          }

          void setCopyName(const std::string& copyName)
          {
            m_values.AddMember("CopyName", parse_json<std::string>::format(copyName, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(CopySVAntennaModel);
  }
}

