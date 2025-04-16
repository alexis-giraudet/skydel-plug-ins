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
    /// Result of GetSpoofTxFixEcef.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------------
    /// X     double ECEF X (m)
    /// Y     double ECEF Y (m)
    /// Z     double ECEF Z (m)
    /// Yaw   double Yaw (rad)
    /// Pitch double Pitch (rad)
    /// Roll  double Roll (rad)
    /// Id    string Transmitter unique identifier.
    ///

    class GetSpoofTxFixEcefResult;
    typedef std::shared_ptr<GetSpoofTxFixEcefResult> GetSpoofTxFixEcefResultPtr;
    
    
    class GetSpoofTxFixEcefResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSpoofTxFixEcefResult";
      inline static const char* const Documentation = "Result of GetSpoofTxFixEcef.\n"      "\n"      "Name  Type   Description\n"      "----- ------ ------------------------------\n"      "X     double ECEF X (m)\n"      "Y     double ECEF Y (m)\n"      "Z     double ECEF Z (m)\n"      "Yaw   double Yaw (rad)\n"      "Pitch double Pitch (rad)\n"      "Roll  double Roll (rad)\n"      "Id    string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetSpoofTxFixEcefResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSpoofTxFixEcefResult(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setX(x);
            setY(y);
            setZ(z);
            setYaw(yaw);
            setPitch(pitch);
            setRoll(roll);
            setId(id);
          }

          GetSpoofTxFixEcefResult(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setX(x);
            setY(y);
            setZ(z);
            setYaw(yaw);
            setPitch(pitch);
            setRoll(roll);
            setId(id);
          }



          static GetSpoofTxFixEcefResultPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
          {
            return std::make_shared<GetSpoofTxFixEcefResult>(x, y, z, yaw, pitch, roll, id);
          }

          static GetSpoofTxFixEcefResultPtr create(CommandBasePtr relatedCommand, double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
          {
            return std::make_shared<GetSpoofTxFixEcefResult>(relatedCommand, x, y, z, yaw, pitch, roll, id);
          }

      static GetSpoofTxFixEcefResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSpoofTxFixEcefResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["X"])
                  && parse_json<double>::is_valid(m_values["Y"])
                  && parse_json<double>::is_valid(m_values["Z"])
                  && parse_json<double>::is_valid(m_values["Yaw"])
                  && parse_json<double>::is_valid(m_values["Pitch"])
                  && parse_json<double>::is_valid(m_values["Roll"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"X", "Y", "Z", "Yaw", "Pitch", "Roll", "Id"}; 
        return names; 
      }
      


          double x() const
          {
            return parse_json<double>::parse(m_values["X"]);
          }

          void setX(double x)
          {
            m_values.AddMember("X", parse_json<double>::format(x, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double y() const
          {
            return parse_json<double>::parse(m_values["Y"]);
          }

          void setY(double y)
          {
            m_values.AddMember("Y", parse_json<double>::format(y, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double z() const
          {
            return parse_json<double>::parse(m_values["Z"]);
          }

          void setZ(double z)
          {
            m_values.AddMember("Z", parse_json<double>::format(z, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double yaw() const
          {
            return parse_json<double>::parse(m_values["Yaw"]);
          }

          void setYaw(double yaw)
          {
            m_values.AddMember("Yaw", parse_json<double>::format(yaw, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double pitch() const
          {
            return parse_json<double>::parse(m_values["Pitch"]);
          }

          void setPitch(double pitch)
          {
            m_values.AddMember("Pitch", parse_json<double>::format(pitch, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double roll() const
          {
            return parse_json<double>::parse(m_values["Roll"]);
          }

          void setRoll(double roll)
          {
            m_values.AddMember("Roll", parse_json<double>::format(roll, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetSpoofTxFixEcefResult);
  }
}

