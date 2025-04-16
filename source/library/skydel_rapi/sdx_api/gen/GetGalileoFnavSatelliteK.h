#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).
    ///
    /// Name Type Description
    /// ---- ---- --------------------
    /// Prn  int  Satellite PRN number
    ///

    class GetGalileoFnavSatelliteK;
    typedef std::shared_ptr<GetGalileoFnavSatelliteK> GetGalileoFnavSatelliteKPtr;
    
    
    class GetGalileoFnavSatelliteK : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGalileoFnavSatelliteK";
      inline static const char* const Documentation = "Get the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).\n"      "\n"      "Name Type Description\n"      "---- ---- --------------------\n"      "Prn  int  Satellite PRN number";
      inline static const char* const TargetId = "";



          GetGalileoFnavSatelliteK()
            : CommandBase(CmdName, TargetId)
          {}

          GetGalileoFnavSatelliteK(int prn)
            : CommandBase(CmdName, TargetId)
          {

            setPrn(prn);
          }


          static GetGalileoFnavSatelliteKPtr create(int prn)
          {
            return std::make_shared<GetGalileoFnavSatelliteK>(prn);
          }

      static GetGalileoFnavSatelliteKPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGalileoFnavSatelliteK>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Prn"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Prn"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int prn() const
          {
            return parse_json<int>::parse(m_values["Prn"]);
          }

          void setPrn(int prn)
          {
            m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGalileoFnavSatelliteK);
  }
}

