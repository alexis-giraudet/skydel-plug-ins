#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoFnavSatelliteK.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// Prn  int  Satellite PRN number
    /// K    int  Satellite K PRN number.
    ///

    class GetGalileoFnavSatelliteKResult;
    typedef std::shared_ptr<GetGalileoFnavSatelliteKResult> GetGalileoFnavSatelliteKResultPtr;
    
    
    class GetGalileoFnavSatelliteKResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGalileoFnavSatelliteKResult";
      inline static const char* const Documentation = "Result of GetGalileoFnavSatelliteK.\n"      "\n"      "Name Type Description\n"      "---- ---- -----------------------\n"      "Prn  int  Satellite PRN number\n"      "K    int  Satellite K PRN number.";
      inline static const char* const TargetId = "";



          GetGalileoFnavSatelliteKResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGalileoFnavSatelliteKResult(int prn, int k)
            : CommandResult(CmdName, TargetId)
          {

            setPrn(prn);
            setK(k);
          }

          GetGalileoFnavSatelliteKResult(CommandBasePtr relatedCommand, int prn, int k)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setPrn(prn);
            setK(k);
          }



          static GetGalileoFnavSatelliteKResultPtr create(int prn, int k)
          {
            return std::make_shared<GetGalileoFnavSatelliteKResult>(prn, k);
          }

          static GetGalileoFnavSatelliteKResultPtr create(CommandBasePtr relatedCommand, int prn, int k)
          {
            return std::make_shared<GetGalileoFnavSatelliteKResult>(relatedCommand, prn, k);
          }

      static GetGalileoFnavSatelliteKResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGalileoFnavSatelliteKResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetGalileoFnavSatelliteKResult);
  }
}

