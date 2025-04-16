#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the GPS ionospheric Beta coefficient
    /// Beta 0 is in seconds
    /// Beta 1 is in seconds/semicircle
    /// Beta 2 is in seconds/semicircle^2
    /// Beta 3 is in seconds/semicircle^3
    ///
    /// Name  Type Description
    /// ----- ---- ------------------------
    /// Index int  Coefficient index [0..3]
    ///

    class GetIonoBeta;
    typedef std::shared_ptr<GetIonoBeta> GetIonoBetaPtr;
    
    
    class GetIonoBeta : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIonoBeta";
      inline static const char* const Documentation = "Get the GPS ionospheric Beta coefficient\n"      "Beta 0 is in seconds\n"      "Beta 1 is in seconds/semicircle\n"      "Beta 2 is in seconds/semicircle^2\n"      "Beta 3 is in seconds/semicircle^3\n"      "\n"      "Name  Type Description\n"      "----- ---- ------------------------\n"      "Index int  Coefficient index [0..3]";
      inline static const char* const TargetId = "";



          GetIonoBeta()
            : CommandBase(CmdName, TargetId)
          {}

          GetIonoBeta(int index)
            : CommandBase(CmdName, TargetId)
          {

            setIndex(index);
          }


          static GetIonoBetaPtr create(int index)
          {
            return std::make_shared<GetIonoBeta>(index);
          }

      static GetIonoBetaPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoBeta>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Index"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Index"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int index() const
          {
            return parse_json<int>::parse(m_values["Index"]);
          }

          void setIndex(int index)
          {
            m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIonoBeta);
  }
}

