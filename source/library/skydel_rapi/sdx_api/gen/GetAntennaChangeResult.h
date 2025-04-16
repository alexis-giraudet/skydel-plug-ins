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
    /// Result of GetAntennaChange.
    ///
    /// Name      Type   Description
    /// --------- ------ --------------------------------------------------
    /// StartTime double Elapsed time in seconds since start of simulation.
    /// Antenna   string Antenna model name
    /// Id        string Unique identifier of the event
    ///

    class GetAntennaChangeResult;
    typedef std::shared_ptr<GetAntennaChangeResult> GetAntennaChangeResultPtr;
    
    
    class GetAntennaChangeResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetAntennaChangeResult";
      inline static const char* const Documentation = "Result of GetAntennaChange.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ --------------------------------------------------\n"      "StartTime double Elapsed time in seconds since start of simulation.\n"      "Antenna   string Antenna model name\n"      "Id        string Unique identifier of the event";
      inline static const char* const TargetId = "";



          GetAntennaChangeResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetAntennaChangeResult(double startTime, const std::string& antenna, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setStartTime(startTime);
            setAntenna(antenna);
            setId(id);
          }

          GetAntennaChangeResult(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setStartTime(startTime);
            setAntenna(antenna);
            setId(id);
          }



          static GetAntennaChangeResultPtr create(double startTime, const std::string& antenna, const std::string& id)
          {
            return std::make_shared<GetAntennaChangeResult>(startTime, antenna, id);
          }

          static GetAntennaChangeResultPtr create(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id)
          {
            return std::make_shared<GetAntennaChangeResult>(relatedCommand, startTime, antenna, id);
          }

      static GetAntennaChangeResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAntennaChangeResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["StartTime"])
                  && parse_json<std::string>::is_valid(m_values["Antenna"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"StartTime", "Antenna", "Id"}; 
        return names; 
      }
      


          double startTime() const
          {
            return parse_json<double>::parse(m_values["StartTime"]);
          }

          void setStartTime(double startTime)
          {
            m_values.AddMember("StartTime", parse_json<double>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string antenna() const
          {
            return parse_json<std::string>::parse(m_values["Antenna"]);
          }

          void setAntenna(const std::string& antenna)
          {
            m_values.AddMember("Antenna", parse_json<std::string>::format(antenna, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetAntennaChangeResult);
  }
}

