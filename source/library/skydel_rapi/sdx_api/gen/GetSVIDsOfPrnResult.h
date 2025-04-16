#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVIDsOfPrn.
    ///
    /// Name     Type      Description
    /// -------- --------- ----------------------------------------------------------------------
    /// Signal   string    Signal key - see GetSVIDsOfPrn command description for possible values
    /// Prn      int       Satellite PRN number
    /// SvIdList array int A list containing all SV ID of a specific signal
    ///

    class GetSVIDsOfPrnResult;
    typedef std::shared_ptr<GetSVIDsOfPrnResult> GetSVIDsOfPrnResultPtr;
    
    
    class GetSVIDsOfPrnResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSVIDsOfPrnResult";
      inline static const char* const Documentation = "Result of GetSVIDsOfPrn.\n"      "\n"      "Name     Type      Description\n"      "-------- --------- ----------------------------------------------------------------------\n"      "Signal   string    Signal key - see GetSVIDsOfPrn command description for possible values\n"      "Prn      int       Satellite PRN number\n"      "SvIdList array int A list containing all SV ID of a specific signal";
      inline static const char* const TargetId = "";



          GetSVIDsOfPrnResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSVIDsOfPrnResult(const std::string& signal, int prn, const std::vector<int>& svIdList)
            : CommandResult(CmdName, TargetId)
          {

            setSignal(signal);
            setPrn(prn);
            setSvIdList(svIdList);
          }

          GetSVIDsOfPrnResult(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSignal(signal);
            setPrn(prn);
            setSvIdList(svIdList);
          }



          static GetSVIDsOfPrnResultPtr create(const std::string& signal, int prn, const std::vector<int>& svIdList)
          {
            return std::make_shared<GetSVIDsOfPrnResult>(signal, prn, svIdList);
          }

          static GetSVIDsOfPrnResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, int prn, const std::vector<int>& svIdList)
          {
            return std::make_shared<GetSVIDsOfPrnResult>(relatedCommand, signal, prn, svIdList);
          }

      static GetSVIDsOfPrnResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSVIDsOfPrnResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Signal"])
                  && parse_json<int>::is_valid(m_values["Prn"])
                  && parse_json<std::vector<int>>::is_valid(m_values["SvIdList"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Signal", "Prn", "SvIdList"}; 
        return names; 
      }
      


          std::string signal() const
          {
            return parse_json<std::string>::parse(m_values["Signal"]);
          }

          void setSignal(const std::string& signal)
          {
            m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int prn() const
          {
            return parse_json<int>::parse(m_values["Prn"]);
          }

          void setPrn(int prn)
          {
            m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<int> svIdList() const
          {
            return parse_json<std::vector<int>>::parse(m_values["SvIdList"]);
          }

          void setSvIdList(const std::vector<int>& svIdList)
          {
            m_values.AddMember("SvIdList", parse_json<std::vector<int>>::format(svIdList, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSVIDsOfPrnResult);
  }
}

