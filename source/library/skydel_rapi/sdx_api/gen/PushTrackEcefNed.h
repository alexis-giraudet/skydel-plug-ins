#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a track ecef and ned attitude node. Must be called after BeginTrackDefinition and before EndTrackDefinition.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// Time  int    Node Timestamp in miliseconds
    /// X     double X distance from earth-center in meters
    /// Y     double Y distance from earth-center in meters
    /// Z     double Z distance from earth-center in meters
    /// Yaw   double Yaw in radians
    /// Pitch double Pitch in radians
    /// Roll  double Roll in radians
    ///

    class PushTrackEcefNed;
    typedef std::shared_ptr<PushTrackEcefNed> PushTrackEcefNedPtr;
    
    
    class PushTrackEcefNed : public CommandBase
    {
    public:
      inline static const char* const CmdName = "PushTrackEcefNed";
      inline static const char* const Documentation = "Push a track ecef and ned attitude node. Must be called after BeginTrackDefinition and before EndTrackDefinition.\n"      "\n"      "Name  Type   Description\n"      "----- ------ --------------------------------------\n"      "Time  int    Node Timestamp in miliseconds\n"      "X     double X distance from earth-center in meters\n"      "Y     double Y distance from earth-center in meters\n"      "Z     double Z distance from earth-center in meters\n"      "Yaw   double Yaw in radians\n"      "Pitch double Pitch in radians\n"      "Roll  double Roll in radians";
      inline static const char* const TargetId = "";



          PushTrackEcefNed()
            : CommandBase(CmdName, TargetId)
          {}

          PushTrackEcefNed(int time, double x, double y, double z, double yaw, double pitch, double roll)
            : CommandBase(CmdName, TargetId)
          {

            setTime(time);
            setX(x);
            setY(y);
            setZ(z);
            setYaw(yaw);
            setPitch(pitch);
            setRoll(roll);
          }


          static PushTrackEcefNedPtr create(int time, double x, double y, double z, double yaw, double pitch, double roll)
          {
            return std::make_shared<PushTrackEcefNed>(time, x, y, z, yaw, pitch, roll);
          }

      static PushTrackEcefNedPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<PushTrackEcefNed>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Time"])
                  && parse_json<double>::is_valid(m_values["X"])
                  && parse_json<double>::is_valid(m_values["Y"])
                  && parse_json<double>::is_valid(m_values["Z"])
                  && parse_json<double>::is_valid(m_values["Yaw"])
                  && parse_json<double>::is_valid(m_values["Pitch"])
                  && parse_json<double>::is_valid(m_values["Roll"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Yaw", "Pitch", "Roll"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int time() const
          {
            return parse_json<int>::parse(m_values["Time"]);
          }

          void setTime(int time)
          {
            m_values.AddMember("Time", parse_json<int>::format(time, m_values.GetAllocator()), m_values.GetAllocator());
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

    };
    REGISTER_COMMAND_TO_FACTORY(PushTrackEcefNed);
  }
}

