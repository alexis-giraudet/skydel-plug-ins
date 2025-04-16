#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// Prn  int  Satellite PRN number
    /// K    int  Satellite K PRN number.
    ///

    class SetGalileoFnavSatelliteK;
    typedef std::shared_ptr<SetGalileoFnavSatelliteK> SetGalileoFnavSatelliteKPtr;
    
    
    class SetGalileoFnavSatelliteK : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetGalileoFnavSatelliteK";
      inline static const char* const Documentation = "Set the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).\n"      "\n"      "Name Type Description\n"      "---- ---- -----------------------\n"      "Prn  int  Satellite PRN number\n"      "K    int  Satellite K PRN number.";
      inline static const char* const TargetId = "";



          SetGalileoFnavSatelliteK()
            : CommandBase(CmdName, TargetId)
          {}

          SetGalileoFnavSatelliteK(int prn, int k)
            : CommandBase(CmdName, TargetId)
          {

            setPrn(prn);
            setK(k);
          }


          static SetGalileoFnavSatelliteKPtr create(int prn, int k)
          {
            return std::make_shared<SetGalileoFnavSatelliteK>(prn, k);
          }

      static SetGalileoFnavSatelliteKPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetGalileoFnavSatelliteK>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Prn"])
                  && parse_json<int>::is_valid(m_values["K"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Prn", "K"}; 
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



          int k() const
          {
            return parse_json<int>::parse(m_values["K"]);
          }

          void setK(int k)
          {
            m_values.AddMember("K", parse_json<int>::format(k, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetGalileoFnavSatelliteK);
  }
}

