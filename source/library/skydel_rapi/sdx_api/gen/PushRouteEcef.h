#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Push a route ecef node with speed. Must be called after BeginRouteDefinition and before EndRouteDefinition.
    ///
    /// Name  Type   Description
    /// ----- ------ --------------------------------------
    /// Speed double Node speed in meters per second
    /// X     double X distance from earth-center in meters
    /// Y     double Y distance from earth-center in meters
    /// Z     double Z distance from earth-center in meters
    ///

    class PushRouteEcef;
    typedef std::shared_ptr<PushRouteEcef> PushRouteEcefPtr;
    
    
    class PushRouteEcef : public CommandBase
    {
    public:
      inline static const char* const CmdName = "PushRouteEcef";
      inline static const char* const Documentation = "Push a route ecef node with speed. Must be called after BeginRouteDefinition and before EndRouteDefinition.\n"      "\n"      "Name  Type   Description\n"      "----- ------ --------------------------------------\n"      "Speed double Node speed in meters per second\n"      "X     double X distance from earth-center in meters\n"      "Y     double Y distance from earth-center in meters\n"      "Z     double Z distance from earth-center in meters";
      inline static const char* const TargetId = "";



          PushRouteEcef()
            : CommandBase(CmdName, TargetId)
          {}

          PushRouteEcef(double speed, double x, double y, double z)
            : CommandBase(CmdName, TargetId)
          {

            setSpeed(speed);
            setX(x);
            setY(y);
            setZ(z);
          }


          static PushRouteEcefPtr create(double speed, double x, double y, double z)
          {
            return std::make_shared<PushRouteEcef>(speed, x, y, z);
          }

      static PushRouteEcefPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<PushRouteEcef>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["Speed"])
                  && parse_json<double>::is_valid(m_values["X"])
                  && parse_json<double>::is_valid(m_values["Y"])
                  && parse_json<double>::is_valid(m_values["Z"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Speed", "X", "Y", "Z"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          double speed() const
          {
            return parse_json<double>::parse(m_values["Speed"]);
          }

          void setSpeed(double speed)
          {
            m_values.AddMember("Speed", parse_json<double>::format(speed, m_values.GetAllocator()), m_values.GetAllocator());
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

    };
    REGISTER_COMMAND_TO_FACTORY(PushRouteEcef);
  }
}

