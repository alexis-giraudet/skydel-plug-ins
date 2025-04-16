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
    /// Push an spoofer transmitter track ecef node. Must be called after BeginSpoofTxTrackDefinition and before EndSpoofTxTrackDefinition.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------------------
    /// Time int    Node Timestamp in miliseconds.
    /// X    double X distance from earth-center in meters.
    /// Y    double Y distance from earth-center in meters.
    /// Z    double Z distance from earth-center in meters.
    /// Id   string Transmitter unique identifier.
    ///

    class PushSpoofTxTrackEcef;
    typedef std::shared_ptr<PushSpoofTxTrackEcef> PushSpoofTxTrackEcefPtr;
    
    
    class PushSpoofTxTrackEcef : public CommandBase
    {
    public:
      inline static const char* const CmdName = "PushSpoofTxTrackEcef";
      inline static const char* const Documentation = "Push an spoofer transmitter track ecef node. Must be called after BeginSpoofTxTrackDefinition and before EndSpoofTxTrackDefinition.\n"      "\n"      "Name Type   Description\n"      "---- ------ ---------------------------------------\n"      "Time int    Node Timestamp in miliseconds.\n"      "X    double X distance from earth-center in meters.\n"      "Y    double Y distance from earth-center in meters.\n"      "Z    double Z distance from earth-center in meters.\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          PushSpoofTxTrackEcef()
            : CommandBase(CmdName, TargetId)
          {}

          PushSpoofTxTrackEcef(int time, double x, double y, double z, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setTime(time);
            setX(x);
            setY(y);
            setZ(z);
            setId(id);
          }


          static PushSpoofTxTrackEcefPtr create(int time, double x, double y, double z, const std::string& id)
          {
            return std::make_shared<PushSpoofTxTrackEcef>(time, x, y, z, id);
          }

      static PushSpoofTxTrackEcefPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<PushSpoofTxTrackEcef>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Time"])
                  && parse_json<double>::is_valid(m_values["X"])
                  && parse_json<double>::is_valid(m_values["Y"])
                  && parse_json<double>::is_valid(m_values["Z"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Time", "X", "Y", "Z", "Id"}; 
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



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(PushSpoofTxTrackEcef);
  }
}

