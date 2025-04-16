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
    /// Tells if the satellite is fixed (True) or not fixed (false).
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------
    /// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// SvId   int    The satellite's SV ID.
    ///

    class IsSatMotionFixed;
    typedef std::shared_ptr<IsSatMotionFixed> IsSatMotionFixedPtr;
    
    
    class IsSatMotionFixed : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSatMotionFixed";
      inline static const char* const Documentation = "Tells if the satellite is fixed (True) or not fixed (false).\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------\n"      "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "SvId   int    The satellite's SV ID.";
      inline static const char* const TargetId = "";



          IsSatMotionFixed()
            : CommandBase(CmdName, TargetId)
          {}

          IsSatMotionFixed(const std::string& system, int svId)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setSvId(svId);
          }


          static IsSatMotionFixedPtr create(const std::string& system, int svId)
          {
            return std::make_shared<IsSatMotionFixed>(system, svId);
          }

      static IsSatMotionFixedPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSatMotionFixed>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "SvId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsSatMotionFixed);
  }
}

