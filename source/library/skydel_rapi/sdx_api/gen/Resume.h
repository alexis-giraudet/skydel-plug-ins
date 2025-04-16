#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Resume vehicle motion during simulation.
    ///
    /// 
    ///

    class Resume;
    typedef std::shared_ptr<Resume> ResumePtr;
    
    
    class Resume : public CommandBase
    {
    public:
      inline static const char* const CmdName = "Resume";
      inline static const char* const Documentation = "Resume vehicle motion during simulation.";
      inline static const char* const TargetId = "";



          Resume()
            : CommandBase(CmdName, TargetId)
          {

          }


          static ResumePtr create()
          {
            return std::make_shared<Resume>();
          }

      static ResumePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<Resume>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(Resume);
  }
}

