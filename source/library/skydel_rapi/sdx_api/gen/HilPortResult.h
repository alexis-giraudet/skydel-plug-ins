#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetHilPort.
    ///
    /// Name Type Description
    /// ---- ---- ---------------
    /// Port int  Hil Server Port
    ///

    class HilPortResult;
    typedef std::shared_ptr<HilPortResult> HilPortResultPtr;
    
    
    class HilPortResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "HilPortResult";
      inline static const char* const Documentation = "Result of GetHilPort.\n"      "\n"      "Name Type Description\n"      "---- ---- ---------------\n"      "Port int  Hil Server Port";
      inline static const char* const TargetId = "";



          HilPortResult()
            : CommandResult(CmdName, TargetId)
          {}

          HilPortResult(int port)
            : CommandResult(CmdName, TargetId)
          {

            setPort(port);
          }

          HilPortResult(CommandBasePtr relatedCommand, int port)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setPort(port);
          }



          static HilPortResultPtr create(int port)
          {
            return std::make_shared<HilPortResult>(port);
          }

          static HilPortResultPtr create(CommandBasePtr relatedCommand, int port)
          {
            return std::make_shared<HilPortResult>(relatedCommand, port);
          }

      static HilPortResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<HilPortResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Port"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Port"}; 
        return names; 
      }
      


          int port() const
          {
            return parse_json<int>::parse(m_values["Port"]);
          }

          void setPort(int port)
          {
            m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(HilPortResult);
  }
}

