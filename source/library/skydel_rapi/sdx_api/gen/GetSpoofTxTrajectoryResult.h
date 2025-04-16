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
    /// Result of GetSpoofTxTrajectory.
    ///
    /// Name           Type   Description
    /// -------------- ------ ---------------------------------------------------
    /// TrajectoryType string Type of the trajectory of the spoofer transmitters.
    /// Id             string Transmitter unique identifier.
    ///

    class GetSpoofTxTrajectoryResult;
    typedef std::shared_ptr<GetSpoofTxTrajectoryResult> GetSpoofTxTrajectoryResultPtr;
    
    
    class GetSpoofTxTrajectoryResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSpoofTxTrajectoryResult";
      inline static const char* const Documentation = "Result of GetSpoofTxTrajectory.\n"      "\n"      "Name           Type   Description\n"      "-------------- ------ ---------------------------------------------------\n"      "TrajectoryType string Type of the trajectory of the spoofer transmitters.\n"      "Id             string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetSpoofTxTrajectoryResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSpoofTxTrajectoryResult(const std::string& trajectoryType, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setTrajectoryType(trajectoryType);
            setId(id);
          }

          GetSpoofTxTrajectoryResult(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setTrajectoryType(trajectoryType);
            setId(id);
          }



          static GetSpoofTxTrajectoryResultPtr create(const std::string& trajectoryType, const std::string& id)
          {
            return std::make_shared<GetSpoofTxTrajectoryResult>(trajectoryType, id);
          }

          static GetSpoofTxTrajectoryResultPtr create(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id)
          {
            return std::make_shared<GetSpoofTxTrajectoryResult>(relatedCommand, trajectoryType, id);
          }

      static GetSpoofTxTrajectoryResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSpoofTxTrajectoryResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["TrajectoryType"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"TrajectoryType", "Id"}; 
        return names; 
      }
      


          std::string trajectoryType() const
          {
            return parse_json<std::string>::parse(m_values["TrajectoryType"]);
          }

          void setTrajectoryType(const std::string& trajectoryType)
          {
            m_values.AddMember("TrajectoryType", parse_json<std::string>::format(trajectoryType, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetSpoofTxTrajectoryResult);
  }
}

