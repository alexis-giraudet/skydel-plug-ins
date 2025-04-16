#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoBdgimAlpha.
    ///
    /// Name  Type   Description
    /// ----- ------ ------------------------
    /// Index int    Coefficient index [1..9]
    /// Val   double Coefficient value
    ///

    class GetIonoBdgimAlphaResult;
    typedef std::shared_ptr<GetIonoBdgimAlphaResult> GetIonoBdgimAlphaResultPtr;
    
    
    class GetIonoBdgimAlphaResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIonoBdgimAlphaResult";
      inline static const char* const Documentation = "Result of GetIonoBdgimAlpha.\n"      "\n"      "Name  Type   Description\n"      "----- ------ ------------------------\n"      "Index int    Coefficient index [1..9]\n"      "Val   double Coefficient value";
      inline static const char* const TargetId = "";



          GetIonoBdgimAlphaResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIonoBdgimAlphaResult(int index, double val)
            : CommandResult(CmdName, TargetId)
          {

            setIndex(index);
            setVal(val);
          }

          GetIonoBdgimAlphaResult(CommandBasePtr relatedCommand, int index, double val)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIndex(index);
            setVal(val);
          }



          static GetIonoBdgimAlphaResultPtr create(int index, double val)
          {
            return std::make_shared<GetIonoBdgimAlphaResult>(index, val);
          }

          static GetIonoBdgimAlphaResultPtr create(CommandBasePtr relatedCommand, int index, double val)
          {
            return std::make_shared<GetIonoBdgimAlphaResult>(relatedCommand, index, val);
          }

      static GetIonoBdgimAlphaResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoBdgimAlphaResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Index"])
                  && parse_json<double>::is_valid(m_values["Val"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Index", "Val"}; 
        return names; 
      }
      


          int index() const
          {
            return parse_json<int>::parse(m_values["Index"]);
          }

          void setIndex(int index)
          {
            m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double val() const
          {
            return parse_json<double>::parse(m_values["Val"]);
          }

          void setVal(double val)
          {
            m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIonoBdgimAlphaResult);
  }
}

