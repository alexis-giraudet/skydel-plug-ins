#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GLONASS satellite Ephemeris Health Flag Bn(ln)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------------
    /// SvId int  The satellite's SV ID 1..24
    ///

    class GetGlonassEphemerisHealthFlagForSV;
    typedef std::shared_ptr<GetGlonassEphemerisHealthFlagForSV> GetGlonassEphemerisHealthFlagForSVPtr;
    
    
    class GetGlonassEphemerisHealthFlagForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGlonassEphemerisHealthFlagForSV";
      inline static const char* const Documentation = "Get GLONASS satellite Ephemeris Health Flag Bn(ln)\n"      "\n"      "Name Type Description\n"      "---- ---- ---------------------------\n"      "SvId int  The satellite's SV ID 1..24";
      inline static const char* const TargetId = "";



          GetGlonassEphemerisHealthFlagForSV()
            : CommandBase(CmdName, TargetId)
          {}

          GetGlonassEphemerisHealthFlagForSV(int svId)
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
          }


          static GetGlonassEphemerisHealthFlagForSVPtr create(int svId)
          {
            return std::make_shared<GetGlonassEphemerisHealthFlagForSV>(svId);
          }

      static GetGlonassEphemerisHealthFlagForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGlonassEphemerisHealthFlagForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetGlonassEphemerisHealthFlagForSV);
  }
}

