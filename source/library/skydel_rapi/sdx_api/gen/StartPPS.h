#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Start the simulation at the given PPS count.
    ///
    /// Name Type Description
    /// ---- ---- -------------------------------------------------------------
    /// Msec int  The number of ms after PPS to wait before starting simulation
    ///

    class StartPPS;
    typedef std::shared_ptr<StartPPS> StartPPSPtr;
    
    
    class StartPPS : public CommandBase
    {
    public:
      inline static const char* const CmdName = "StartPPS";
      inline static const char* const Documentation = "Start the simulation at the given PPS count.\n"      "\n"      "Name Type Description\n"      "---- ---- -------------------------------------------------------------\n"      "Msec int  The number of ms after PPS to wait before starting simulation";
      inline static const char* const TargetId = "";



          StartPPS()
            : CommandBase(CmdName, TargetId)
          {}

          StartPPS(int msec)
            : CommandBase(CmdName, TargetId)
          {

            setMsec(msec);
          }


          static StartPPSPtr create(int msec)
          {
            return std::make_shared<StartPPS>(msec);
          }

      static StartPPSPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<StartPPS>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Msec"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Msec"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
          }


          int msec() const
          {
            return parse_json<int>::parse(m_values["Msec"]);
          }

          void setMsec(int msec)
          {
            m_values.AddMember("Msec", parse_json<int>::format(msec, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(StartPPS);
  }
}

