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
    /// Set antenna offset and orientation relative to body frame.
    /// The origin of the body frame follows the transmitter trajectory.
    /// When the body yaw/pitch/roll are zeros, the body X-axis is pointing north
    ///                          Y-axis is pointing east
    ///                          Z-axis is pointing down
    /// The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and
    /// the Roll is rotating arond the X-axis of the body frame.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// X     double Antenna X offset in the body frame
    /// Y     double Antenna Y offset in the body frame
    /// Z     double Antenna Z offset in the body frame
    /// Yaw   double Antenna Yaw offset in the body frame
    /// Pitch double Antenna Pitch offset in the body frame
    /// Roll  double Antenna Roll offset in the body frame
    /// Id    string Transmitter unique identifier.
    ///

    class SetIntTxAntennaOffset;
    typedef std::shared_ptr<SetIntTxAntennaOffset> SetIntTxAntennaOffsetPtr;
    
    
    class SetIntTxAntennaOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxAntennaOffset";
      inline static const char* const Documentation = "Set antenna offset and orientation relative to body frame.\n"      "The origin of the body frame follows the transmitter trajectory.\n"      "When the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n"      "                         Y-axis is pointing east\n"      "                         Z-axis is pointing down\n"      "The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\n"      "the Roll is rotating arond the X-axis of the body frame.\n"      "\n"      "Name  Type   Description\n"      "----- ------ --------------------------------------\n"      "X     double Antenna X offset in the body frame\n"      "Y     double Antenna Y offset in the body frame\n"      "Z     double Antenna Z offset in the body frame\n"      "Yaw   double Antenna Yaw offset in the body frame\n"      "Pitch double Antenna Pitch offset in the body frame\n"      "Roll  double Antenna Roll offset in the body frame\n"      "Id    string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxAntennaOffset()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxAntennaOffset(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setX(x);
            setY(y);
            setZ(z);
            setYaw(yaw);
            setPitch(pitch);
            setRoll(roll);
            setId(id);
          }


          static SetIntTxAntennaOffsetPtr create(double x, double y, double z, double yaw, double pitch, double roll, const std::string& id)
          {
            return std::make_shared<SetIntTxAntennaOffset>(x, y, z, yaw, pitch, roll, id);
          }

      static SetIntTxAntennaOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxAntennaOffset>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxAntennaOffset);
  }
}

