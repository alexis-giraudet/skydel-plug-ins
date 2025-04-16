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
    /// Result of GetModulationTarget.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------------------------------------------------------------------------
    /// Type            string Target type can be "DTA-2116", "DTA-2115B", "File", "N310", "None", "NoneRT", "X300" or "Wavefront Controller".
    /// Path            string File path. Optional, use only if type is "File".
    /// Address         string Optional. IP Address if type is "N310" or "X300".
    /// ClockIsExternal bool   Indicate 10 MHz reference clock is external (true) or internal (false). Optional, use only if type is "DTA-2116", "DTA-2115B", "N310" or "X300".
    /// Id              string Unique identifier automatically set by simulator
    ///

    class GetModulationTargetResult;
    typedef std::shared_ptr<GetModulationTargetResult> GetModulationTargetResultPtr;
    
    
    class GetModulationTargetResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetModulationTargetResult";
      inline static const char* const Documentation = "Result of GetModulationTarget.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ ------------------------------------------------------------------------------------------------------------------------------------------------\n"      "Type            string Target type can be \"DTA-2116\", \"DTA-2115B\", \"File\", \"N310\", \"None\", \"NoneRT\", \"X300\" or \"Wavefront Controller\".\n"      "Path            string File path. Optional, use only if type is \"File\".\n"      "Address         string Optional. IP Address if type is \"N310\" or \"X300\".\n"      "ClockIsExternal bool   Indicate 10 MHz reference clock is external (true) or internal (false). Optional, use only if type is \"DTA-2116\", \"DTA-2115B\", \"N310\" or \"X300\".\n"      "Id              string Unique identifier automatically set by simulator";
      inline static const char* const TargetId = "";



          GetModulationTargetResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetModulationTargetResult(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setType(type);
            setPath(path);
            setAddress(address);
            setClockIsExternal(clockIsExternal);
            setId(id);
          }

          GetModulationTargetResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setType(type);
            setPath(path);
            setAddress(address);
            setClockIsExternal(clockIsExternal);
            setId(id);
          }



          static GetModulationTargetResultPtr create(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
          {
            return std::make_shared<GetModulationTargetResult>(type, path, address, clockIsExternal, id);
          }

          static GetModulationTargetResultPtr create(CommandBasePtr relatedCommand, const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id)
          {
            return std::make_shared<GetModulationTargetResult>(relatedCommand, type, path, address, clockIsExternal, id);
          }

      static GetModulationTargetResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetModulationTargetResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Type"])
                  && parse_json<std::string>::is_valid(m_values["Path"])
                  && parse_json<std::string>::is_valid(m_values["Address"])
                  && parse_json<bool>::is_valid(m_values["ClockIsExternal"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Type", "Path", "Address", "ClockIsExternal", "Id"}; 
        return names; 
      }
      


          std::string type() const
          {
            return parse_json<std::string>::parse(m_values["Type"]);
          }

          void setType(const std::string& type)
          {
            m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string path() const
          {
            return parse_json<std::string>::parse(m_values["Path"]);
          }

          void setPath(const std::string& path)
          {
            m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string address() const
          {
            return parse_json<std::string>::parse(m_values["Address"]);
          }

          void setAddress(const std::string& address)
          {
            m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool clockIsExternal() const
          {
            return parse_json<bool>::parse(m_values["ClockIsExternal"]);
          }

          void setClockIsExternal(bool clockIsExternal)
          {
            m_values.AddMember("ClockIsExternal", parse_json<bool>::format(clockIsExternal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetModulationTargetResult);
  }
}

