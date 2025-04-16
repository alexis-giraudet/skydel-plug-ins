#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get if spectrums are show/hide.
    ///
    /// 
    ///

    class IsSpectrumVisible;
    typedef std::shared_ptr<IsSpectrumVisible> IsSpectrumVisiblePtr;
    
    
    class IsSpectrumVisible : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSpectrumVisible";
      inline static const char* const Documentation = "Get if spectrums are show/hide.";
      inline static const char* const TargetId = "";



          IsSpectrumVisible()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsSpectrumVisiblePtr create()
          {
            return std::make_shared<IsSpectrumVisible>();
          }

      static IsSpectrumVisiblePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSpectrumVisible>(ptr);
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
            return EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(IsSpectrumVisible);
  }
}

